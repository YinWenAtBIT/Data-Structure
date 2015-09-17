#include <stdlib.h>
#ifndef _list_h
#define _list_h


struct ListNode;
typedef int ElementType;
typedef struct ListNode * PtrToNode;
typedef PtrToNode List;
struct ListHead;

List makeEmpty(List L);
int isEmpty(List L);
int isLast(List P, List L);
List find(ElementType X, List L);
void Delete(ElementType X, List L);
List findPrevious(ElementType X, List L);

void insert(ElementType X, List P);


void deleteList(List L);
List Header(List L);
List First(List L);
List Advance(List L);
ElementType retrieve(List P);


struct ListNode
{
	ElementType Element;
	struct ListNode * Next;
};



#endif