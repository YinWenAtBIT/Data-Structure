/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/20
description:二叉查找树
********************************************/
#include "searchTree.h"

#include <stdlib.h>
#include <malloc.h>
#include <iostream>
SearchTree MakeEmpty(SearchTree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->lchild);
		MakeEmpty(T->rchild);
		free(T);
	}

	return NULL;
}

/*递归查找*/
Position Find(ElementType X, SearchTree T)
{
	if(T == NULL)
		return NULL;

	if(T->Element == X)
		return T;
	else if(X <T->Element)
		return Find(X, T->lchild);
	else
		return Find(X, T->rchild);
}

/*非递归查找最小值*/
Position FindMin(SearchTree T)
{
	if(T!=NULL)
	{
		while(T->lchild !=NULL)
			T = T->lchild;

		return T;
	}
	return NULL;
}

/*非递归查找最大值*/
Position FindMax(SearchTree T)
{
	if(T!= NULL)
	{
		while(T->rchild !=NULL)
			T= T->rchild;

		return T;
	}
	return NULL;
}

/*递归插入*/
SearchTree Insert(ElementType X, SearchTree T)
{
	if(T ==NULL)
	{
		T = (SearchTree)malloc(sizeof(TreeNode));
		T->Element = X;
		T->lchild = T->rchild = NULL;

	}
	else if(X< T->Element)
	{
		T->lchild = Insert(X, T->lchild);
	}
	else if(X>T->Element)
	{
		T->rchild = Insert(X, T->rchild);
	}
	return T;

}

/*递归删除*/
SearchTree Delete(ElementType X, SearchTree T)
{
	Position tempCell;
	if(T ==NULL)
	{
		perror("Element not Found");
		return NULL;
	}
	if(X< T->Element)
		T->lchild = Delete(X, T->lchild);
	else if(X> T->Element)
		T->rchild = Delete(X, T->rchild);
	else
	{
		/*找到的树节点如果有两个孩子的话就用它右子树的最大值代替该点，再删去右子数上的最大值*/
		if(T->lchild && T->rchild)
		{
			tempCell = FindMin(T->rchild);
			T->Element = tempCell ->Element;
			T->rchild = Delete(T->Element, T->rchild);
		}
		else 
		{
			tempCell = T;
			if(T->lchild ==NULL)
				T = T->rchild;
			else
				T = T->lchild;
			free(tempCell);
		}
	}
	return T;

}
/*打印节点值，根据深度在之前加入4个空格*/
void PrintDepth(ElementType A, int depth)
{
	while(depth !=0)
	{
		printf("	");
		depth --;
	}
	printf("%d\n", A);
}
/*打印树，depth为根节点的初始化深度*/
void PrintTree(SearchTree T, int depth)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->lchild != NULL)
		PrintTree(T->lchild, depth+1);

	PrintDepth(T->Element, depth);
	if(T->rchild !=NULL)
		PrintTree(T->rchild, depth+1);
}
/*打印树，先答应左子树再打印右子树*/
void PrintTree(SearchTree T)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->lchild != NULL)
		PrintTree(T->lchild);

	printf("%d\n",T->Element);
	if(T->rchild !=NULL)
		PrintTree(T->rchild);
}