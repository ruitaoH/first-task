/*************************************************************************
	> File Name: myhash.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月10日 星期二 19时34分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"myhash.h"

#define MinTableSize 10

struct linknode{
    int data;
    Position nextPtr;
};

struct hashtbl{
    int TableSize;
    List *TheList;
};

/*NextPrime*/
static int NextPrime(int N){
    int i;

    if(N % 2 == 0){
        N++;
    }
    for(;;N += 2){
        for(i = 3;i * i <= N;i += 2){
            if(N % i == 0){
                goto ContOuter;
            }
            return N;
        }
        ContOuter: ;
    }
}

/*Hash*/
int Hash(int Key,int TableSize){
    return Key % TableSize;
}

int main(void){
    HashTable H = InitializeTable(20);
    printf("%d\n",H->TableSize);
    printf("%d\n",H->TheList[0]->data);
    int choice;
    int item;

    instructions();
    printf("your choice:");
    scanf("%d",&choice);

    while(choice != 4){
        switch(choice){
            case 1:
                printf("\nEnter a number:\n");
                scanf("%d",&item);
                Insert(item,H);
                break;
            case 2:
                printf("\nEnter a number to delete\n");
                scanf("%d",&item);
                Delete(item,H);
                break;
            case 3:
                printTable(H);
                break;
            default:
                printf("\nInvaild choice\n\n");
                instructions();
                break;
        }
        printf("\nyour choice:");
        scanf("%d",&choice);
    }
    DestroyTable(H);
    printf("End of run\n");

    return 0;
}

/*instructions*/
void instructions(void){
    printf("Enter your choice:\n"
        "1 to insert an element into Hash\n"
        "2 to delete an element\n"
        "3 to see list from Hash\n" 
        "4 to end\n");
}

/*InitializeTable分离链接散列表的初始化*/
HashTable InitializeTable(int TableSize){
    HashTable H;
    int i;

    if(TableSize < MinTableSize){
        printf("Table is too small\n");
        return NULL;
    }

    H = malloc(sizeof(HashTbl));
    if(H != NULL){
        H->TableSize = NextPrime(TableSize);

        H->TheList = malloc(sizeof(List) * H->TableSize);
        if(H->TheList == NULL){
            printf("Out of spzce!!!\n");
        }

        for(i = 0;i < H->TableSize;i++){
            H->TheList[i] = malloc(sizeof(LinkNode));

            if(H->TheList[i] == NULL){
                printf("Out of space!!!\n");
            }else{
                H->TheList[i]->nextPtr = NULL;
            }
        } 
    }else{
        printf("Out of space!!!\n");
    }
    return H;
}

/*Find*/
Position Find(int Key,HashTable H){
    List L;
    Position P;

    L = H->TheList[Hash(Key,H->TableSize)];
    P = L->nextPtr;

    while(P != NULL && P->data != Key){
        P = P->nextPtr;
    }

    return P;
}

/*Insert*/
void Insert(int Key,HashTable H){
    Position tempPtr,Pos;
    List L;

    Pos = Find(Key,H);
    if(Pos == NULL){
        tempPtr = malloc(sizeof(LinkNode));

        if(tempPtr != NULL){
            L = H->TheList[Hash(Key,H->TableSize)];
            tempPtr->data = Key;
            tempPtr->nextPtr = L->nextPtr;
            L->nextPtr = tempPtr;
        }else{
            printf("Out of space!!!\n");
        }
    }

}

/*Retrieve*/
int Retrieve(Position P){
    return P->data;
}

/*DestroyTable*/
void DestroyTable(HashTable H){
    int i;

    for(i = 0;i < H->TableSize;i++){
        Position P = H->TheList[i];
        Position Temp;

        while(P != NULL){
            Temp = P->nextPtr;
            free(P);
            P = Temp;
        }
    }
    free(H->TheList);
    free(H);
}

/*Delete*/
int Delete(int Key,HashTable H){
    Position P,temp;

    if((temp = Find(Key,H)) == NULL){
        printf("Can't find\n");
        return 0;
    }

    P = H->TheList[Hash(Key,H->TableSize)]->nextPtr;

    if(P->data == Key){
        H->TheList[Hash(Key,H->TableSize)]->nextPtr = P->nextPtr;
        free(P);
        return Key;
    }

    if(P->nextPtr == NULL){
        H->TheList[Hash(Key,H->TableSize)]->nextPtr = NULL;
        free(P);
        return Key;
    }

    while(P != NULL && P->nextPtr->data != Key){
        P = P->nextPtr;
    }

    P->nextPtr = temp->nextPtr;
    free(temp);

    return Key;
}

/*printTable*/
void printTable(HashTable H){
    int i;
    Position P;

    for(i = 0;i < H->TableSize;i++){
        P = H->TheList[i]->nextPtr;

        while(P != NULL){
            printf("%d -->",P->data);
            P = P->nextPtr;
        }
        printf("NULL\n");
    }
}


