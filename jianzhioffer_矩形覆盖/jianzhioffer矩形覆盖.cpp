// jianzhioffer矩形覆盖.cpp : Defines the entry point for the console application.
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//	口	口口		口口口口……口口
//	口			口口口口……口口
//	简化：
//	口		口口		口口口口……口口
//
/*
	n=1;	1
	n=2;	2
	n=3;	3	

	f(n)=f(n-1)+f(n-2)
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

//我的解法：简化后同跳台阶问题
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1; 
		if (n == 2)
			return 2;

		int fl = 1;
		int fh = 2;
		int value = 0;
		for (int i = 3; i < n; i++)
		{
			value = fl + fh;
			fl = fh;
			fh = value;
			//v.push_back(value);
		}

		return fh + fl;
	}
};

int main()
{

    return 0;
}

