/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/15
description:不相交集
********************************************/

#include "DisjSet.h"
#include <cstdlib>
#include <iostream>


int main()
{
	DisjSet One;
	initialize(One);
	int i;
	SetType root1, root2;
	for(i=10; i< 1000; i++)
	{
		root1 = Find(2*i+1, One);
		root2 = Find(3*i+1, One);
		SetUnion(One, root1, root2);
	}
	for(i=0; i<1000; i++)
		printf("%d : %d\n ", i, Find(i,One));
}