/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/25
description:带有父亲指针实现的伸展树，自底向上实现伸展
********************************************/
#ifndef _SPLAYTREE_H
#define _SPLAYTREE_H

struct SplayNode;

typedef SplayNode* SplayTree;
typedef SplayNode* Position;

typedef int ElementType;

SplayTree insert(ElementType X, SplayTree T);
SplayTree Delete(ElementType X, SplayTree T);
SplayTree Find(ElementType X, SplayTree T);
SplayTree makeEmpty(SplayTree T);
SplayTree findMin(SplayTree T);
SplayTree findMax(SplayTree T);

SplayTree Splay(Position P, SplayTree T);

SplayTree LeftSingleRotate(SplayTree T);
SplayTree RightSingleRotate(SplayTree T);
SplayTree LeftDoubleRotate(SplayTree T);
SplayTree RightDoubleRotate(SplayTree T);

struct SplayNode
{
	ElementType Element;
	SplayTree Parent;
	SplayTree Left;
	SplayTree Right;
};


#endif

void PrintTree(SplayTree T, int depth);
void PrintTree(SplayTree T);
void PrintDepth(ElementType A, int depth);