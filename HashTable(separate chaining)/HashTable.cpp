/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/30
description:Hash表
********************************************/
#include "HashTable.h"
#include <iostream>

int Hash(ElementType Key, int TableSize)
{
	int temp;
	temp = Key*Key/100%100;
	return temp%TableSize;
}

int NextPrime(int TableSize)
{
	/*不求素数，简化编写*/
	return TableSize;
}

/*无头结点，使用calloc给所有指针赋值为0*/
HashTable initializeTable(int TableSize)
{
	HashTable H;
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if( H == NULL)
	{
		fprintf(stderr,"not enough memory");
		exit(1);
	}
	H->TableSize = NextPrime(TableSize);
	H->TheList = (List *)calloc(H->TableSize, sizeof(List));
	if(H->TheList == NULL)
	{
		fprintf(stderr,"not enough memory");
		exit(1);
	}
	return H;
}

void DestroyTable(HashTable H)
{ 
	int i;
	for(i = 0; i<H->TableSize; i++)
		H->TheList[i] = makeEmpty(H->TheList[i]);
	free(H->TheList);
	free(H);
}

Position FindKey(ElementType Key, HashTable H)
{
	Position P;
	List L;
	L = H->TheList[Hash(Key, H->TableSize)];
	P = find(Key, L);
	if(P == NULL)
		fprintf(stderr, "%d do not exist", Key);

	return P;
}

void insertKey(ElementType Key, HashTable H)
{
	Position P;
	List L;

	L = H->TheList[Hash(Key, H->TableSize)];
	/*没有节点*/
	if(L == NULL)
	{
		P = (Position)malloc(sizeof(Node));
		P->Element = Key;
		P->Next = NULL;
		H->TheList[Hash(Key, H->TableSize)] = P;
	}
	else
	{
		P = find(Key, L);
		if(P == NULL)
		{
			P = (Position)malloc(sizeof(Node));
			P->Element = Key;
			P->Next = L;
			H->TheList[Hash(Key, H->TableSize)] = P;

		}
	}
}



void deleteKey(ElementType Key, HashTable H)
{
	List L;
	Position P;
	L = H->TheList[Hash(Key, H->TableSize)];
	P = find(Key, L);
	if(P == NULL)
		fprintf(stderr, "%d do not exist\n", Key);
	else
	{
		/*被删除的元素为第一个*/
		if(L == P)
		{
			H->TheList[Hash(Key, H->TableSize)] = P->Next;
			free(P);
		}
		else
		{
			Position front;
			front = findPrevious(Key, L);
			front->Next = P->Next;
			free(P);
		}
	}
}


void printList(List L);

void PrintHashTable(HashTable H)
{
	int i;
	List L;
	for(i = 0; i<H->TableSize; i++)
	{
		L = H->TheList[i];
		printList(L);
		printf("\n");
	}
}

void printList(List L)
{
	while(L != NULL)
	{
		printf("%d  ",L->Element);
		L = L->Next;
	}
}