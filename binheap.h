/*************************************************************************
	> File Name: binheap.h
	> Author: 
	> Mail: 
	> Created Time: 2015年11月11日 星期三 18时24分22秒
 ************************************************************************/

#ifndef _BINHEAP_H
#define _BINHEAP_H

struct heapNode;
typedef struct heapNode HeapNode;
typedef HeapNode *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int X,PriorityQueue H);
int DeleteMin(PriorityQueue H);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void printHeap(PriorityQueue H);
void instructions(void);

#endif

