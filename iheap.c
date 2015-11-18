/*************************************************************************
	> File Name: iheap.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月15日 星期日 16时29分20秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int factorial(int n){
    if(n == -1){
        return 0;
    }
    int i;
    int result = 1;

    for(i = 0;i < n;i++){
        result *= 2;
    }

    return result;
}

int mylog(int n){
    int i;
    int result = 0;

    for(i = 0;factorial(i) <= n;i++){
        result += factorial(i);
    }

    return i - 1;
}

/*定义结构体*/
struct linkNode{
    int data;
    struct linkNode *nextPtr;
};

typedef struct linkNode LinkNode;
typedef LinkNode *LinkNodePtr;
typedef LinkNodePtr Position;
typedef LinkNodePtr List;

Position Last;

struct heapNode{
	int currentSize;
	List L;
};

typedef struct heapNode HeapNode;
typedef HeapNode *HeapNodePtr;

/*函数声明*/
HeapNodePtr InitializeHeap();
List MakeEmpty(List L);
void Insert(int X,HeapNodePtr H);
void Destroy(HeapNodePtr H);
int FindMin(HeapNodePtr H);
int DeleteMin(HeapNodePtr H);
void Delete(HeapNodePtr H,int n);

void instructions(void);
void printList(List L);
void printheap(HeapNodePtr H);

int FindNum(int X,List L);
void Change(int X,List L,int n);
int ReturnNum(int X,List L);
LinkNodePtr FindPre(HeapNodePtr H,Position P);

/*主函数*/
int main(void){
	HeapNodePtr H;
    int choice;
    int item;
    
    H = InitializeHeap();
    instructions();
    printf("\nyour choice:\n");
    if(!scanf("%d",&choice)){
        printf("input error\n");
        exit(1);
    }

    while(choice != 5){
        switch(choice){
            case 1:
                printf("\nenter a number:\n");
                if(scanf("%d",&item)){
                    Insert(item,H);
                }else{
                    printf("input error\n");
                    exit(1);
                }
                break;
            case 2:
                printf("Min = %d\n",FindMin(H));
                printf("do you want to delete minelement(0-YES)\n");
                if(scanf("%d",&item)){  
                    if(item == 0)
                        DeleteMin(H);
                }else{
                    printf("input error\n");
                    exit(1);
                }
                break;
            case 4:
                printf("currentSize = %d\n",H->currentSize);
                printList(H->L);
                printf("\n");
                printheap(H);
                break;
            case 3:
                printf("\nenter a number:\n");
                if(scanf("%d",&item)){  
                    Delete(H,item);
                }else{
                    printf("input error\n");
                    exit(1);
                }
                break;
            default:
                printf("\nInvalid choice\n");
        }
        printf("\n");
        instructions();
        printf("\nyour choice:\n");
        if(!scanf("%d",&choice)){
            printf("input error\n");
            exit(1);
        }
    }
    Destroy(H);
    printf("run to end\n");

	return 0;
}

/*输入链表中的数据返回第几个数*/
int ReturnNum(int X,List L){
    Position P;
    int i;

    P = L->nextPtr;
    for(i = 1;P->data != X;i++){
        P = P->nextPtr;
    }

    return i;
}

/*instructions*/
void instructions(void){
    printf("Enter your choice\n"
        "1 to insert an element into heap\n"
        "2 to find and delete min from heap\n"
        "3 to delete an element from heap\n"
        "4 to print the heap\n"
        "5 to end\n");
}


/*printheap*/
void printheap(HeapNodePtr H){
    Position P,tempPre;
    int i,j,lastnum,lasth;

    P = H->L->nextPtr;
    tempPre = FindPre(H,Last);
    lastnum = ReturnNum(tempPre->data,H->L);
    lasth = mylog(lastnum);

    for(i = 0;i <= lasth;i++){
        while(ReturnNum(P->data,H->L) > factorial(i-1) && ReturnNum(P->data,H->L) < factorial(i + 1) && P != Last){
            printf("%5d",P->data);
            P = P->nextPtr;
        }
        printf("\n");
    }
}

/*printList*/
void printList(List L){
    Position P;

    P = L->nextPtr;
    while(P != Last){
        printf("%d -->",P->data);
        P = P->nextPtr;
    }
    printf("NULL\n");
    
}

/*InitializeHeap*/
HeapNodePtr InitializeHeap(){
    HeapNodePtr H;
    List L;

    H = malloc(sizeof(HeapNode));
    if(H == NULL){
        printf("Out of space");
        exit(1);
    }

    L = MakeEmpty(L);

    H->currentSize = 0;
    H->L = L;

    return H;
}

/*MakeEmpty*/
List MakeEmpty(List L){
    L = malloc(sizeof(LinkNode));
    Last = malloc(sizeof(LinkNode));

    L->data = -32767;
    if(L == NULL){
        printf("Out of space!!!");
        exit(1);
    }
    L->nextPtr = Last;
    return L;
}

/*Insert*/
void Insert(int X,HeapNodePtr H){
    Position P,temp;
    int i;

    P = malloc(sizeof(LinkNode));
    temp = FindPre(H,Last);

    if(P == NULL){
        printf("Out of space");
        exit(1);
    }

    temp->nextPtr = P;
    P->nextPtr = Last;

    for(i = ++H->currentSize;X < FindNum(i/2,H->L);i /= 2){
        printf("FindNum(%d) = %d\n",i/2,FindNum(i/2,H->L));
        Change(i,H->L,FindNum(i/2,H->L));
    }
    Change(i,H->L,X);
}

/*FindMin*/
int FindMin(HeapNodePtr H){
    if(H->L->nextPtr == Last){
        printf("Heap is empty");
    }
    return H->L->nextPtr->data;
}

/*DeleteMin*/
int DeleteMin(HeapNodePtr H){
    int i,child;
    int Min,Final;
    Position temp,P;

    Min = FindNum(1,H->L);
    Final = FindNum(H->currentSize--,H->L);

    if(H->L->nextPtr == Last){
        printf("Heap is empty");
    }

    for(i = 1;2 * i < H->currentSize;i = child){
        child = 2 * i;

        if(FindNum(child,H->L) > FindNum(child + 1,H->L))
            child++;

        if(Final > FindNum(child,H->L)){
            Change(i,H->L,FindNum(child,H->L));
        }else{
            break;
        }
    }
    Change(i,H->L,Final);

    temp = FindPre(H,Last);
    P = FindPre(H,temp);
    P->nextPtr = Last;
    free(temp);

    return Min;
}

/*Delete*/
void Delete(HeapNodePtr H,int n){
    if(n > H->currentSize){
        printf("Over the heap\n");
        return ;
    }
    Position temp,P;
    int i,child;
    int Final;

    Final = FindNum(H->currentSize--,H->L);
    for(i = n;2 * i < H->currentSize;i = child){
        child = 2 * i;

        if(FindNum(child,H->L) > FindNum(child + 1,H->L))
            child++;
        if(Final > FindNum(child,H->L))
            Change(i,H->L,FindNum(child,H->L));
        else
            break;
    }
    Change(i,H->L,Final);

    temp = FindPre(H,Last);
    P = FindPre(H,temp);
    P->nextPtr = Last;
    free(temp);
}

/*输入是第几个数，返回链表中的数据*/
int FindNum(int X,List L){
    int i;
    Position P = L->nextPtr;

    if(X == 0){
        return L->data;
    }

    for(i = 1;i < X;i++){
        P = P->nextPtr;
    }

    return P->data;
}

/*用n替换掉链表的第x个数据*/
void Change(int X,List L,int n){
    int i;
    Position P = L->nextPtr;

    for(i = 1;i < X;i++){
        P = P->nextPtr;
    }
    
    P->data = n;
}

/*FindPre*/
LinkNodePtr FindPre(HeapNodePtr H,Position P){
    Position p;

    p = H->L;
    while(p != Last && p->nextPtr != P){
        p = p->nextPtr;
    }

    return p;
}

/*Destroy*/
void Destroy(HeapNodePtr H){
    Position P,tempPtr;

    P = H->L->nextPtr;
    free(H->L);
    while(P != Last){
        tempPtr = P;
        P = P->nextPtr;
        free(tempPtr);
    }
    free(Last);
    free(H);
}
