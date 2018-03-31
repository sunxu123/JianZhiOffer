// jianzhioffer变态跳台阶.cpp : Defines the entry point for the console application.
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
/*
n=1;	1
n=2;	1+1=2
n=3;	1+2+1=4
n=4;	8	
n=5;	16
//f(n)的前一状态可以是f(0)~f(n-1)任意状态
f(n)=f(n-1)  + f(n-2) + f(n-3) +  f(n-4) + f(2) +f(1) +1;(f(0)==1)

*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//我的做法；利用动态规划找递推公式
class Solution {
public:
	int jumpFloorII(int number) {
		if (number < 2)
			return 1;
		vector<int> vector_fn;
		vector_fn.push_back(1);//f(0)
		vector_fn.push_back(1);//f(1)

		for (int i = 2; i <= number; i++)
		{
			int fi = 0;
			for (int j = 0; j < vector_fn.size(); j++)
				fi += vector_fn[j];
			vector_fn.push_back(fi);
		}

		return vector_fn[vector_fn.size() - 1];
	}
};

//推荐的做法：对地推公式继续进行简化：
//f(n-1)=f(0) + f(1) + f(2) + f(3) + ... + f(n - 2)
//所以：f(n) = 2*f(n-1) = 2*2*f(n-2)=……=2^(n-1)*f(1) = 2^(n-1);注意f(0)为初值特例不满足此递归
class Solution1 {
public:
	int jumpFloorII(int number) {
		if (number < 2)
			return 1;

		return 2 ^ (number - 1);
	}
};

int main()
{
	Solution s;
	cout << s.jumpFloorII(3) << endl;
	Solution s1;
	cout << s1.jumpFloorII(3) << endl;

    return 0;
}

