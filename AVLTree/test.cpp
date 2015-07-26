/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/7/22
description:AVL树测试代码
********************************************/
#include "AVLTree.h"
#include <stdlib.h>
#include <iostream>

int main()
{

#pragma region AVLTree
	int i;
	AVLTree One;
	One = NULL;
	One = Insert(10, One);

	/*插入数值，先插入偶数，再插入奇数*/
	for(i = 0; i<10; i++)
	{
		One = Insert(2*i, One);
	}
	for(i = 0; i<10; i++)
	{
		One = Insert(2*i+1, One);
	}
	
	PrintTree(One,0);
	One = Delete(20, One);


	AVLTree temp10;


	printf("\n\nDelete 7,9,11,13,8,12 \n");
	/*删除时需要保持赋值的，不能让返回值滞空，因为旋转之后可能根节点改变*/
	One =Delete(7, One);
	One =Delete(9, One);
	One =Delete(11, One);
	One =Delete(13, One);

	/*打印出树节点的高度*/
	temp10 = Find(10,One);
	printf("10's height = %d\n",temp10->Hight);

	One =Delete(8, One);
	temp10 = Find(10,One);
	printf("10's height = %d\n",temp10->Hight);

	One =Delete(12, One);
	temp10 = Find(10,One);
	printf("10's height = %d\n",temp10->Hight);

	PrintTree(One,0);


	std::cout<<std::endl;

#pragma endregion  

}