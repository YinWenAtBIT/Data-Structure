/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/10
description:配对堆
********************************************/

#include "PairingHeap.h"
#include <stdlib.h>
#include <iostream>

int main()
{
	int i;
	PairHeap One;
	One = NULL;

	Position Location;

	/*插入数据，先插入10，再分别按偶数奇数插入0-20*/
	insert(10, One, &Location);

	for(i = 0; i<10; i++)
	{
		One = insert(2*i, One, &Location);
	}

	for(i = 0; i<10; i++)
	{
		One = insert(2*i+1, One, &Location);
	}
	/*打印出树，每一级深度加一个4个空格，先打印左子树再打印右子数*/
	PrintTree(One,0);

	
	printf("\n\n\n\n");


	DecreaseKey(Location, 3,  One);
	PrintTree(One,0);
	printf("\n\n\n\n");

	/*删除元素之后的树*/
	int Min;
	One = deleteMin(& Min, One);

	PrintTree(One,0);






	std::cout<<std::endl;
}