/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/4
description:×óÊ½¶Ñ
********************************************/

#ifndef _LEFTIST_HEAP
#define _LEFTIST_HEAP

struct TreeNode;
typedef TreeNode * PriorityQueue;
typedef int ElementType;


PriorityQueue merge(PriorityQueue H1, PriorityQueue H2);
ElementType findMin(PriorityQueue H);
int isEmpty(PriorityQueue H);
PriorityQueue deleteMin(PriorityQueue H);
PriorityQueue insert(ElementType X, PriorityQueue H);

void PrintTree(PriorityQueue T);
void PrintTree(PriorityQueue T, int depth);
void PrintDepth(ElementType A, int depth);

#endif

struct TreeNode
{
	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;
};

