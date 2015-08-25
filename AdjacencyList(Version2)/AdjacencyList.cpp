/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/23
description:使用邻接表实现图的数据结构
			使用了开放定址的哈希表
********************************************/

#include "AdjacencyList.h"
#include <cstdlib>
#include <iostream>
#include "queue.h"

/*初始化图*/
Graph intializeGraph(int VertexNum)
{
	return initializeTable(VertexNum);
}

/*插入顶点，直接调用哈希表的插入键值*/
void insertVertex(VertexType vertex, Graph G)
{
	insertKey(vertex, G);
	G->vertex++;
}

/*插入边，需要先进行判断边的两个顶点是否存在，不存在则先插入顶点*/
void insertEdge(VertexType vertex1, VertexType vertex2, WeightType weight, Graph G)
{
	Position P1, P2;
	P1 = FindKey(vertex1, G);
	P2 = FindKey(vertex2, G);
	
	if(G->TheCells[P2].Info != Legitimate)
		insertVertex(vertex2, G);
	if(G->TheCells[P1].Info != Legitimate)
		insertVertex(vertex1, G);
	
	/*加入新的边*/
	Edge newEdge = (Edge)malloc(sizeof(EdgeNode));
	newEdge->vertexIndex = P2;
	newEdge->weight = weight;
	newEdge->next = G->TheCells[P1].next;
	G->TheCells[P1].next = newEdge;
	/*边数加一*/
	G->edge++;
}

/*寻找顶点索引*/
Position findVertex(VertexType vertex, Graph G)
{
	return FindKey(vertex, G);
}


/*移除边，先确认顶点存在*/
void removeEdge(VertexType vertex1, VertexType vertex2, Graph G)
{
	Position P1, P2;
	P1 = FindKey(vertex1, G);
	P2 = FindKey(vertex2, G);
	
	if(G->TheCells[P2].Info != Legitimate && G->TheCells[P1].Info == Legitimate)
	{
		fprintf(stderr, "Edge not exist\n");
		return;
	}

	VertexNode * V = &G->TheCells[P1];

	Edge parent = V->next;

	/*判断该边是否是第一条边*/
	if(parent->vertexIndex == P2)
	{
		V->next = parent->next;
		free(parent);
	}
	else
	{
		Edge temp;

		while(parent->next->vertexIndex != P2)
			parent = parent->next;

		temp = parent->next;
		parent->next = temp->next;
		free(temp);
	}
}

/*删除边*/
void DestroyEdge(Edge E)
{
	Edge temp;	
	while(E != NULL)
	{
		temp = E->next;
		free(E);
		E = temp;
	}
}

/*删除图，需要先删除边，再调用删除哈希表*/
void  DestroyGraph(Graph G)
{
	for(int i =0; i<G->TableSize; i++)
		if(G->TheCells[i].Info == Legitimate &&G->TheCells[i].next != NULL)
			DestroyEdge(G->TheCells[i].next);

	DestroyTable(G);
}




/*获取入度组*/
Indegree getIndegree(Graph G)
{
	int num = G->vertex;
	Indegree indegree;
	int count=0;

	indegree = (Indegree)calloc(num, sizeof(int));
	for(int i=0; i<G->TableSize; i++)
	{
		if(G->TheCells[i].Info == Legitimate)
		{
			Edge edge = G->TheCells[i].next;
			while(edge != NULL)
			{
				indegree[edge->vertexIndex]++;
				edge = edge->next;
			}
		}
	}
	return indegree;
}


/*拓扑排序*/
int* TopSort(Graph G, Indegree D)
{
	Queue Q;
	Q = createQueue();
	int num = G->vertex;
	int * TopNum = (int *)calloc(G->vertex, sizeof(int));


	if(TopNum == NULL)
	{
		fprintf(stderr, "not enough memory\n");
		exit(1);
	}

	for(int i=0; i<num; i++)
	{
		if(D[i] == 0)
			enqueue(i, Q);
	}



	int count =0;
	Index V;

	while(!isEmpty(Q))
	{
		 V = dequeue(Q);
		 TopNum[count++] = V;

		 Edge edge = G->TheCells[V].next;
		 while(edge != NULL)
		 {
			 if( --D[edge->vertexIndex] == 0)
				 enqueue(edge->vertexIndex, Q);
			 edge = edge->next;
		 }
	}

	/*删除队列*/
	disposeQueue(Q);

	if(count != num)
	{
		fprintf(stderr,"Graph has a cycle\n");
		free(TopNum);
		return NULL;
	}
	return TopNum;
}

/*打印入度组*/
void PrintIndegree(Indegree D, Graph G)
{
	int total = G->vertex;

	Index P;
	for(int i=0; i<total; i++)
	{
		printf("%s indegree:  ", G->TheCells[i].vertexName);
		printf("%d\n",D[i]);
	}
}



/*打印边*/
void PrintEdge(VertexNode * V, Graph G)
{
	Edge edgeNext;
	edgeNext = V->next;
	while(edgeNext != NULL)
	{
		printf("Edge: %s -->  ", V->vertexName);
		Index P2 = edgeNext->vertexIndex;
		printf("%s  ",G->TheCells[P2].vertexName);
		printf("weight: %d\n",edgeNext->weight);
		edgeNext = edgeNext->next;
	}
}

/*打印图*/
void PrintGraph(Graph G)
{
	for(int i =0; i<G->TableSize; i++)
		if(G->TheCells[i].Info == Legitimate)
			PrintEdge(&G->TheCells[i], G);
}

void PrintTopSort(int * TopNum, Graph G)
{
	int num = G->vertex;
	Index P;

	printf("TopSort :\n");
	for(int i=0; i<num; i++)
	{
		P = TopNum[i];
		printf("%s  ",G->TheCells[P].vertexName);	
	}
	printf("\n");
}

