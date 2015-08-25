/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/23
description:使用邻接表实现图的数据结构
			使用了开放定址的哈希表
********************************************/


#include "HashTableOpenAdd.h"


#ifndef _ADJACENCY_LIST
#define _ADJACENCY_LIST



typedef int* Indegree;
typedef HashTable Graph;




Graph intializeGraph(int VertexNum);
void insertEdge(VertexType vertex1, VertexType vertex2, WeightType weight, Graph G);
void insertVertex(VertexType vertex, Graph G);
Position findVertex(VertexType vertex, Graph G);
void removeEdge(VertexType vertex1, VertexType vertex2, Graph G);
void  DestroyGraph(Graph G);
void PrintGraph(Graph G);
Indegree getIndegree(Graph G);
void PrintIndegree(Indegree D, Graph G);
int* TopSort(Graph G, Indegree D);
void PrintTopSort(int * TopNum, Graph G);




#endif 