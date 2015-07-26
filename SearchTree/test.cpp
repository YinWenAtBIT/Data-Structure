/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/20
description:二叉查找树测试代码
********************************************/
#include "searchTree.h"
#include <stdlib.h>
#include <malloc.h>
#include <iostream>

int main()
{

#pragma region searchtree
	int i;
	SearchTree One;
	One = NULL;
	/*插入数据，先插入10，再插入偶数和奇数*/
	One = Insert(10, One);
	for(i = 0; i<10; i++)
	{
		One = Insert(2*i, One);
	}
	for(i = 0; i<10; i++)
	{
		One = Insert(2*i+1, One);
	}
	
	PrintTree(One,0);
	/*删除节点*/
	Delete(20, One);

	Delete(11, One);

	Delete(3, One);

	PrintTree(One,0);



	std::cout<<std::endl;

#pragma endregion  

}