#include "AVLTree.h"
#include <stdlib.h>
#define Max(a,b) ((a)>(b)?(a):(b))
#include <iostream>

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
		if((Hight(T->Rchild) - Hight(T->Lchild)) ==2)
		{
			if(X >T->Rchild->Element)
				T = SingleRotateRight(T);
			else
				T = DoubleRotateRight(T);
		}
	}
	/*X in the Tree already, we will do nothing*/

	T->Hight = Max(Hight(T->Lchild), Hight(T->Rchild)) +1;
	return T;
}

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

AVLTree DoubleRotateLeft(AVLTree k3)
{
	k3->Lchild = SingleRotateRight(k3->Lchild);
	return SingleRotateLeft(k3);
}

AVLTree DoubleRotateRight(AVLTree k1)
{
	k1->Rchild = SingleRotateLeft(k1->Rchild);
	return SingleRotateRight(k1);
}

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
			/*最开始未加上删除之后重新计算改点高度的代码，会导致底部的节点被删除后改点高度不变*/
			T->Hight =Max(Hight(T->Lchild), Hight(T->Rchild))+1;
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
			/*最开始未加上删除之后重新计算改点高度的代码，会导致底部的节点被删除后改点高度不变*/
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
			if(T ->Lchild &&T->Rchild)
			{
				T->Element = FindMin(T->Rchild)->Element;
				T->Rchild = Delete(T->Element, T->Rchild);
				/*最开始未加上删除之后重新计算改点高度的代码，会导致底部的节点被删除后改点高度不变*/
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