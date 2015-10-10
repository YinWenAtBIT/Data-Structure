/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/10
description:≈‰∂‘∂—
********************************************/

#include "PairingHeap.h"
#include <cstdlib>
#include <iostream>

PairHeap CompareAndLink(PairHeap H1, PairHeap H2)
{
	if(H2 == NULL)
		return H1;
	else if(H1 ->Element <= H2->Element)
	{
		H2->Prev = H1;
		H1->NextSibling = H2->NextSibling;
		if(H1->NextSibling != NULL)
			H1->NextSibling->Prev = H1;

		H2->NextSibling = H1->Left;
		if(H2->NextSibling != NULL)
			H2->NextSibling->Prev = H2;

		H1->Left = H2;
		return H1;
	}
	else
	{
		H2->Prev = H1->Prev;
		H1->Prev = H2;
		H1->NextSibling = H2->Left;

		if(H1->NextSibling != NULL)
			H1->NextSibling->Prev = H1;
		H2->Left = H1;
		return H2;
	}

}

ElementType findMin(PairHeap H)
{
	return H->Element;
}

int isEmpty(PairHeap H)
{
	return H == NULL;
}

PairHeap deleteMin(ElementType * Min, PairHeap H)
{
	if(H == NULL)
		return H;

	PairHeap NewRoot;
	*Min = H->Element;
	if(H->Left != NULL)
		NewRoot = CombineSiblings(H->Left);
	free(H);

	return NewRoot;
}

PairHeap insert(ElementType X, PairHeap H, Position * Loc)
{
	PairHeap NewNode;
	NewNode = (PairHeap)malloc(sizeof(struct PairNode));
	if(NewNode == NULL)
		exit(1);

	NewNode->Element = X;
	NewNode->Left = NewNode->NextSibling = NewNode ->Prev = NULL;

	*Loc = NewNode;
	if(H == NULL)
		return NewNode;

	return CompareAndLink(H, NewNode);
}



PairHeap DecreaseKey(Position P, ElementType Delta, PairHeap H)
{
	if(Delta < 0)
		return H;
	P->Element -= Delta;

	if(P == H)
		return H;
	
	if(P->NextSibling != NULL)
		P->NextSibling->Prev = P->Prev;

	if(P->Prev->Left == P)
		P->Prev ->Left = P->NextSibling;
	else
		P->Prev->NextSibling = P->NextSibling;

	P->NextSibling = NULL;
	return CompareAndLink(H, P);
}

PairHeap CombineSiblings(Position FirstSibling)
{
	static Position TreeArray[100];
	int i, j, Num;

	if(FirstSibling == NULL)
		return FirstSibling;

	for(Num =0; FirstSibling != NULL; Num++)
	{
		TreeArray[Num] = FirstSibling;
		FirstSibling->Prev->NextSibling = NULL;
		FirstSibling = FirstSibling->NextSibling;
	}

	TreeArray[Num] = NULL;

	for(i =0; i+1<Num; i +=2)
		TreeArray[i] = CompareAndLink(TreeArray[i], TreeArray[i+1]);


	j =i-2;
	if(j == Num -3)
		TreeArray[j] = CompareAndLink(TreeArray[j], TreeArray[j+2]);

	for(; j>=2; j-=2)
		TreeArray[j-2] = CompareAndLink(TreeArray[j-2], TreeArray[j]);

	

	return TreeArray[0];
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

void PrintTree(PairHeap T, int depth)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->Left != NULL)
		PrintTree(T->Left, depth+1);

	PrintDepth(T->Element, depth);
	if(T->NextSibling !=NULL)
		PrintTree(T->NextSibling, depth);
}

void PrintTree(PairHeap T)
{
	if(T == NULL)
	{
		perror("wrong tree");
		exit(1);
	}
	if(T->Left != NULL)
		PrintTree(T->Left);

	printf("%d\n",T->Element);
	if(T->NextSibling !=NULL)
		PrintTree(T->NextSibling);
}