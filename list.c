/*************************************************************************
	> File Name: insert.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月08日 星期日 11时08分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/*定义节点*/
struct ListNode{
    int data;
    struct ListNode *nextNodePtr;
};

/*重命名*/
typedef struct ListNode ListNode;
typedef ListNode *ListNodePtr;

/*函数声明*/
void insert(ListNodePtr *sPtr,int value);
int delete(ListNodePtr *sPtr,int value);
int isEmpty(ListNodePtr sPtr);
ListNodePtr Find(ListNodePtr sPtr,int value);
ListNodePtr FindPrevious(ListNodePtr sPtr,int value);
void printList(ListNodePtr sPtr);
void instructions(void);

/*主函数*/
int main(void){
    ListNodePtr startPtr = NULL;
    int choice;
    int item;

    instructions();
    printf("?");
    scanf("%d",&choice);

    while(choice != 3){
        switch(choice){
            case 1:
                printf("Enter a number:\n");
                scanf("%d",&item);
                insert(&startPtr,item);
                printList(startPtr);
                break;
            case 2:
                if(isEmpty(startPtr)){
                    printf("List is empty\n\n");
                }else{
                    printf("Enter a number to be deleted:\n");
                    scanf("%d",&item);
                    delete(&startPtr,item);
                    printList(startPtr);
                }
                break;
            default:
                printf("Invalid choice\n\n");
                instructions();
                break;
            }
        printf("?");
        scanf("%d",&choice);
    }
    printf("End of run\n");
    return 0;
}

/*instructions*/
void instructions(void){
    printf("Please input you choice:\n"
        "1 to insert element into list\n"
        "2 to delete element from list\n"
        "3 to end\n");
}

/*insert*/
void insert(ListNodePtr *sPtr,int value){
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(ListNode));

    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextNodePtr = NULL;

        previousPtr = NULL;
        currentPtr = *sPtr;

        while(currentPtr != NULL && value < currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextNodePtr;
        }

        if(previousPtr == NULL){
            newPtr->nextNodePtr = *sPtr;
            *sPtr = newPtr;
        }else{
            previousPtr->nextNodePtr = newPtr;
            newPtr->nextNodePtr = currentPtr;
        }
    }else{
        printf("%d not inserted. No memory available\n",value);
    }
}

/*delete*/
int delete(ListNodePtr *sPtr,int value){
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    if((*sPtr)->data == value){
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextNodePtr;
        free(tempPtr);
        return value;
    }else{
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextNodePtr;
    
        while(currentPtr != NULL && value != currentPtr->data){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextNodePtr;
        }

        if(currentPtr != NULL){
            tempPtr = currentPtr;
            previousPtr->nextNodePtr = currentPtr->nextNodePtr;
            free(tempPtr);
            return value;
        }else{
            printf("%d not found\n",value);
            return value;
        }
    }
}

/*isEmpty*/
int isEmpty(ListNodePtr sPtr){
    return sPtr == NULL;
}

/*printList*/
void printList(ListNodePtr currentPtr){
    if(currentPtr == NULL){
        printf("List is empty\n\n");
    }else{
        printf("The list is:\n");

        while(currentPtr != NULL){
            printf("%d -->",currentPtr->data);

            currentPtr = currentPtr->nextNodePtr;
        }
        printf("NULL\n\n");
    }
}

/*Find*/
ListNodePtr Find(ListNodePtr sPtr,int value){
    ListNodePtr currentPtr;

    currentPtr = sPtr;
    while(currentPtr != NULL && currentPtr->data != value){
        currentPtr = currentPtr->nextNodePtr;
    }

    return currentPtr;
}

/*FindPrevious*/
ListNodePtr FindPrevious(ListNodePtr sPtr,int value){
    ListNodePtr currentPtr;

    currentPtr = sPtr;
    while(currentPtr != NULL && currentPtr->nextNodePtr->data != value){
        currentPtr = currentPtr->nextNodePtr;
    }

    return currentPtr;
}
