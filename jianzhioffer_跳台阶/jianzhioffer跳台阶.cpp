// jianzhioffer跳台阶.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//我的做法：使用排列组合来计算2步的可能性。要注意计算时阶乘溢出的问题
class Solution {
public:
	long long  Factorial(int n)
	{
		if (n == 0)
			return 1;
		else
			return n*Factorial(n - 1);
	}

	int cnm(int n, int m)
	{
		long long mul=1;

		for (int i = 0; i < m; i++)
		{
			mul *= (n - i);
		}
		return mul / Factorial(m);
		//return Factorial(n)/(Factorial(m)*Factorial(n-m));
	}

	int jumpFloor(int number) {
		if (number == 0)
			return 0;
		else if (number == 1)
			return 1;

		int methods = 0;
		int quotients = number / 2;//最多可以放多少个2
			while (quotients >=0)
			{
				methods += cnm(number- quotients,  quotients);
				quotients--;
			}

		return methods;
	}
};

//推荐的做法：
/*
	对于本题, 前提只有 一次 1阶或者2阶的跳法。

	a.如果两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n - 1个台阶，跳法是f(n - 1);

	b.假定第一次跳的是2阶，那么剩下的是n - 2个台阶，跳法是f(n - 2)

	c.由a\b假设可以得出总跳法为: f(n) = f(n - 1) + f(n - 2)

	d.然后通过实际的情况可以得出：只有一阶的时候 f(1) = 1, 只有两阶的时候可以有 f(2) = 2

	e.可以发现最终得出的是一个斐波那契数列：
*/
class Solution1 {
public:
	int jumpFloor(int target) {

			if (target <= 0) {
				return -1;
			}
			else if (target == 1) {
				return 1;
			}
			else if (target == 2) {
				return 2;
			}
			else {
				return jumpFloor(target - 1) + jumpFloor(target - 2);
			}
	}
};

int main()
{
	Solution s;
	cout << s.jumpFloor(0) << endl;
	cout << s.jumpFloor(2) << endl;
	cout << s.jumpFloor(5) << endl;
	cout << s.jumpFloor(29) << endl;
	Solution1 s1;
	cout << s1.jumpFloor(29) << endl;
	//cout << s.cnm(3,2)<< endl;

    return 0;
}

