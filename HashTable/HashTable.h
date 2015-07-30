/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/22
description:AVL树
********************************************/
#include "list.h"

#ifndef _HASH_TABLE
#define _HASH_TABLE

struct HashTbl;
typedef HashTbl * HashTable;
typedef int ElementType;

HashTable initializeTable(int TableSize);
void DestroyTable(HashTable H);
Position FindKey(ElementType Key, HashTable H);
void insertKey(ElementType Key, HashTable H);
void deleteKey(ElementType Key, HashTable H);

void PrintHashTable(HashTable H);

/*平方取中法*/
int Hash(ElementType Key, int TableSize);


struct HashTbl
{
	int TableSize;
	List * TheList;
};


#endif