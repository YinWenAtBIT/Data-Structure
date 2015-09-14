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


	Graph One = intializeGraph(5);

	insertEdgeNoDirect("A", "B", 2, One);
	insertEdgeNoDirect("A", "D", 1, One);
	insertEdgeNoDirect("A", "E", 3, One);
	insertEdgeNoDirect("B", "D", 10, One);
	insertEdgeNoDirect("B", "C", 4, One);
	insertEdgeNoDirect("D", "C", 5, One);
	insertEdgeNoDirect("C", "E", 2, One);
	
	Table T = deepFirstSearch(One, "A");

	printf("\n");

	PrintTable(T, One);
	printf("\n");

	free(T);
	DestroyGraph(One);

	Graph Two = intializeGraph(8);
		
	insertEdgeNoDirect("A", "B", 2, Two);
	insertEdgeNoDirect("A", "D", 1, Two);
	insertEdgeNoDirect("A", "H", 2, Two);
	insertEdgeNoDirect("B", "C", 3, Two);
	insertEdgeNoDirect("C", "D", 10, Two);
	insertEdgeNoDirect("C", "G", 4, Two);
	insertEdgeNoDirect("D", "E", 5, Two);
	insertEdgeNoDirect("D", "F", 2, Two);
	insertEdgeNoDirect("E", "F", 2, Two);



	FindArticulation("A", Two);
	DestroyGraph(Two);

}