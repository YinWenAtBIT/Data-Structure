/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/23
description:哈希表(开放定址法)
			为邻接表做了修改
********************************************/

#ifndef _HASH_TABLE
#define _HASH_TABLE

struct HashTbl;
struct VertexNode;
struct EdgeNode;

typedef EdgeNode *Edge;
typedef char VertexType[20];
typedef HashTbl * HashTable;
typedef unsigned int Index;
typedef Index Position;
typedef int WeightType;

HashTable initializeTable(int TableSize);
void DestroyTable(HashTable H);
Position FindKey(VertexType Key, HashTable H);
void insertKey(VertexType Key, HashTable H);
void deleteKey(VertexType Key, HashTable H);

void PrintHashTable(HashTable H);

/*平方取中法*/
int Hash(VertexType Key, int TableSize);

/*令Empty默认为0，则使用calloc可以自动初始化为Empty*/
enum KindOfEntry
{
	Empty =0,
	Legitimate,
	Deleted
};

struct EdgeNode
{
	int vertexIndex;
	WeightType weight;
	Edge next;
};

struct VertexNode
{
	VertexType vertexName;
	int vertexIndex;
	Edge next;
	enum KindOfEntry Info;
};

typedef struct VertexNode Cell;

struct HashTbl
{
	int TableSize;
	int vertex, edge;
	Cell * TheCells;
};


#endif