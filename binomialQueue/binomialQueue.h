/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/11
description:二项队列
********************************************/

#ifndef _BINOMIAL_QUEUE
#define _BINOMIAL_QUEUE

struct BinNode;
struct Collection;

typedef int ElementType;
typedef struct Collection * BinQueue;
typedef struct BinNode * Position;
typedef struct BinNode * BinTree;

#define MaxSize 30
#define Capacity 4294967296

BinQueue initialize();
bool isEmpty(BinQueue H);
bool isFUll(BinQueue H);
void insert(ElementType X, BinQueue H);
int findMin(BinQueue H);
void destroy(BinQueue H);
BinQueue merge(BinQueue H1, BinQueue H2);
ElementType DeleteMin(BinQueue H);

void PrintTree(BinTree T, int depth);
void PrintDepth(ElementType A, int depth);

struct BinNode
{
	ElementType Element;
	Position leftChild;
	Position nextSibling;

};

struct Collection
{
	int currentSize;
	BinTree theTrees[MaxSize];
};

#endif