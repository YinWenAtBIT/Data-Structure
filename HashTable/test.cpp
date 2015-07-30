/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/30
description:Hash±í²âÊÔÎÄ¼ş
********************************************/
#include "HashTable.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	HashTable H;
	H = initializeTable(41);

	int i;
	int key;
	Position P;
	////insertKey(1,H);
	//insertKey(2,H);	
	//insertKey(3,H);

	////deleteKey(1,H);
	//deleteKey(2,H);
	//deleteKey(3,H);

	for(i=0; i<100; i++)
	{
		key = i;
		insertKey(key, H);
	}
	deleteKey(100, H);
	for(i=0; i<50; i++)
		deleteKey(2*i, H);

	P = FindKey(21,H);
	printf("%d is found\n",P->Element);

	PrintHashTable(H);
	DestroyTable(H);
	std::cout<<std::endl;
}