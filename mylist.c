/*************************************************************************
	> File Name: mylist.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月09日 星期一 19时51分09秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"mylist.h"

//#define Error(Str) FatalError(Str)
#define FatalError(Str) fprintf(stderr,"%s\n",Str),exit(1)

struct linkNode{
    int data;
    struct linkNode *nextPtr;
};

int main(void){
    List L;
    int choice;
    int item;

    L = MakeEmpty(L);
    instructions();
    printf("?:");
    scanf("%d",&choice);

    while(choice != 3){
        switch(choice){
            case 1:
                printf("\nEnter a number\n");
                scanf("%d",&item);
                Insert(item,L,L);
                printList(L);
                break;
            case 2:
                if(IsEmpty(L)){
                    printf("\nList is empty\n");
                }else{
                    printf("\nEnter a number to be deleted\n");
                    scanf("%d",&item);
                    myDelete(item,&L);
                    printList(L);
                }
                break;
            default:
                printf("Invalid choice\n\n");
                instructions();
                break;
        }
        printf("\n?:");
        scanf("%d",&choice);
    }
    DeleteList(L);
    printf("End of run\n");
    return 0;
}

/*instructions*/
void instructions(void){
    printf("Enter your choice:\n"
        "1 to insert element into list\n"
        "2 to delete element from list\n"
        "3 to end\n");
}

/*IsEmpty*/
int IsEmpty(List L){
    return L->nextPtr == NULL;
} 

/*IsLast*/
int IsLast(Position P,List L){
    return P->nextPtr == NULL;
}

/*Find*/
Position Find(int X,List L){
    Position P;

    P = L->nextPtr;
    while(P != NULL && P->data != X){
        P = P->nextPtr;
    }
    
    if(P != NULL){
        return P;
    }else{
        return NULL;
    }
}

/*FindPrevious*/
Position FindPrevious(int X,List L){
    Position P;

    P = L->nextPtr;
    while(P != NULL && P->nextPtr->data != X){
        P = P->nextPtr;
    }
    
    if(P->nextPtr != NULL){
        return P;
    }else{
        return NULL;
    }
}

/*Insert*/
void Insert(int X,List L,Position P){
    Position newPtr;

    newPtr = malloc(sizeof(LinkNode));
    if(newPtr != NULL){
        newPtr->data = X;
        newPtr->nextPtr = P->nextPtr;
        P->nextPtr = newPtr;
    }else{
        FatalError("Out of space!!!");
    }
}

/*Delete*/
/*void Delete(int X,List L){
    Position tempPtr,P;
    printf("进入Delete\n"); 
    if(L->nextPtr->data == X){
        tempPtr = L->nextPtr;
        L->nextPtr = tempPtr->nextPtr;
        free(tempPtr);
    }else{
        printf("ok");

        if((P = FindPrevious(X,L)) != NULL){
            if(!IsLast(P,L)){
                printf("%d\n",P->data);
                tempPtr = P->nextPtr;
                P->nextPtr = tempPtr->nextPtr;
                free(tempPtr);
            }
        }else{
            FatalError("Can't find\n");
        }
    }
}*/

/*myDelete*/
int myDelete(int X,List *L){
    Position tempPtr;
    Position prePtr;
    Position curPtr;

    if((*L)->nextPtr->data == X){
        tempPtr = *L;
        *L = tempPtr->nextPtr;
        free(tempPtr);
    }else{
        prePtr = *L;
        curPtr = (*L)->nextPtr;

        while(curPtr != NULL && curPtr->data != X){
            prePtr = curPtr;
            curPtr = curPtr->nextPtr;
        }

        if(curPtr != NULL){
            tempPtr = curPtr;
            prePtr->nextPtr = curPtr->nextPtr;
            free(tempPtr);
        }else{
            printf("Can't find\n");
        }
    }
    return X;
}

/*DeleteList*/
void DeleteList(List L){
    Position P,tempPtr;

    P = L->nextPtr;
    L->nextPtr = NULL;
    while(P != NULL){
        tempPtr = P;
        P = P->nextPtr;
        free(tempPtr);
    }
}

/*printList*/
void printList(List L){
    Position P;

    P = L->nextPtr;
    while(P != NULL){
        printf("%d -->",P->data);
        P = P->nextPtr;
    }
    printf("NULL\n");
    
}

/*MakeEmpty*/
List MakeEmpty(List L){
    if(L != NULL)
        DeleteList(L);
    L = malloc(sizeof(LinkNode));
    if(L == NULL)
        FatalError("Out of space!!!");
    L->nextPtr = NULL;
    return L;
}

/*Header*/
Position Header(List L){
    return L;   
}

/*First*/
Position First(List L){
    return L->nextPtr;
}

/*Advance*/
Position Advance(Position P){
    return P->nextPtr;
}

/*Retrieve*/
int Retrieve(Position P){
    return P->data;
}
