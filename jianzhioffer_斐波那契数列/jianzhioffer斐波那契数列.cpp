// jianzhioffer斐波那契数列.cpp : Defines the entry point for the console application.
//F(0)=0，F(1)=1, F(n)=F(n-1)+F(n-2)

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//我的做法：递归法存在大量的重复运算，采用递推法求解
class Solution {
public:
	int Fibonacci1(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return Fibonacci1(n - 1) + Fibonacci1(n - 2);
	}
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;

		vector<int> v = { 0,1 };
		int value = 0;
		for (int i = 2; i < n ; i++)
		{
			value = v[0] + v[1];
			v[0] = v[1];
			v[1] = value;
			//v.push_back(value);
		}

		return v[1]+v[0];
	}
};


int main()
{
	Solution s;
	cout << s.Fibonacci1(0) << endl;
	cout << s.Fibonacci1(1) << endl;
	cout << s.Fibonacci1(2) << endl;
	cout << s.Fibonacci1(3) << endl;
	cout << s.Fibonacci1(4) << endl;
	cout << s.Fibonacci1(39) << endl;

	cout << s.Fibonacci(0) << endl;
	cout << s.Fibonacci(1) << endl;
	cout << s.Fibonacci(2) << endl;
	cout << s.Fibonacci(3) << endl;
	cout << s.Fibonacci(4) << endl;
	cout << s.Fibonacci(39) << endl;

	Solution1 s1;
	cout << s1.Fibonacci(0) << endl;
	cout << s1.Fibonacci(1) << endl;
	cout << s1.Fibonacci(2) << endl;
	cout << s1.Fibonacci(3) << endl;
	cout << s1.Fibonacci(4) << endl;
	cout << s1.Fibonacci(39) << endl;

    return 0;
}

