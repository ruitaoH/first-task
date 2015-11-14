/*************************************************************************
	> File Name: myheap.h
	> Author: 
	> Mail: 
	> Created Time: 2015年11月14日 星期六 15时48分29秒
 ************************************************************************/

#ifndef _MYHEAP_H
#define _MYHEAP_H

struct heapNode;
typedef struct heapNode HeapNode;
typedef HeapNode *HeapNodePtr;

HeapNodePtr Initialize(int Max);
int IsEmpty(HeapNodePtr H);
int IsFull(HeapNodePtr H);
void instructions(void);
void MakeEmpty(HeapNodePtr H);
void Insert(int value,HeapNodePtr H);
void Destroy(HeapNodePtr H);
int FindMin(HeapNodePtr H);
int DeleteMin(HeapNodePtr H);
void printHeap(HeapNodePtr H);

#endif
