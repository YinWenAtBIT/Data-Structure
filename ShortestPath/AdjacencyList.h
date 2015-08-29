/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/28
description:使用邻接表实现图的数据结构
			使用了开放定址的哈希表
********************************************/


#include "HashTableOpenAdd.h"
#define Infinity 0x7fffffff

#ifndef _ADJACENCY_LIST
#define _ADJACENCY_LIST


struct TableNode;
typedef TableNode* Table;
typedef int* Indegree;
typedef HashTable Graph;


/*初始化图，输入顶点数，所有顶点边置零*/
Graph intializeGraph(int VertexNum);

/*插入边，使用名字插入，如果顶点不存在会先插入顶点*/
void insertEdge(VertexType vertex1, VertexType vertex2, WeightType weight, Graph G);

/*使用顶点序号插入边，顶点应该已经存在于图中*/
void insertEdgeWithIndex(Index P1, Index P2, WeightType weight, Graph G);

/*插入顶点，使用顶点名字*/
void insertVertex(VertexType vertex, Graph G);

/*寻找顶点序号，返回的顶点序号不一定代表顶点存在，需要自行判断Info信息*/
Position findVertex(VertexType vertex, Graph G);

/*删除边，使用顶点的名字，如果变不存在删除终止*/
void removeEdge(VertexType vertex1, VertexType vertex2, Graph G);

/*使用顶点序号删除边，不存在则删除终止*/
void removeEdgeWithIndex(Index P1, Index P2, Graph G);

/*销毁图*/
void  DestroyGraph(Graph G);

/*打印图*/
void PrintGraph(Graph G);

/*获取入度组*/
Indegree getIndegree(Graph G);

/*打印入度组*/
void PrintIndegree(Indegree D, Graph G);

/*拓扑排序，需要输入已经初始化好的入度组*/
int* TopSort(Graph G, Indegree D);

/*打印拓扑排序结果，使用排序完成的数组*/
void PrintTopSort(int * TopNum, Graph G);

/*无权最短路径*/
Table UnweightedShortestPath(VertexType vertex, Graph G);

/*打印带权路径，路径保存在路径表T中*/
void PrintWeighted(Table T, Graph G);

/*单源点有权最短路径算法，返回带去路径表T*/
Table Dijkstra(VertexType vertex, Graph G);

/*带有负权值的单源点有权最短路径算法，返回带去路径表T，没有对负圈进行处理，遇到负圈无法跳出*/
Table WeightedNegative(VertexType vertex, Graph G);

/*网络最大流算法，输入顶点名字，返回Gf图*/
Graph maxStream(VertexType source, VertexType sink, Graph G);



struct TableNode
{
	bool known;
	int dist;
	Index path;
};


#endif 