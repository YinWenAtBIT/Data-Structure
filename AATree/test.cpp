/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/9
description:AAÊ÷
********************************************/

#include "AATree.h"

int main()
{
	
	AATree T = initialize();

	T = insert(10, T);
	T = insert(85, T);
	T = insert(15, T);
	T = insert(70, T);
	T = insert(20, T);
	T = insert(60, T);
	T = insert(30, T);
	T = insert(50, T);
	T = insert(65, T);
	T = insert(80, T);
	T = insert(90, T);
	T = insert(40, T);
	T = insert(5, T);
	T = insert(55, T);
	T = insert(35, T);
	PrintTree(T, T->level);

	T = remove(70, T);
	PrintTree(T, T->level);
}
