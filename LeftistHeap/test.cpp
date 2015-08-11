/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/4
description:伸展树的测试代码，输出树的结构
********************************************/
#include "LeftistHeap.h"
#include <stdlib.h>
#include <iostream>

int main()
{
	int i;
	PriorityQueue One;
	One = NULL;

	/*插入数据，先插入10，再分别按偶数奇数插入0-20*/
	insert(10, One);

	for(i = 0; i<10; i++)
	{
		One = insert(2*i, One);
	}

	for(i = 0; i<10; i++)
	{
		One = insert(2*i+1, One);
	}
	/*打印出树，每一级深度加一个4个空格，先打印左子树再打印右子数*/
	PrintTree(One,0);
	printf("\n\n\n\n");

	/*寻找5之后的树*/

	PrintTree(One,0);
	printf("\n\n\n\n");

	/*删除元素之后的树*/



	PrintTree(One,0);






	std::cout<<std::endl;
}