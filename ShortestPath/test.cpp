/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/24
description:邻接表测试文件，进行了拓扑排序
********************************************/
#include "AdjacencyList.h"
#include "HashTableOpenAdd.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{

	//printf("please input the Vertex Number\n");

	//int vertexNum;
	//scanf("%d", &vertexNum);
	//Graph One = intializeGraph(vertexNum);

	//char vertex1[20];
	//char vertex2[20];
	//int weight;
	//printf("please input the Edge, v0 v1 weight, v0 = quit to end\n");
	//printf("please input the like: \"v0 v1 1\" :\n");
	//while(1)
	//{

	//	std::cin>>vertex1>>vertex2>>weight;
	//	if(strcmp(vertex1, "quit") == 0)
	//		break;		
	//	insertEdge(vertex1, vertex2, weight, One);
	//}

	Graph One = intializeGraph(7);

	insertEdge("v1", "v2", 2, One);
	insertEdge("v1", "v4", 1, One);
	insertEdge("v2", "v4", 3, One);
	insertEdge("v2", "v5", 10, One);
	insertEdge("v3", "v1", 4, One);
	insertEdge("v3", "v6", 5, One);
	insertEdge("v4", "v3", 2, One);
	insertEdge("v4", "v6", 8, One);
	insertEdge("v4", "v7", 4, One);
	insertEdge("v4", "v5", 2, One);
	insertEdge("v5", "v7", 6, One);
	insertEdge("v7", "v6", 1, One);

	PrintGraph(One);
	printf("\n");

	Indegree Degre = getIndegree(One);
	PrintIndegree(Degre,One);

	printf("\n");
	int* Top = TopSort(One, Degre);
	PrintTopSort(Top, One);

	printf("\n");

	char vertex1[20];

	printf("please input the start vertex: ");
	std::cin>>vertex1;
	Table T = UnweightedShortestPath(vertex1, One);
	printf("\n");
	printf("The shortest pathes are:\n");
	PrintWeighted(T, One);

	free(T);
	Table T2 = Dijkstra(vertex1,  One);

	printf("\n");
	printf("The Dijkstra pathes are:\n");	
	PrintWeighted(T2, One);

	free(T2);
	printf("\n");
}