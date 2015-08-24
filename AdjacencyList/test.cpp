/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/30
description:哈希表(开放定址法)测试文件
********************************************/
#include "AdjacencyList.h"
#include "HashTableOpenAdd.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	Graph One = intializeGraph(15);

	char vertex1[20];
	char vertex2[20];
	int weight;
	while(1)
	{
		printf("please input the Edge, v0 v1 weight, quit to end\n");
		gets(vertex1);
		if(strcmp(vertex1, "quit") == 0)
			break;

		gets(vertex2);
		scanf("%d", &weight);
		getchar();
		insertEdge(vertex1, vertex2, weight, One);

	}
	PrintGraph(One);
	printf("\n");

	Indegree Degre = getIndegree(One);
	PrintIndegree(Degre,One, One->vertex);

	int* Top = TopSort(One, Degre);
	PrintTopSort(Top, One);

	printf("\n");

}