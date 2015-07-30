/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/30
description:哈希表(开放定址法)
********************************************/

#ifndef _HASH_TABLE
#define _HASH_TABLE

struct HashTbl;
typedef HashTbl * HashTable;
typedef int ElementType;
typedef unsigned int Index;
typedef Index Position;


HashTable initializeTable(int TableSize);
void DestroyTable(HashTable H);
Position FindKey(ElementType Key, HashTable H);
void insertKey(ElementType Key, HashTable H);
void deleteKey(ElementType Key, HashTable H);

void PrintHashTable(HashTable H);

/*平方取中法*/
int Hash(ElementType Key, int TableSize);

/*令Empty默认为0，则使用calloc可以自动初始化为Empty*/
enum KindOfEntry
{
	Empty =0,
	Legitimate,
	Deleted
};

struct HashEntry
{
	ElementType Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
	int TableSize;
	Cell * TheCells;
};


#endif