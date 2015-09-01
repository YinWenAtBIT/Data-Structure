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

/*为了使用Kruskal算法添加了一个顶点，现在实际上是表示一条边
现在与之前编写的Dijkstra算法保持兼容,添加了一个元素实际上只

需要添加一条初始化语句（不添加甚至都没事），其他部分结构体自动赋值*/
struct AdjvexPath
{
	Index vertex;
	Index adjvex;
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


