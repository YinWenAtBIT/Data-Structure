/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/9
description:AA树
********************************************/
#ifndef _AATREE_H
#define _AATREE_H

struct AANode;
typedef struct AANode* AATree;
typedef struct AANode* Position;
typedef int ElementType;

struct AANode
{
	ElementType Element;
	AATree left;
	AATree right;
	int level;
};

/*初始化*/
AATree initialize();

/*去除左孩子与根节点同高度*/
AATree skew(AATree T);

/*去除两个连续的右红孩子*/
AATree split(AATree T);

/*右旋转*/
AATree insert(ElementType item, AATree T);

/*右旋转*/
AATree remove(ElementType item, AATree T);

/*右旋转*/
AATree rightSingleRotate(AATree T);

/*左旋转*/
AATree leftSingleRotate(AATree k1);

/*打印树*/
void PrintTree(AATree T, int K);
#endif