/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/30
description:哈希表(开放定址法)测试文件
********************************************/
#include "HashTableOpenAdd.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	HashTable H;
	H = initializeTable(353);

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
	//deleteKey(100, H);
	//for(i=99; i>=0; i--)
	//	deleteKey(i, H);

	P = FindKey(6,H);
	printf("Index %d is found\n",P);

	PrintHashTable(H);
	DestroyTable(H);
	std::cout<<std::endl;
}