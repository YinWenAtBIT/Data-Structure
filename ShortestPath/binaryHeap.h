/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/27
description:为了dijkstra算法修改的二叉堆
********************************************/
#include "AdjacencyList.h"




#ifndef _BINARY_HEAP
#define _BINARY_HEAP


#define NotAVertex -1

struct AdjvexPath;
struct HeapStruct;
typedef HeapStruct * PriorityQueue;
typedef struct AdjvexPath Adjvex;


PriorityQueue Initialize(int MaxElements);
void Destory(PriorityQueue H);
void makeEmpty(PriorityQueue H);
void Insert(Adjvex X, PriorityQueue H);
Adjvex DeleteMin(PriorityQueue H);
Adjvex FindMin(PriorityQueue H);
int isEmpty(PriorityQueue H);
int isFull(PriorityQueue H);
PriorityQueue BuildHeap(Adjvex *x, int n);
void PercolateUp(PriorityQueue H, int hole);
void PercolateDown(PriorityQueue H, int hole);

struct AdjvexPath
{
	Index vertex;
	WeightType cost;
};

/*打印二叉堆，利用递归打印，输出结果与二叉树相似*/
void printBHeap(PriorityQueue H, int depth, int Index);
#endif

struct HeapStruct
{
	int capacity;
	int size;
	Adjvex * Elements;
};


