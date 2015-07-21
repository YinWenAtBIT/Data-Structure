#include "stack.h"
#include <stdlib.h>

int isEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack createStack(void)
{
	Stack S;
	S = new Node;
	if( S!=NULL)
	{
		S->Next = NULL;
	}
	return S;
}

void disposeStack(Stack S)
{
	while(!isEmpty(S))
		pop(S);
}

void makeEmpty(Stack S)
{
	if(S !=NULL)
	{
		while(!isEmpty(S))
		pop(S);
	}
}

void push(ElementType X, Stack S)
{
	PtrToNode temp;
	temp = new Node;
	if(temp ==NULL)
	{
		perror("Not Enough memory");
		return;
	}
	temp ->Element = X;
	temp->Next= S->Next;
	S->Next = temp;
}

ElementType pop(Stack S)
{
	if(isEmpty(S))
	{
		perror("Stack is empty");
		return 0;
	}
	ElementType temp;
	PtrToNode P;
	P = S->Next;
	temp = P->Element;
	S->Next = P->Next;
	delete P;
	return temp;
}