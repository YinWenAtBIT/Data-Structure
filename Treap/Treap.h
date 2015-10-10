/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/10
description:Treap树
********************************************/
#ifndef _TREAP_H
#define _TREAP_H

#define Infinity 0x7fffffff

struct TreapNode;
typedef struct TreapNode* TreapTree;
typedef struct TreapNode* Position;
typedef int ElementType;

struct TreapNode
{
	ElementType Element;
	TreapTree left;
	TreapTree right;
	int Priority;
};

/*初始化*/
TreapTree initialize();

/*插入*/
TreapTree insert(ElementType item, TreapTree T);

/*删除*/
TreapTree remove(ElementType item, TreapTree T);

/*右旋转*/
TreapTree rightSingleRotate(TreapTree T);

/*左旋转*/
TreapTree leftSingleRotate(TreapTree k1);

/*打印树*/
void PrintTree(TreapTree T, int depth);
#endif