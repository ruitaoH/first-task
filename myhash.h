/*************************************************************************
	> File Name: myhash.h
	> Author: 
	> Mail: 
	> Created Time: 2015年11月10日 星期二 19时28分22秒
 ************************************************************************/

#ifndef _MYHASH_H
#define _MYHASH_H

struct linknode;
struct hashtbl;
typedef struct linknode LinkNode;
typedef struct hashtbl HashTbl;
typedef LinkNode *Position;
typedef Position List;
typedef HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
int Delete(int Key,HashTable H);
void DestroyTable(HashTable H);
Position Find(int Key,HashTable H);
void Insert(int Key,HashTable H);
int Retrieve(Position P);
void instructions(void);
void printHash(int Key,HashTable H);
void printTable(HashTable H);
#endif

