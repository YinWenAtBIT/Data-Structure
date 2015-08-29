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

	Graph One = intializeGraph(6);

	printf("VertexNode size: %d\n", sizeof(VertexNode));

	insertEdge("s", "a", 3, One);
	insertEdge("s", "b", 2, One);
	insertEdge("a", "c", 3, One);
	insertEdge("a", "d", 4, One);
	insertEdge("a", "b", 1, One);
	insertEdge("b", "d", 2, One);
	insertEdge("c", "t", 2, One);
	insertEdge("d", "t", 3, One);

	PrintGraph(One);
	printf("\n");
	printf("\n");


	char vertex1[20];
	char vertex2[20];

	//printf("please input the start vertex: ");
	//std::cin>>vertex1;
	//printf("\n");
	//printf("please input the end vertex: ");
	//std::cin>>vertex2;

	Graph Gf = maxStream("s", "t", One);
	printf("\n");

	printf("The Flow Graph is:\n");
	PrintGraph(Gf);



	printf("\n");
}