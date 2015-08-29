/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/28
description:最大网络流算法，使用了广度优先遍历
			来确定增广路径，实际上是修改了无权
			最短路径算法
********************************************/
#include "AdjacencyList.h"
#include <cstdlib>
#include "queue.h"
#include <iostream>

#define MIN(x,y) ((x)<(y)?(x):(y))

Graph copyGraph(Graph D, Graph S);
void copyVertex(Graph D, Graph S);
void maxStream(Index S, Index E, Graph Gf, Graph Gr);
void modifyGraphByIncrem(Index E, Table T, Graph Gf, Graph Gr);
void getShortestIncrePath(Index S, Table T, Graph G);
void modifyWeightGr(Index V, Index W, WeightType weight, Graph Gr);
void modifyWeightGf(Index V, Index W, WeightType weight, Graph Gf);
void decreaseWeight(Index V, Index W, WeightType weight, Graph Gr);
void increaseWeight(Index V, Index W, WeightType weight, Graph Gr);
bool isEdgeExist(Index V, Index W, Graph G);

/*最短无权路径,初始化路径表*/
void initTable(Index V, int num, Table T)
{
	for(int i=0; i<num; i++)
	{
		T[i].known = false;
		T[i].dist = Infinity;
		T[i].path = -1;
	}
	T[V].dist = 0;
}

Graph maxStream(VertexType source, VertexType sink, Graph G)
{
	Index S = findVertex(source, G);
	Index E = findVertex(sink, G);
	if(G->TheCells[S].Info != Legitimate || G->TheCells[E].Info != Legitimate)
	{
		fprintf(stderr, "vertex %s or %s does not exist", source, sink);
		return NULL;
	}
	/*准备好残余图和流图*/
	Graph Gr = intializeGraph(G->vertex);
	Gr = copyGraph(Gr, G);
	Graph Gf = intializeGraph(G->vertex);
	copyVertex(Gf, G);

	
	maxStream(S, E, Gf, Gr);
	DestroyGraph(Gr);

	return Gf;
}






Graph copyGraph(Graph D, Graph S)
{
	if(S->vertex != D->vertex)
	{
		DestroyGraph(D);
		D = intializeGraph(S->vertex);
	}

	/*必须先对每一个顶点赋值，因为图的顶点排列是通过
	开放定址法的哈希表，插入顺序不同会导致顶点的序号不同*/
	copyVertex(D, S);

	VertexType vertex1, vertex2;
	WeightType weight;
	for(int i=0; i<S->vertex; i++)
	{
		strcpy(vertex1, S->TheCells[i].vertexName);
		Edge edge = S->TheCells[i].next;
		while(edge != NULL)
		{
			weight = edge->weight;
			strcpy(vertex2, S->TheCells[edge->vertexIndex].vertexName);
			insertEdge(vertex1, vertex2, weight, D);
			edge = edge ->next;
		}
	}
	return D;
}


void copyVertex(Graph D, Graph S)
{
	D->vertex = S->vertex;
	for(int i=0; i<S->vertex; i++)
	{
		D->TheCells[i].Info = S->TheCells[i].Info;
		D->TheCells[i].vertexIndex = S->TheCells[i].vertexIndex;
		strcpy(D->TheCells[i].vertexName, S->TheCells[i].vertexName);
	}
}


void maxStream(Index S, Index E, Graph Gf, Graph Gr)
{
	/*生成列表*/
	Table T = (Table)calloc(Gr->vertex, sizeof(TableNode));
	if(T == NULL)
	{
		fprintf(stderr, "not enough memory");
		return;
	}
	/*初始化表，并且计算第一条增广路径*/
	initTable(S, Gr->vertex, T);
	getShortestIncrePath(S, T, Gr);
	/*运算直到没有增广路径*/
	while(T[E].dist != Infinity)
	{
		modifyGraphByIncrem(E, T, Gf, Gr);
		initTable(S, Gr->vertex, T);
		getShortestIncrePath(S, T, Gr);
	}
}



/*最短增广路径,计算路径*/
void getShortestIncrePath(Index S, Table T, Graph G)
{
	Queue Q = createQueue();
	enqueue(S, Q);

	/*初始化入度路径计算表时，发出节点被置0，
	我们在这里的目的是计算路径最小流*/
	T[S].dist = Infinity;

	Index V,W;


	while(!isEmpty(Q))
	{
		V = dequeue(Q);
		T[V].known = true;

		Edge edge = G->TheCells[V].next;
		while(edge !=NULL)
		{
			W = edge->vertexIndex;
			if(T[W].known == false)
			{
				T[W].dist = MIN(T[V].dist, edge->weight);
				T[W].path = V;
				enqueue(W,Q);
			}
			edge = edge->next;
		}
	}
	disposeQueue(Q);
}

void modifyGraphByIncrem(Index E, Table T, Graph Gf, Graph Gr)
{
	WeightType increment = T[E].dist;
	
	Index V,W;
	W = E;
	V = T[W].path;
	/*根据路径，修改Gr与Gf图*/
	while(V != -1)
	{
		modifyWeightGr(V, W, increment, Gr);
		modifyWeightGf(V, W, increment, Gf);
		W = V;
		V = T[V].path;
	}
}


void modifyWeightGr(Index V, Index W, WeightType weight, Graph Gr)
{
	/*Gr图中，先减去从V->W路径上权值weight,
	如果减去后权值为0，则删去这条边*/
	decreaseWeight(V, W, weight, Gr);

	/*然后在W->V这条路径上增加权值weight,
	如果边不存在，则添加这条边*/
	increaseWeight(W, V, weight, Gr);
}

void modifyWeightGf(Index V, Index W, WeightType weight, Graph Gf)
{
	/*先判断相反方向的边是否存在，如果存在,
	则在相反路径上减去权值weight,如果不存在则在该路径上增加权值*/
	if(isEdgeExist(W, V, Gf))
		decreaseWeight(W, V, weight, Gf);
	else
		increaseWeight(V, W, weight, Gf);
}


void decreaseWeight(Index V, Index W, WeightType weight, Graph Gr)
{
	Edge edge= Gr->TheCells[V].next;
	while(edge!= NULL && edge->vertexIndex != W)
		edge = edge->next;

	if(edge == NULL)
	{
		fprintf(stderr, "edge %s to %s not exist", Gr->TheCells[V].vertexName, Gr->TheCells[W].vertexName);
		return;
	}
	edge->weight -= weight;
	/*路径上的剩余流量为0时删去路径*/
	if(edge->weight  == 0)
		removeEdgeWithIndex(V, W, Gr);
}

void increaseWeight(Index V, Index W, WeightType weight, Graph Gr)
{
	Edge edge= Gr->TheCells[V].next;
	while(edge!= NULL && edge->vertexIndex != W)
		edge = edge->next;
	/*如果原边不存在则添加边*/
	if(edge == NULL)
	{
		insertEdgeWithIndex(V, W, weight, Gr);
	}
	else
		edge->weight += weight;
}

bool isEdgeExist(Index V, Index W, Graph G)
{
	Edge edge= G->TheCells[V].next;
	while(edge!= NULL && edge->vertexIndex != W)
		edge = edge->next;

	if(edge != NULL)
		return true;
	else
		return false;
}