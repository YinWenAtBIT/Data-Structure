/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/10
description:TreapÊ÷
********************************************/
#include "Treap.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

static TreapTree NullNode = NULL;


/*ÓÒÐý×ª*/
TreapTree rightSingleRotate(TreapTree T)
{
	TreapTree k1;

	k1 = T->left;
	T->left = k1->right;
	k1->right = T;
	return k1;
}
/*×óÐý×ª*/
TreapTree leftSingleRotate(TreapTree k1)
{
	Position k2;

	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	return k2;
}




TreapTree initialize()
{
	if(NullNode == NULL)
	{
		NullNode = (TreapTree)malloc(sizeof(struct TreapNode));
		if(NullNode == NULL)
			exit(1);

		NullNode ->left = NullNode->right = NullNode;
		NullNode ->Priority = Infinity;
	}
	srand(time(0));
	return NullNode;
}



TreapTree insert(ElementType item, TreapTree T)
{
	if(T == NullNode)
	{
		T = (TreapTree)malloc(sizeof(struct TreapNode));
		if(T == NULL)
			exit(1);

		T->Element = item;
		T->Priority  = rand()%Infinity;
		T->left = T->right = NullNode;

		return T;
	}
	else if(item < T->Element)
	{
		T->left = insert(item, T->left);
		if(T->Priority > T->left->Priority)
			T = rightSingleRotate(T);
	}
	else if(item> T->Element)
	{
		T->right = insert(item, T->right);
		if(T->Priority > T->right->Priority)
			T = leftSingleRotate(T);
	}

	return T;
}



TreapTree remove(ElementType item, TreapTree T)
{
	static Position DeletePtr, LastPtr;
	if(T != NullNode)
	{
		if(item < T->Element)
			T->left = remove(item, T->left);
		else if(item > T->Element)
		{
			T->right = remove(item, T->right);
		}
		else
		{
			if(T->left->Priority < T->right->Priority)
				T = rightSingleRotate(T);
			else 
				T = leftSingleRotate(T);

			if(T != NullNode)
				T = remove(item, T);

			else
			{
				free(T->left);
				T->left = NullNode;
			}
		}
	}

	return T;

}

/*´òÓ¡Ê÷*/
void PrintTree(TreapTree T, int depth)
{
	if(T != NullNode)
	{
		PrintTree(T->left, depth +1);

		for(int i=0; i< depth; i++)
			printf("        ");

		printf("%d, %d\n", T->Element, T->Priority);

		PrintTree(T->right, depth+1);
	}
}