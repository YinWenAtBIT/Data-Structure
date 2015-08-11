/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/11
description:二项队列
********************************************/

#include "binomialQueue.h"
#include <stdlib.h>
#include <iostream>

int main()
{
	int i, j;
	BinQueue One;
	One = initialize();

	/*插入数据，先插入10，再分别按偶数奇数插入0-20*/
	insert(10, One);
	insert(0, One);
	insert(1, One);
	for(j = 0; j<10; j++)
	{
		insert(2*j, One);

	}

	for(j = 0; j<10; j++)
	{
		insert(2*j+1, One);

	}

	/*打印出树，每一级深度加一个4个空格，先打印左子树再打印兄弟*/
	for(i =0; i< MaxSize; i ++)
	{
		if(One ->theTrees[i])
		{
			PrintTree(One ->theTrees[i],0);
			printf("\n\n");
		}

	}



	printf("\n\n\n\n");

	/*删除元素之后的树*/

	DeleteMin(One);
	DeleteMin(One);

	for(i =0; i< MaxSize; i ++)
	{
		if(One ->theTrees[i])
		{
			PrintTree(One ->theTrees[i],0);
			printf("\n\n");
		}

	}

	std::cout<<std::endl;
}