#include "list.h"

int isEmpty(List L)
{
	return L->Next ==NULL;
}

int isLast(Position P)
{
	return P->Next ==NULL;
}

Position find(ElementType X, List L)
{
	Position P = L->Next;
	while(P !=NULL && P->Element !=X)
		P = P->Next;

	return P;
}

void Delete(ElementType X, List L)
{
	Position P, temp;
	P = findPrevious(X, L);

	if(!isLast(P,L))
	{
		temp = P->Next;

		P->Next = temp->Next;
		delete P;
	}
}

Position findPrevious(ElementType X, List L)
{
	Position P = L->Next;

	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}

void insert(ElementType X, Position P)
{
	Position temp;
	temp = new struct Node;
	if(temp !=NULL)
	{
		temp->Element = X;
		temp->Next = P->Next;
		P->Next = temp;
	}
	perror("Not enough memory");
}

void deleteList(List L)
{
	Position P = L->Next;
	Position temp;
	L->Next = NULL;

	while(P !=NULL)
	{
		temp = P->Next;
		delete P;
		P = temp;
	}
}