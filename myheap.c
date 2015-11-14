/*************************************************************************
	> File Name: myheap.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月14日 星期六 15时57分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"myheap.h"

#define MinSize 15
#define MinData -32767

struct heapNode{
    int *data;
    int currentSize;
    int Capacity;
};

int main(){
    HeapNodePtr H;
    int choice,delete;
    int item;

    H = Initialize(20);
    printf("%d\n",H->Capacity);
    printf("%d\n",H->currentSize);

    instructions();
    printf("your choice:");
    scanf("%d",&choice);

    while(choice != 4){
        switch(choice){
            case 1:
                printf("\ninput a number\n");
                scanf("%d",&item);
                Insert(item,H);
                break;
            case 2:
                printf("minelement is %d\n",FindMin(H));
                printf("do you want to delete min(0-NO,1-YES)\n");
                scanf("%d",&delete);
                if(delete == 0)
                    ;
                else if(delete == 1)
                    DeleteMin(H);
                else
                    printf("input error\n");
                break; 
            case 3:
                if(IsEmpty(H)){
                    printf("heap is empty\n");
                    break;
                }
                printHeap(H);
                break;
            default:
                printf("Invalid choice\n");
                instructions();
                break;
        }
        printf("your choice:");
        scanf("%d",&choice);
    }
    Destroy(H);
    printf("Run to end\n");

    return 0;

}

void instructions(void){
    printf("Enter your choice:\n"
        "1 to insert a element\n"
        "2 to find and delete minelement\n"
        "3 to print heap\n"
        "4 to end\n");
}

int IsEmpty(HeapNodePtr H){
    return H == NULL;
}

int IsFull(HeapNodePtr H){
    return H->Capacity == H->currentSize;
}

void MakeEmpty(HeapNodePtr H){
    H->currentSize = 0;    
}

void Destroy(HeapNodePtr H){
    free(H->data);
    free(H);
}

HeapNodePtr Initialize(int Max){
    HeapNodePtr H;

    if(Max < MinSize){
        printf("size is too small\n");
        exit(1);
    }

    H = malloc(sizeof(HeapNode));
    if(H == NULL){
        printf("Out of space!!!\n");
        exit(1);
    }
    
    H->data = malloc(sizeof(int)*(Max + 1));
    if(H->data == NULL){
        printf("Out of space!!!\n");
        exit(1);
    }

    H->currentSize = 0;
    H->Capacity = Max;
    H->data[0] = MinData;

    return H;
}

/**************************************************
 *采用上虑法实现数据的插入操作
 *上虑法的实现方式比较简单，首先创建一个空节点
 *然后将需要插入的值与当前空穴的父结点进行比较
 *如果大于父结点，直接插入空穴中
 *如果小于父结点的值，则将父结点的值下拉到空穴中
 *之前父结点的位置就是空穴，接着与上层比较
 *直到找到父结点大于当前插入值的情况
 ***************************************************/
void Insert(int value,HeapNodePtr H){
    int i;

    if(IsFull(H)){
        printf("Heap is full\n");
        return ;
    }

    for(i = ++H->currentSize;value < H->data[i/2];i /= 2){
        H->data[i] = H->data[i/2];
    }
    H->data[i] = value;
}

int FindMin(HeapNodePtr H){
    if(H != NULL){
        return H->data[1];
    }else{
        printf("Heap is empty");
    }
    return H->data[0];
}

/***********************************************************
 *下虑法实现数据的重排序操作
 *实现的方式，将子结点的两个儿子进行比较，将小的提升
 *需要注意的是如何让判断节点是否一定存在右儿子
 *实现的方式主要是利用了二叉堆的特性:
 *2*pare = L_child
 *2*pare + 1 = R_child;
 ************************************************************/
int DeleteMin(HeapNodePtr H){
    int i,child;
    int Min,Last;

    Min = H->data[1];
    Last = H->data[H->currentSize--];

    if(IsEmpty(H)){
        printf("Heap is empty");
    }

    for(i = 1;2 * i < H->currentSize;i = child){
        child = i * 2;
        if(child < H->currentSize && H->data[child] > H->data[child + 1])
            child++;

        if(Last > H->data[child])
            H->data[i] = H->data[child];
        else 
            break;
    }
    H->data[i] = Last;

    return Min;
}

void printHeap(HeapNodePtr H){
    int i;

    for(i = 1;i <= H->currentSize;i++){
        printf(" %3d ",H->data[i]);
        if(i%5 == 0)
            printf("\n");
    }
    printf("\n");
}
