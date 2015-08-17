/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/8/15
description:不相交集
********************************************/

#include "DisjSet.h"
#include <cstdlib>
#include <iostream>


/*按高度求并，初始化为高度1用复数表示*/
void initialize(DisjSet S)
{
	int i;
	for(i=0; i<NumSets; i++)
		S[i] = -1;
}


void SetUnion(DisjSet S, SetType root1, SetType root2)
{
	if(S[root1] < S[root2])
		S[root2] = root1;
	else
	{
		if(S[root1] == S[root2])
			S[root2] --;
		S[root1] = root2;
	}
}


/*路径压缩*/
SetType Find(ElementType X, DisjSet S)
{
	if(S[X] <= 0)
		return X;
	else
		return S[X] = Find(S[X], S);
}

