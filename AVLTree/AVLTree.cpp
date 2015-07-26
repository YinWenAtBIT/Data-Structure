/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/22
description:AVL树
********************************************/
#include "AVLTree.h"
#include <stdlib.h>
#include <iostream>

#define Max(a,b) ((a)>(b)?(a):(b))


/*返回树节点的高度，如果为NULL返回-1*/
int Hight(AVLTree T)
{
	if(T == NULL)
	{
		return -1;
	}
	return T->Hight;
}



AVLTree MakeEmpty(AVLTree T)
{
	if(T !=NULL)
	{
		MakeEmpty(T->Lchild);
		MakeEmpty(T->Rchild);
		free(T);
	}
	return NULL;
}

/*递归查找*/
Position Find(ElementType X, AVLTree T)
{
	if(T == NULL)
	{
		return NULL;
	}
	if(X< T->Element)
		return Find(X, T->Lchild);
	if(X > T->Element)
		return Find(X, T->Rchild);
	if( X == T->Element)
		return T;
}

/*非递归查找*/
Position FindMin(AVLTree T)
{
	if(T !=NULL)
	{
		while(T->Lchild !=NULL)
			T= T->Lchild;

		return T;
	}
	return NULL;
}

/*非递归查找*/
Position FindMax(AVLTree T)
{
	if(T !=NULL)
	{
		while(T->Rchild !=NULL)
			T= T->Rchild;

		return T;
	}
	return NULL;
}

/*递归插入*/
AVLTree Insert(ElementType X, AVLTree T)
{
	if(T == NULL)
	{
		T = (AVLTree)malloc(sizeof(AVLNode));
		if(T ==NULL)
			exit(1);

		T->Element = X;
		T->Lchild = T->Rchild = NULL;
		T->Hight = 0;
	}
	if(X <T->Element)
	{
		T->Lchild = Insert(X, T->Lchild);
		/*左边插入之后检查是否满足平衡条件，如果不平衡需要进行旋转*/
		if( (Hight(T->Lchild)-Hight(T->Rchild)) == 2)
		{
			if(X< T->Lchild->Element)
				T = SingleRotateLeft(T);
			else
				T = DoubleRotateLeft(T);
		}
	}
	if(X >T->Element)
	{
		T->Rchild = Insert(X, T->Rchild);
		/*右边插入之后检查是否满足平衡条件，如果不平衡需要进行旋转*/
		if((Hight(T->Rchild) - Hight(T->Lchild)) ==2)
		{
			if(X >T->Rchild->Element)
				T = SingleRotateRight(T);
			else
				T = DoubleRotateRight(T);
		}
	}
	/*X in the Tree already, we will do nothing*/
	/*插入完成更新该节点高度*/
	T->Hight = Max(Hight(T->Lchild), Hight(T->Rchild)) +1;
	return T;
}

/*左边树枝旋转*/
AVLTree SingleRotateLeft(AVLTree T)
{
	AVLTree k1;

	k1 = T->Lchild;
	T->Lchild = k1->Rchild;
	k1->Rchild = T;

	T->Hight = Max(Hight(T->Lchild), Hight(T->Rchild)) +1;
	k1->Hight = Max(Hight(k1->Lchild), Hight(k1->Rchild)) +1;

	return k1;
}
/*右边树枝旋转*/
AVLTree SingleRotateRight(AVLTree k1)
{
	Position k2;

	k2 = k1->Rchild;
	k1->Rchild = k2->Lchild;
	k2->Lchild = k1;

	k1->Hight = Max(Hight(k1->Lchild), Hight(k1->Rchild))+1;
	k2->Hight = Max(Hight(k2->Lchild), Hight(k2->Rchild))+1;

	return k2;
}

/*左边树枝双旋转*/
AVLTree DoubleRotateLeft(AVLTree k3)
{
	k3->Lchild = SingleRotateRight(k3->Lchild);
	return SingleRotateLeft(k3);
}

/*右边树枝双旋转*/
AVLTree DoubleRotateRight(AVLTree k1)
{
	k1->Rchild = SingleRotateLeft(k1->Rchild);
	return SingleRotateRight(k1);
}

/*递归删除*/
AVLTree Delete(ElementType X, AVLTree T)
{
	if(T == NULL)
	{
		fprintf(stderr, "%d not exist\n", X);
	}
	else
	{
		if(X < T->Element)
		{
			T->Lchild = Delete(X, T->Lchild);
			/*删除之后需要更新该节点高度*/
			T->Hight =Max(Hight(T->Lchild), Hight(T->Rchild))+1;
			/*删除之后检查是否满足平衡条件，不满足需要旋转*/
			if((Hight(T->Rchild) - Hight(T->Lchild)) == 2)
			{
				if(Hight(T->Rchild->Rchild) >= Hight(T->Rchild->Lchild))
					T = SingleRotateRight(T);
				else
					T = DoubleRotateRight(T);
			}

		}
		else if(X > T->Element)
		{
			T->Rchild = Delete(X, T->Rchild);
			/*删除之后需要更新该节点高度*/
			T->Hight =Max(Hight(T->Lchild), Hight(T->Rchild))+1;
			/*删除之后检查是否满足平衡条件，不满足需要旋转*/
			if((Hight(T->Lchild) - Hight(T->Rchild)) == 2)
			{
				if(Hight(T->Lchild->Lchild) >= Hight(T->Lchild->Rchild))
					T = SingleRotateLeft(T);
				else
					T = DoubleRotateLeft(T);
			}

		}
		else
		{
			/*找到的树节点如果有两个孩子的话就用它右子树的最大值代替该点，再删去右子数上的最大值*/
			if(T ->Lchild &&T->Rchild)
			{
				T->Element = FindMin(T->Rchild)->Element;
				T->Rchild = Delete(T->Element, T->Rchild);
				
				T->Hight =Max(Hight(T->Lchild), Hight(T->Rchild))+1;

				if((Hight(T->Lchild) - Hight(T->Rchild)) == 2)
				{
					if(Hight(T->Lchild->Lchild) >= Hight(T->Lchild->Rchild))
						T = SingleRotateLeft(T);
					else
						T = DoubleRotateLeft(T);
				}

			}
			else
			{
				AVLTree temp = T;
				if(T->Lchild == NULL)
					T= T->Rchild;
				else
					T= T->Lchild;

				free(temp);
			}
		}

	}

	
	
	return T;

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

void PrintTree(AVLTree T, int depth)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->Lchild != NULL)
		PrintTree(T->Lchild, depth+1);

	PrintDepth(T->Element, depth);
	if(T->Rchild !=NULL)
		PrintTree(T->Rchild, depth+1);
}

void PrintTree(AVLTree T)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->Lchild != NULL)
		PrintTree(T->Lchild);

	printf("%d\n",T->Element);
	if(T->Rchild !=NULL)
		PrintTree(T->Rchild);
}