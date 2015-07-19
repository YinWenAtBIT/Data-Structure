#include <stdlib.h>
#ifndef _list_h
#define _list_h


struct Node;
typedef int ElementType;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List makeEmpty(List L);
int isEmpty(List L);
int isLast(Position P, List L);
Position find(ElementType X, List L);
void Delete(ElementType X, List L);
Position findPrevious(ElementType X, List L);
void insert(ElementType X, Position P, List L);
void deleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(List L);
ElementType retrieve(Position P);





struct Node
{
	ElementType Element;
	struct Node * Next;
};


#endif