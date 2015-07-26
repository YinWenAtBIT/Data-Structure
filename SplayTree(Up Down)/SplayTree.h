/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/26
description:SplayTree UpDown自顶向下，不包含父亲节点
********************************************/
#ifndef _SPLAYTREE_H
#define _SPLAYTREE_H

struct SplayNode;
typedef struct SplayNode * Position;
typedef struct SplayNode * SplayTree;

typedef int ElementType;

SplayTree MakeEmpty(SplayTree T);
Position Find(ElementType X, SplayTree T);
Position FindMin(SplayTree T);
Position FindMax(SplayTree T);
SplayTree insert(ElementType X, SplayTree T);
SplayTree Delete(ElementType X, SplayTree T);
SplayTree Splay(ElementType X, SplayTree T);


SplayTree LeftSingleRotate(SplayTree T);
SplayTree RightSingleRotate(SplayTree T);




void PrintTree(SplayTree T, int depth);
void PrintTree(SplayTree T);
void PrintDepth(ElementType A, int depth);



struct SplayNode
{
	ElementType Element;
	SplayTree Left;
	SplayTree Right;
};

#endif