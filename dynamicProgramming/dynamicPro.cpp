/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/27
description:动态规划问题，
			斐波那契数列计算
			C(N)=(2/N)((C(0)+0) + (C(1)+1) + ... +(C(N-1)+N-1))数列求解
			矩阵乘法顺序安排
********************************************/
#include "dynamicPro.h"
#define infinity 0x7FFFFFFF

/*斐波那契数列计算*/
int Fibonacci(int N)
{
	if(N<=1)
		return 1;

	int last, nextToLast, Answer;
	last = nextToLast =1;
	for(int i=1; i<N; i++)
	{
		Answer = last+nextToLast;
		nextToLast = last;
		last = Answer;
	}
	return Answer;
}

/*C(N)=(2/N)((C(0)+0) + (C(1)+1) + ... +(C(N-1)+N-1))数列求解*/
double Eval(int N)
{
	double lastSum, Answer;
	Answer = lastSum = 1.0;
	int i=1;
	while(i<=N)
	{
		Answer = 2.0/i*lastSum+i;
		lastSum += Answer;
		i++;
	}
	return Answer;
}

/*矩阵乘法顺序安排*/
void OptMatrix(const long C[], int N, TwoDimArray M, TwoDimArray LastChange)
{
	int i, k, left, right;
	long ThisM;
	for(left =1; left<=N; left++)
		M[left][left] = 0;
	for(k=1; k<N; k++)
		for(left=1; left<=N-k; left++)
		{
			right = left+k;
			M[left][right] = infinity;
			for(i = left; i<right; i++)
			{
				ThisM = M[left][i]+M[i+1][right] + C[left-1]*C[i]*C[right];
				if(ThisM<M[left][right])
				{
					M[left][right] = ThisM;
					LastChange[left][right] = i;
				}
			}
		}
}

double sum(const Vob C[], int left, int right)
{
	double output = 0;
	for(int i=left; i<= right; i++)
		output += C[i].value;

	return output;
}

double value(doubleArray M, int left, int right)
{
	if(left>right)
		return 0.0;
	return M[left][right];
}


/*最优查找二叉树,为了保持和上面的最佳矩阵乘法顺序形式相同，这里计数也从1开始，0没有定义*/
void OptSearchTree(const Vob C[], int N, doubleArray &M, TwoDimArray &LastChange)
{
	int left, right, k;
	double ThisM;
	for(int i=1; i<=N; i++)
		M[i][i] = C[i].value;

	for(k=1; k<N; k++)
		for(left =1; left<=N-k; left++)
		{
			right = left+k;
			M[left][right] =infinity;
			for(int i=left; i<=right; i++)
			{
				ThisM = value(M, left, i-1) + value(M, i+1, right)+sum(C, left, right);
				if(ThisM < M[left][right])
				{
					M[left][right] = ThisM;
					LastChange[left][right] = i;
				}
			}
		}
}