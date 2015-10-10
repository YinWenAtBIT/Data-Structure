/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/10/10
description:2-dÊ÷
********************************************/

#include "2-dTree.h"
#include <cstdlib>
#include <iostream>

int main()
{
	KdTree T = NULL;

	int data[2];
	data[0] = 53;
	data[1] = 14;
	T = insert(data, T);

	data[0] = 27;
	data[1] = 28;
	T = insert(data, T);

	data[0] = 30;
	data[1] = 11;
	T = insert(data, T);

	data[0] = 29;
	data[1] = 16;
	T = insert(data, T);

	data[0] = 40;
	data[1] = 26;
	T = insert(data, T);

	data[0] = 38;
	data[1] = 23;
	T = insert(data, T);

	data[0] = 31;
	data[1] = 85;
	T = insert(data, T);

	data[0] = 7;
	data[1] = 39;
	T = insert(data, T);

	data[0] = 15;
	data[1] = 61;
	T = insert(data, T);

	data[0] = 32;
	data[1] = 29;
	T = insert(data, T);

	data[0] = 67;
	data[1] = 50;
	T = insert(data, T);

	data[0] = 79;
	data[1] = 3;
	T = insert(data, T);

	data[0] = 99;
	data[1] = 90;
	T = insert(data, T);

	data[0] = 82;
	data[1] = 64;
	T = insert(data, T);

	data[0] = 73;
	data[1] = 75;
	T = insert(data, T);

	PrintTree(T, 0);

	printf("\n\n\n\n");

	int Low[2] = {15,20};
	int High[2] = {60, 60};
	PrintRange(Low, High , T);
}