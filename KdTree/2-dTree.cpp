/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/10
description:2-dÊ÷
********************************************/
#include "2-dTree.h"
#include <cstdlib>
#include <iostream>


KdTree insert(ElementType item, KdTree T)
{
	return insert(item, T, 0);
}

KdTree insert(ElementType item, KdTree T, int level)
{
	if(T == NULL)
	{
		T = (KdTree)malloc(sizeof(struct KdNode));
		if(T == NULL)
			exit(1);

		T->Element[0] = item[0];
		T->Element[1] = item[1];
		T->Priority  = rand()%Infinity;
		T->left = T->right = NULL;

		return T;
	}
	else if(item[level] < T->Element[level])
		T->left = insert(item, T->left, !level);
	else 
		T->right = insert(item, T->right);

	return T;
}


/*´òÓ¡·¶Î§*/
void PrintRange(ElementType Low, ElementType High , KdTree T)
{
	RecPrintRange(Low, High , T, 0);
}

static void RecPrintRange(ElementType Low, ElementType High , KdTree T, int level)
{
	if(T != NULL)
	{
		if(Low[0] <= T->Element[0] && High[0] >= T->Element[0] 
			&& Low[1] <= T->Element[1] && High[1] >= T->Element[1])
				printf("%d, %d\n", T->Element[0], T->Element[1]);



		if(Low[level] <= T->Element[level])
			RecPrintRange(Low, High , T->left, !level);

		if(High[level] >= T->Element[level])
			RecPrintRange(Low, High , T->right, !level);
	}
}


/*´òÓ¡Ê÷*/
void PrintTree(KdTree T, int depth)
{
	if(T != NULL)
	{
		PrintTree(T->left, depth +1);

		for(int i=0; i< depth; i++)
			printf("    ");

		printf("%d, %d\n", T->Element[0], T->Element[1]);

		PrintTree(T->right, depth+1);
	}
}