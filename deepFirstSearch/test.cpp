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


void printList(List Head, Graph G);

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

	Graph Two = intializeGraph(7);
		
	insertEdgeNoDirect("A", "B", 2, Two);
	insertEdgeNoDirect("A", "D", 1, Two);
	insertEdgeNoDirect("B", "C", 3, Two);
	insertEdgeNoDirect("C", "D", 10, Two);
	insertEdgeNoDirect("C", "G", 4, Two);
	insertEdgeNoDirect("D", "E", 5, Two);
	insertEdgeNoDirect("D", "F", 2, Two);
	insertEdgeNoDirect("E", "F", 2, Two);



	FindArticulation("A", Two);
	DestroyGraph(Two);

	Graph Three = intializeGraph(12);

	insertEdgeNoDirect("1", "3", 2, Three);
	insertEdgeNoDirect("1", "4", 1, Three);
	insertEdgeNoDirect("2", "3", 3, Three);
	insertEdgeNoDirect("2", "8", 10, Three);
	insertEdgeNoDirect("3", "6", 4, Three);
	insertEdgeNoDirect("3", "9", 5, Three);
	insertEdgeNoDirect("3", "7", 2, Three);
	insertEdgeNoDirect("3", "4", 2, Three);
	insertEdgeNoDirect("4", "7", 2, Three);
	insertEdgeNoDirect("4", "10", 1, Three);
	insertEdgeNoDirect("4", "11", 3, Three);
	insertEdgeNoDirect("4", "5", 10, Three);
	insertEdgeNoDirect("5", "10", 4, Three);
	insertEdgeNoDirect("6", "9", 5, Three);
	insertEdgeNoDirect("7", "9", 2, Three);
	insertEdgeNoDirect("7", "10", 2, Three);
	insertEdgeNoDirect("8", "9", 2, Three);
	insertEdgeNoDirect("9", "12", 1, Three);
	insertEdgeNoDirect("9", "10", 3, Three);
	insertEdgeNoDirect("10", "12", 10, Three);
	insertEdgeNoDirect("10", "11", 4, Three);
	

	List head = eulerCircuit("5", Three);

	printf("\n\n");
	printList(head, Three);


	PrintGraph(Three);
	DestroyGraph(Three);
	makeEmpty(head->Next);
	free(head);

	printf("\n\n");

	Graph Four = intializeGraph(3);

	insertEdgeNoDirect("1", "2", 2, Four);
	insertEdgeNoDirect("2", "3", 1, Four);
	insertEdgeNoDirect("3", "1", 3, Four);

	head = eulerCircuit("1", Four);
	printList(head, Four);
}


void printList(List Head, Graph G)
{
	if(Head == NULL)
		return;

	List Node = Head->Next;
	while(Node != NULL)
	{
		if(Node->Next != NULL)
			printf("%s  to  ",G->TheCells[Node->Element].vertexName);
		else
			printf("%s\n",G->TheCells[Node->Element].vertexName);
		Node = Node->Next;
	}
}