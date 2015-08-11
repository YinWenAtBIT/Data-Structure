/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/4
description:左式堆实现代码
********************************************/
#include "LeftistHeap.h"
#include <stdlib.h>
#include <iostream>

PriorityQueue merge1(PriorityQueue H1, PriorityQueue H2);
void switchChildren(PriorityQueue H);

PriorityQueue merge(PriorityQueue H1, PriorityQueue H2)
{
	if(H1 == NULL)
		return H2;
	if(H2 == NULL)
		return H1;

	if(H1->Element < H2->Element)
		return merge1(H1, H2);
	else
		return merge1(H2, H1);
}

PriorityQueue merge1(PriorityQueue H1, PriorityQueue H2)
{
	if(H1->Left == NULL)
		H1->Left = H2;
	else
	{
		H1->Right = merge(H1->Right, H2);
		if(H1->Left->Npl < H1->Right->Npl)
			switchChildren(H1);

		H1->Npl = H1->Right->Npl +1;
	}

	return H1;
}

ElementType findMin(PriorityQueue H)
{
	return H->Element;
}

int isEmpty(PriorityQueue H)
{
	return H == NULL;
}

PriorityQueue deleteMin(PriorityQueue H)
{
	if(H == NULL)
		return H;
	PriorityQueue Leftchild, Rightchild;
	Leftchild = H->Left;
	Rightchild = H->Right;
	free(H);
	return merge(Leftchild, Rightchild);
}

PriorityQueue insert(ElementType X, PriorityQueue H)
{
	PriorityQueue newone = (PriorityQueue)malloc(sizeof(TreeNode));
	newone->Element = X;
	newone->Left = newone->Right = NULL;
	newone ->Npl =0;
	H = merge(H, newone);
	return H;
}



void switchChildren(PriorityQueue H)
{
	if(H == NULL)
		return;

	PriorityQueue temp;
	temp = H->Right;
	H->Right = H->Left;
	H->Left = temp;

}


void PrintDepth(ElementType A, int depth)
{
	while(depth !=0)
	{
		printf("	");
		depth --;
	}
	printf("%d\n", A);
}

void PrintTree(PriorityQueue T, int depth)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->Left != NULL)
		PrintTree(T->Left, depth+1);

	PrintDepth(T->Element, depth);
	if(T->Right !=NULL)
		PrintTree(T->Right, depth+1);
}

void PrintTree(PriorityQueue T)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->Left != NULL)
		PrintTree(T->Left);

	printf("%d\n",T->Element);
	if(T->Right !=NULL)
		PrintTree(T->Right);
}