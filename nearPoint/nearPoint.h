/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/22
description:求最近点的距离
********************************************/
#include <cstdlib>
#include <iostream>







class PointX
{
public:
	PointX(){}
	bool operator <(PointX &P2){return x<P2.x;}
	bool operator <=(PointX &P2){return x<=P2.x;}
	int ID;
	float x,y;
	
};

class PointY
{
public:
	PointY(){}
	bool operator <(PointY &P2){return y<P2.y;}
	bool operator <=(PointY &P2){return x<=P2.y;}
	int xID;
	float x,y;
	
};

void getNearDis(PointX X[], int N, PointX &a, PointX &b, float &d);
void getClosest(PointX X[], PointY Y[], PointY Z[], int left, int right, PointX &a, PointX &b, float &d);




template <typename T>
float getDis(T &a, T &b)
{
	float x = a.x-b.x;
	float y = a.y-b.y;
	return sqrt(x*x+y*y);
}

/*归并排序*/
template <typename T>
void Merge(T A[], T TmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, Num, TmpPos;
	LeftEnd = Rpos -1;
	Num = RightEnd - Lpos +1;
	TmpPos = Lpos;

	while(Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if(A[Lpos] < A[Rpos])
			TmpArray[TmpPos++] = A[Lpos++];
		else
			TmpArray[TmpPos++] = A[Rpos++];
	}

	/*复制剩下的数据*/
	while(Lpos <= LeftEnd)
		TmpArray[TmpPos++] = A[Lpos++];

	while(Rpos <= RightEnd)
		TmpArray[TmpPos++] = A[Rpos++];

	/*拷贝回原来的数组*/
	for(i =0; i<Num; i++, RightEnd--)
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}


template <typename T>
void Msort(T A[], T TmpArray[], int Left, int Right)
{
	int Center;
	if(Left < Right)
	{
		Center = (Left+Right)/2;
		Msort(A, TmpArray, Left, Center);
		Msort(A, TmpArray, Center+1, Right);
		Merge(A, TmpArray, Left, Center+1, Right);
	}
}


template <typename T>
void MergeSort(T A[], int N)
{
	T * TmpArray = (T *)malloc(N*sizeof(T));
	if(TmpArray == NULL)
	{
		fprintf(stderr, "not enough memory\n");
		exit(1);
	}

	Msort(A, TmpArray, 0, N-1);
	free(TmpArray);
}




