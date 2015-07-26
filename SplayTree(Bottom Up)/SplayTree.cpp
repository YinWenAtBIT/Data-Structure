/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/25
description:带有父亲指针实现的伸展树，自底向上实现伸展
********************************************/
#include "SplayTree.h"
#include <stdlib.h>
#include <iostream>


SplayTree FindMax(SplayTree T);
SplayTree searchValue(ElementType X, SplayTree T);

/*插入功能实现的方式是先非递归的插入，再进行Splay操作，其实过于复杂，可以优化，
先进行Splay操作，然后再把新值作为根节点和返回的树合并就可以*/
SplayTree insert(ElementType X, SplayTree T)
{
	/*空树时直接创建新的树*/
	if(T == NULL)
	{
		T = (SplayTree)malloc(sizeof(struct SplayNode));
		if(T == NULL)
		{
			fprintf(stderr, "not enough memory");
			exit(1);
		}
		T->Element = X;
		T->Left = T->Right =T->Parent = NULL;
		return T;
	}
	/*X为根节点时直接返回*/
	if(X == T->Element)
		return T;
	/*X不为根节点，寻找到X之后进行Splay操作*/
	else
	{
		Position tempP = T;
		Position temp = T;
		while(temp != NULL)
		{
			if(X < temp->Element)
			{
				tempP =temp;
				temp = temp->Left;
			}
			else if(X >temp->Element)
			{
				tempP= temp;
				temp = temp->Right;
			}
			//此时X等于temp的成员值
			else
				break;
		}
		/*节点中不存在X*/
		if(temp == NULL)
		{
			Position np= (SplayTree)malloc(sizeof(struct SplayNode));
			if(np == NULL)
			{
				fprintf(stderr, "not enough memory");
				exit(1);
			}
			np->Element = X;
			np->Left = np->Right = NULL;
			np->Parent =tempP;
			if(X<tempP->Element)
				tempP->Left = np;
			else
				tempP->Right = np;

			/*准备调到根节点*/
			temp = np;
		}
		T = Splay(temp, T);
	}
	return T;
}

SplayTree Delete(ElementType X, SplayTree T)
{
	if(T == NULL)
	{
		fprintf(stderr, "%d don't exist", X);
	}
	T =Find(X, T);
	/*要寻找的值已经变成根节点，如果相等则找到，不相等则不存在*/
	if(X == T->Element)
	{
		/*删除根，剩下两个子树L（左子树）和R（右子树）。使用FindMax查找L的最大节点，此时，L的根没有右子树，使R成为L的根的右子树*/
		if(T->Left && T->Right)
		{
			Position Ltemp, Rtemp;
			Ltemp = T->Left;
			Rtemp = T->Right;
			/*左右节点的父亲节点设置为NULL*/
			Ltemp->Parent = Rtemp->Parent =NULL;

			free(T);
			Ltemp = FindMax(Ltemp);
			Ltemp->Right = Rtemp;
			Rtemp->Parent = Ltemp;
			return Ltemp;
		}
		else if(T->Left)
		{
			Position Ltemp = T->Left;
			Ltemp ->Parent =NULL;
			free(T);
			return Ltemp;
		}
		else
		{
			Position Rtemp = T->Right;
			Rtemp ->Parent =NULL;
			free(T);
			return Rtemp;
		}
		
	}
	else
	{
		fprintf(stderr, "%d do not exist", X);
		return T;
	}
}

SplayTree Find(ElementType X, SplayTree T)
{
	/*空树直接返回*/
	if(T==NULL)
	{
		fprintf(stderr, "empty tree");
		return T;
	}
	Position np = searchValue(X, T);
	/*不保证最后返回的元素等于X，需要调用者检查，不为根节点则进行splay操作*/
	if(np != T)
		 return Splay(np, T);
	/*若为根节点，直接返回*/
	else
		return T;

}
SplayTree searchValue(ElementType X, SplayTree T)
{

	/*X小于当前元素且有左孩子时*/
	if(X<T->Element && T->Left)
		return Find(X, T->Left);
	/*X大于当前元素且有右孩子时*/
	else if(X >T->Element && T->Right)
		return Find(X, T->Right);
	/*X等于当前元素，或者没找到该元素，又没有左右孩子时*/
	else
		return T;
}

/*找到最小值之后将该值变为根节点*/
SplayTree FindMin(SplayTree T)
{
	Position np = T;
	if(T!=NULL)
	{
		while(np->Left !=NULL)
			np = np->Left;

		return Splay(np, T);
	}
	return NULL;
}

/*找到最大值之后将该值变为根节点*/
SplayTree FindMax(SplayTree T)
{
	Position np = T;
	if(T!=NULL)
	{
		while(np->Right !=NULL)
			np = np->Right;

		return Splay(np, T);
	}
	return NULL;
}

SplayTree makeEmpty(SplayTree T)
{
	if(T != NULL)
	{
		makeEmpty(T->Left);
		makeEmpty(T->Right);
		free(T);
	}

	return NULL;
}


SplayTree RightSingleRotate(SplayTree T)
{
	SplayTree k1, parent;

	parent = T ->Parent;
	k1 = T->Left;

	k1->Parent = parent;

	/*连接k1的右子树*/
	if(k1->Right)
		k1->Right->Parent = T;
	T->Left = k1->Right;

	/*调换k1和T的位置*/
	T->Parent = k1;
	k1->Right = T;

	/*连接上一个节点*/
	if(parent)
	{
		if(parent->Left ==T)
			parent->Left = k1;
		else
			parent->Right = k1;
	}

	return k1;
}

SplayTree LeftSingleRotate(SplayTree k1)
{
	SplayTree k2, parent;

	parent = k1 ->Parent;
	k2 = k1->Right;

	k2->Parent = parent;

	/*连接k2的左子树*/
	if(k2->Left)
		k2->Left->Parent = k1;
	k1->Right = k2->Left;

	/*调换k1和T的位置*/
	k1->Parent = k2;
	k2->Left = k1;

	/*连接上一个节点*/
	if(parent)
	{
		if(parent->Left ==k1)
			parent->Left = k2;
		else
			parent->Right = k2;
	}

	return k2;
}

SplayTree RightDoubleRotate(SplayTree k3)
{
	LeftSingleRotate(k3->Left);
	return RightSingleRotate(k3);
}

SplayTree LeftDoubleRotate(SplayTree k1)
{
	RightSingleRotate(k1->Right);
	return LeftSingleRotate(k1);
}

SplayTree Splay(Position np, SplayTree T)
{
	Position P,G;
	P = np->Parent;
	
	while(P != NULL)
	{
		G = P->Parent;
		/*X是父亲的左节点*/
		if(np == P->Left)
		{
			/*X的父亲节点为根节点*/
			if(G == NULL)
				RightSingleRotate(P);
			/*zigzig形状*/
			else if(G->Left == P)
			{
				RightSingleRotate(G);
				/*第一次旋转完成之后，P变成了G的父节点*/
				RightSingleRotate(P);
			}
			/*zagzig形状*/
			else
				LeftDoubleRotate(G);
		}
		/*/*X是父亲的右节点*/
		else
		{
			/*X的父亲节点为根节点*/
			if(G == NULL)
				LeftSingleRotate(P);
			/*zagzag形状*/
			else if(G->Right == P)
			{
				LeftSingleRotate(G);
				/*第一次旋转完成之后，P变成了G的父节点*/
				LeftSingleRotate(P);
			}
			/*zagzig形状*/
			else
				RightDoubleRotate(G);
		}
		
		P= np->Parent;
	}/*while*/

	/*此时np已经变成根节点*/
	return np;
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

void PrintTree(SplayTree T, int depth)
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

void PrintTree(SplayTree T)
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