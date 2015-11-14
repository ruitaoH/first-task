/*************************************************************************
	> File Name: mylist.h
	> Author: 
	> Mail: 
	> Created Time: 2015年11月09日 星期一 18时32分49秒
 ************************************************************************/

#ifndef _MYLIST_H
#define _MYLIST_H

/*结构体声明*/
struct linkNode;
typedef struct linkNode LinkNode;
typedef LinkNode *LinkNodePtr;
typedef LinkNodePtr Position;
typedef LinkNodePtr List;

/*函数声明*/
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X,List L);
void Delete(int X, List L);
int myDelete(int X,List *L);
Position FindPrevious(int X, List L);
void Insert(int X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);
void printList(List L);
void instructions(void);

#endif
