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
#include <iostream>

using namespace std;

void printSeperate(int A[8][8], int left, int right);

int main()
{
	cout<<"Fibonacci: "<<Fibonacci(10)<<endl;
	cout<<"数列N: "<<Eval(10)<<endl;

	/*,矩阵计数从1开始。四个矩阵，C[1-N]代表每个矩阵的列数，C[0]代表第一个矩阵的行数*/
	long C[7+1];
	C[0] = 50;
	C[1] = 10;
	C[2] = 40;
	C[3] = 30;
	C[4] = 5;
	C[5] = 35;
	C[6] = 25;
	C[7] = 65;

	int M[8][8];
	int LastChange[8][8];
	OptMatrix(C, 7, M, LastChange);

	cout<<"Optimal Out: "<<M[1][7]<<endl;
	cout<<"seperate order: ";
	printSeperate(LastChange, 1, 7);


	cout<<"\n\n\n\n\n";

	Vob Word[8];
	Word[1].name ="a";
	Word[1].value = 0.22;
	Word[2].name ="am";
	Word[2].value = 0.18;
	Word[3].name ="and";
	Word[3].value = 0.20;
	Word[4].name ="egg";
	Word[4].value = 0.05;
	Word[5].name ="if";
	Word[5].value = 0.25;
	Word[6].name ="the";
	Word[6].value = 0.02;
	Word[7].name ="two";
	Word[7].value = 0.08;

	double M2[8][8] = {0};


	OptSearchTree(Word, 7, M2, LastChange);

	cout<<"Optimal Out: "<<M2[1][7]<<endl;
	cout<<"seperate order: ";
	printSeperate(LastChange, 1, 7);
}



void printSeperate(int A[8][8], int left, int right)
{
	int sep;

	sep = A[left][right];
	if(sep<right && sep >=left)
	{
		cout<<"matrix time from "<<left<<" to "<<right<<" is seprated to:\n"<<left<<" to "<<sep<<" and "<<sep+1<<" to "<<right<<endl;
		printSeperate(A, left, sep);
		printSeperate(A, sep+1, right);
	}
}