/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/22
description:求最近点的距离,测试文件
********************************************/
#include "nearPoint.h"
#include <iostream>
#include <time.h>


using namespace std;

float Random()
{
	float temp = rand()%10000;
	return temp/100.0;
}

int main()
{
	int num;
	cout<<"please input number of points"<<endl;
	cin>>num;
	srand((unsigned)time(NULL));


	PointX *X = new PointX[num];
	for(int i=0; i<num; i++)
	{
		X[i].ID = i;
		X[i].x =Random();
		X[i].y =Random();
//		cout<<"num: "<<i<<"  ("<<X[i].x<<", "<<X[i].y<<")"<<endl;
	}

	PointX a,b;
	float distance;
	getNearDis(X, num, a, b, distance);

	cout<<"the min distance is: "<<distance<<endl;
	cout<<"the position is: "<<" ("<<a.x<<", "<<a.y<<")"<<" ("<<b.x<<", "<<b.y<<")"<<endl;

	delete [] X;
}