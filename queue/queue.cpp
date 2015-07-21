#include "queue.h"
#include <stdlib.h>

int isEmpty(Queue Q)
{
	return Q->front ==NULL;
}

Queue createQueue(void)
{
	Queue Q;
	Q = new QueueRecord;
	if(Q ==NULL)
	{
		perror("Not Enough Memory");
		return NULL;
	}
	Q->rear = NULL;
	Q->front = NULL;
	return Q;
}

void enqueue(ElementType X, Queue Q)
{
	struct Node * temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	if(temp ==NULL)
	{
		perror("Not Enough Memory");
		return;
	}
	temp->Element = X;
	temp->Next = NULL;
	if(Q->rear ==NULL)
	{
		Q->rear = Q->front = temp;
	}
	else
	{
		Q->rear->Next = temp;
		Q->rear = temp;
	}
}

ElementType dequeue(Queue Q)
{
	if(isEmpty(Q))
	{
		perror("Queue is empty");
		return 0;
	}
	ElementType temp;
	struct Node *P;
	temp = Q->front->Element;
	P = Q->front;
	Q->front = P->Next;
	free(P);
	if(Q->front ==NULL)
	{
		Q->rear = NULL;
	}
	return temp;
}