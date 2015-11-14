/*************************************************************************
	> File Name: binheap.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月11日 星期三 18时30分00秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"binheap.h"

#define MinPQSize 10
#define MinData -32767

struct heapNode{
    int Capacity;
    int Size;
    int *data;
};

int main(){
    srand((unsigned)time(NULL));
    PriorityQueue H = Initialize(15);
    int choice;
    int item;
    int i;

    instructions();
    printf("your choice:");
    scanf("%d",&choice);

    while(choice != 3){
        switch(choice){
            case 1:
                for(i = 0;i < H->Capacity;i++){
                    Insert(rand()%101,H);
                }
                printf("%d\n",H->Capacity);
                printf("%d\n",H->Size);
                printHeap(H);
                break;
            case 2:
                DeleteMin(H);
                printHeap(H);
                break;
            default:
                printf("\nInvalid choice\n");
                instructions();
        }
        printf("\nyour choice:");
        scanf("%d",&choice);
    }
    Destroy(H);
    printf("\nrun to end\n");

    return 0;
}

void instructions(void){
    printf("Enter your choice:\n"
            "1 insert\n"
            "2 deletemin\n"
            "3 end\n");
}

PriorityQueue Initialize(int MaxElements){
    PriorityQueue H;

    if(MaxElements < MinPQSize)
        printf("Priority queue size is too small\n");

    H = malloc(sizeof(HeapNode));
    if(H == NULL)
        printf("Out of space!!!\n");

    H->data = malloc(sizeof(int)*(MaxElements + 1));
    if(H->data == NULL)
            printf("Out of space!!!\n");

    H->Capacity = MaxElements;
    H->Size = 0;
    H->data[0] = MinData;

    return H;
}

void Insert(int X,PriorityQueue H){
    int i;

    if(IsFull(H))
    {    
        printf("PriorityQueue is full\n");
        return ;
    }

    for(i = ++H->Size;H->data[i/2] > X;i /= 2){
        H->data[i] = H->data[i/2];
    }
    H->data[i] = X;
}

int FindMin(PriorityQueue H){
    if(H != NULL)
        return H->data[1];   
    printf("PriorityQueue is empty\n");
    return H->data[0];
}

int DeleteMin(PriorityQueue H){
    int i,child;
    int Min,Last;

    Min = H->data[1];
    Last = H->data[H->Size--];

    if(IsEmpty(H)){
        printf("PriorityQueue is empty\n");
        return H->data[0];
    }
    
    for(i = 1;2 * i <= H->Size;i = child){
        child = 2 * i;
        if(child < H->Size && H->data[child] > H->data[child + 1])
            child++;
        
        
        if(Last > H->data[child]) 
            H->data[i] = H->data[child];
        else 
            break;
    }
    H->data[i] = Last;

    return Min;
}


/*int DeleteMin( PriorityQueue H ){
    int i, Child;
    int MinElement, LastElement;

    if( IsEmpty( H ) )
    {
        printf( "Priority queue is empty" );
        return H->data[ 0 ];
    }
    MinElement = H->data[ 1 ];
    LastElement = H->data[ H->Size-- ];
   
    for( i = 1; i * 2 <= H->Size; i = Child ){
        Child = i * 2;
        if( Child != H->Size && H->data[ Child + 1 ] < H->data[ Child ] )
            Child++;

        if( LastElement > H->data[ Child ] )
            H->data[ i ] = H->data[ Child ];
        else
            break;
    }
    H->data[ i ] = LastElement;
    return MinElement;
}*/

void Destroy(PriorityQueue H){
    free(H->data);
    free(H);
}

int IsEmpty(PriorityQueue H){
    return H->data == NULL;
}

int IsFull(PriorityQueue H){
    return H->Size == H->Capacity;
}

void MakeEmpty(PriorityQueue H){
    H->Size = 0;
}

void printHeap(PriorityQueue H){
    int i;
    for(i = 1;i <= H->Size;i++){
        printf("%3d",H->data[i]);
    }
}
