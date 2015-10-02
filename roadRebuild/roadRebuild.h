/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/30
description:公路重建问题，用来保存距离的数据结构
			需要支持多个重复的key，出于便捷，我在
			这里直接使用multiset，不自行编写了。
********************************************/


#include <set>

using namespace std;


bool Turnpike(int X[], multiset<int> D, int N);

bool Place(int X[], multiset<int> D, int N, int left, int right);