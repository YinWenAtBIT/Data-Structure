#include "list.h"

int isEmpty(List L)
{
	return L ==NULL;
}

int isLast(List P)
{
	return P->Next ==NULL;
}

List find(ElementType X, List L)
{
	if(L == NULL)
		return NULL;
	List P = L;
	while(P !=NULL && P->Element !=X)
		P = P->Next;

	return P;
}

void Delete(ElementType X, List L)
{
	List P, temp;
	P = findPrevious(X, L);

	if(!isLast(P))
	{
		temp = P->Next;

		P->Next = temp->Next;
		delete temp;
	}
}

List findPrevious(ElementType X, List L)
{
	List P = L;

	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}



void insert(ElementType X, List P)
{
	List temp;
	temp = (List)malloc(sizeof(struct ListNode));
	if(temp !=NULL)
	{
		temp->Element = X;
		temp->Next = P->Next;
		P->Next = temp;
	}
	else
		perror("Not enough memory");
}

void deleteList(List L)
{
	List P = L;
	List temp;


	while(P !=NULL)
	{
		temp = P->Next;
		free (P);
		P = temp;
	}
}

List makeEmpty(List L)
{
	if(L == NULL)
		return L;

	List temp;
	while(L != NULL)
	{
		temp = L;
		L = L->Next;
		free(temp);
	}
	return NULL;
}
