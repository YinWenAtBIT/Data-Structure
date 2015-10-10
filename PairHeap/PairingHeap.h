/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/10
description:≈‰∂‘∂—
********************************************/
#ifndef _PAIRING_HEAP
#define _PAIRING_HEAP

struct PairNode;
typedef PairNode * Position;
typedef PairNode * PairHeap;
typedef int ElementType;


Position CompareAndLink(Position H1, Position H2);
ElementType findMin(PairHeap H);
int isEmpty(PairHeap H);
PairHeap deleteMin(ElementType * Min, PairHeap H);
PairHeap insert(ElementType X, PairHeap H, Position * Loc);
PairHeap CombineSiblings(Position FirstSibling);
PairHeap DecreaseKey(Position P, ElementType Delta, PairHeap H);

void PrintTree(PairHeap T);
void PrintTree(PairHeap T, int depth);
void PrintDepth(ElementType A, int depth);

#endif

struct PairNode
{
	ElementType Element;
	PairHeap Left;
	PairHeap NextSibling;
	PairHeap Prev;
};