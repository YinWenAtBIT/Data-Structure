/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/10
description:TreapÊ÷
********************************************/
#include "Treap.h"
#include <iostream>

int main()
{
	
	TreapTree T = initialize();

	T = insert(10, T);
	T = insert(85, T);
	T = insert(15, T);
	T = insert(70, T);
	T = insert(20, T);
	T = insert(65, T);
	T = insert(80, T);
	T = insert(90, T);
	T = insert(40, T);
	T = insert(5, T);
	T = insert(55, T);
	T = insert(60, T);
	T = insert(30, T);
	T = insert(50, T);

	T = insert(35, T);
	PrintTree(T, 0);

	T = remove(70, T);
	printf("\n\n\n\n\n");
	PrintTree(T, 0);
}