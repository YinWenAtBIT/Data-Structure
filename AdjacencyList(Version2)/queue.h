/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/24
description:进行拓扑排序时使用队列
********************************************/
#ifndef _QUEUE_H
#define _QUEUE_H

struct QueueRecord;
struct Node;
typedef struct QueueRecord * PtrToNode;
typedef QueueRecord * Queue;

typedef int ElementType;

int isEmpty(Queue Q);
Queue createQueue(void);
void disposeQueue(Queue Q);
void makeEmpty(Queue Q);
void enqueue(ElementType X, Queue Q);
ElementType dequeue(Queue Q);


struct QueueRecord
{
	struct Node * front;
	struct Node * rear;
};

struct Node 
{
	ElementType Element;
	struct Node * Next;
};

#endif
