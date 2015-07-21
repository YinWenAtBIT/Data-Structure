#ifndef _STACK_H
#define _STACK_H

struct Node;
typedef Node * PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;



int isEmpty(Stack S);
Stack createStack(void);
void disposeStack(Stack S);
void makeEmpty(Stack S);
void push(ElementType X, Stack S);
ElementType pop(Stack S);

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

#endif

