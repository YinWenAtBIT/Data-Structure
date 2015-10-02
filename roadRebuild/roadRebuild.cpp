/***************************************
Author: YinWen
email: yinwenatbit@163.com
date: 2015/9/30
description:公路重建问题，用来保存距离的数据结构
			需要支持多个重复的key，出于便捷，我在
			这里直接使用multiset，不自行编写了。
********************************************/
#include "roadRebuild.h"

bool Turnpike(int X[], multiset<int> D, int N)
{
	X[1] = 0;
	auto it = D.end();
	X[N] = *(--it);
	--it;
	D.erase(X[N]);
	X[N-1] = *(it);
	D.erase(X[N-1]);

	if((it = D.find(X[N]- X[N-1])) != D.end())
	{
		D.erase(it);
		return Place(X, D, N, 2, N-2);
	}
	return 0;
}

bool Place(int X[], multiset<int> D, int N, int left, int right)
{
	bool found = false;

	if(D.empty())
		return true;

	auto it = D.end();
	--it;
	X[right] = *it;
	

	int i, j;
	/*判断左边点到X[right]的距离是否都存在*/
	for(i=1; i<left; i++)
	{
		if((it = D.find(X[right] - X[i])) != D.end())
			D.erase(it);
		else
		{
			for(int k = i-1;k>0; k--)
				D.insert(X[right] - X[i]);
			break;
		}
	}
	/*左边点到X[right]距离都存在则判断右边*/
	if(i == left)
	{
		for(i=right+1; i<=N; i++)
		{
			if((it = D.find(X[i] - X[right])) != D.end())
				D.erase(it);
			else
			{
				/*右边不符合，还得把先前在左边删除的节点补上再补上右边的*/
				for(int k = 1;k<left; k++)
					D.insert(X[right] - X[k]);

				for(int k = i-1;k>right; k--)
					D.insert(X[k] - X[right]);
				break;
			}
		}
		/*左右两边都符合，进行下一轮判断，不符合就继续执行程序*/
		if(i == N+1)
		{
			found = Place(X, D, N, left, right-1);

			/*下一层成功就直接返回成功，否则尝试左边*/
			if(!found)
			{
				for(i=1; i<left; i++)
					D.insert(X[right] - X[i]);
				for(i=right+1; i<=N; i++)
					D.insert(X[i] - X[right]);
			}
			else
				return true;
		}
	}

	/*如果上一轮没有返回，代表插入到right失败，现在插入到左边*/

	X[left] = X[N] - X[right];

	/*判断左边点到X[left]的距离是否都存在*/
	for(i=1; i<left; i++)
	{
		if((it = D.find(X[left] - X[i])) != D.end())
			D.erase(it);
		else
		{
			for(int k = i-1;k>= 0; k--)
				D.insert(X[left] - X[k]);
			break;
		}
	}
	/*左边点到X[right]距离都存在则判断右边*/
	if(i == left)
	{
		for(i=right+1; i<=N; i++)
		{
			if((it = D.find(X[i] - X[left])) != D.end())
				D.erase(it);
			else
			{
				/*右边不符合，还得把先前在左边删除的节点补上再补上右边的*/
				for(int k = 1;k<left; k++)
					D.insert(X[left] - X[k]);

				for(int k = i-1;k> right; k--)
					D.insert(X[k] - X[left]);
				break;
			}
		}
		/*左右两边都符合，进行下一轮判断，不符合就继续执行程序*/
		if(i == N+1)
		{
			found = Place(X, D, N, left+1, right);

			/*下一层成功就直接返回成功，否则返回失败*/
			if(!found)
			{
				for(i=1; i<left; i++)
					D.insert(X[left] - X[i]);
				for(i=right+1; i<=N; i++)
					D.insert(X[i] - X[left]);
			}
			else
				return true;
		}
	}

	return false;

}