/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/9
description:AAÊ÷
********************************************/

#include "AATree.h"
#include <cstdlib>
#include <iostream>


static AATree NullNode = NULL;


/*ÓÒÐý×ª*/
AATree rightSingleRotate(AATree T)
{
	AATree k1;

	k1 = T->left;
	T->left = k1->right;
	k1->right = T;
	return k1;
}
/*×óÐý×ª*/
AATree leftSingleRotate(AATree k1)
{
	Position k2;

	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	return k2;
}




AATree initialize()
{
	if(NullNode == NULL)
	{
		NullNode = (AATree)malloc(sizeof(struct AANode));
		if(NullNode == NULL)
			exit(1);

		NullNode ->left = NullNode->right = NullNode;
		NullNode ->level = 0;
	}
	return NullNode;
}



AATree skew(AATree T)
{
	if(T->level == T->left->level)
		T = rightSingleRotate(T);
	return T;
}


AATree split(AATree T)
{
	if(T->right->right->level == T->level)
	{
		T = leftSingleRotate(T);
		T->level++;
	}
	return T;
}


AATree insert(ElementType item, AATree T)
{
	if(T == NullNode)
	{
		T = (AATree)malloc(sizeof(struct AANode));
		if(T == NULL)
			exit(1);

		T->Element = item;
		T->level  = 1;
		T->left = T->right = NullNode;

		return T;
	}
	else if(item < T->Element)
		T->left = insert(item, T->left);
	else if(item> T->Element)
		T->right = insert(item, T->right);

	T = skew(T);
	T = split(T);
	return T;
}



AATree remove(ElementType item, AATree T)
{
	static Position DeletePtr, LastPtr;
	if(T != NullNode)
	{
		LastPtr = T;
		if(item < T->Element)
			T->left = remove(item, T->left);
		else
		{
			DeletePtr = T;
			T->right = remove(item, T->right);
		}

		if(T == LastPtr)
		{
			if(DeletePtr != NullNode && item == DeletePtr ->Element)
			{
				DeletePtr->Element = T->Element;
				DeletePtr = NullNode;
				T = T->right;
				free(LastPtr);
			}
		}

		else
		{
			if(T->left->level < T->level -1 || T->right ->level < T->level -1)
			{
				if(T->right->level > -- T->level)
					T->right->level = T->level;

				T= skew(T);
				T->right = skew(T->right);
				T->right->right = skew(T->right->right);
				T = split(T);
				T->right = split(T->right);
			}
		}
	}

	return T;
}


/*´òÓ¡Ê÷*/
void PrintTree(AATree T, int K)
{
	if(T != NullNode)
	{
		PrintTree(T->left, K);
		int num = K- T->level;
		for(int i=0; i< num; i++)
			printf("    ");

		printf("%d\n", T->Element);

		PrintTree(T->right, K);
	}
}