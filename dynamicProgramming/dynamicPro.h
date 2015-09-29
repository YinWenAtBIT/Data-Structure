/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/27
description:动态规划问题，
			斐波那契数列计算
			C(N)=(2/N)((C(0)+0) + (C(1)+1) + ... +(C(N-1)+N-1))数列求解
			矩阵乘法顺序安排
********************************************/
#include <string>

typedef int TwoDimArray[8][8];
typedef double doubleArray[8][8];

/*斐波那契数列计算*/
int Fibonacci(int N);

/*C(N)=(2/N)((C(0)+0) + (C(1)+1) + ... +(C(N-1)+N-1))数列求解*/
double Eval(int N);

/*矩阵乘法顺序安排*/
void OptMatrix(const long C[], int N, TwoDimArray M, TwoDimArray LastChange);




struct Vocab
{
	std::string name;
	double value;
};

typedef struct Vocab Vob;



/*最优查找二叉树*/
void OptSearchTree(const Vob C[], int N, doubleArray &M, TwoDimArray &LastChange);