// jianzhioffer数值的整数次方.cpp : Defines the entry point for the console application.
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

/*
	直接乘？？
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

//我的做法：直接乘
class Solution {
public:
	double Power(double base, int exponent) {
		if (base == 0)
			return 0;
		else
		{
			if (exponent == 0)
				return 1;
			else
			{
				double result=1.0;
				for (int i = 0; i < abs(exponent); i++)
				{
					result *= base;
				}
				if (exponent > 0)
					return result;
				else
					return 1.0 / result;
			}
		}

	}
};

//推荐的做法：https://www.cnblogs.com/lca1826/p/6748372.html
//一、要考虑0的0、-1、-2……是没有意义的
//二、快速幂方法可以迅速求出一个数的任意次方。假设我们要求a^b,按照朴素算法就是把a连乘b次，这样一来时间复杂度是O(b)也即是O(n)级别，快速幂能做到O(logn)，
/*		快速幂算法的原理：例如，若要计算a^11
							a^11
							=a^(2^3+2^1+2^0)	1011 = 11 
							=a^(8+2+1)		
							=a^8 * a^2 * a^1
						同理，若要计算a^15		1111
							a^16
							=a^8 * a^4 * a^2 * a^1		时间复杂度降低，且优化后空间复杂度不变
							=(a^4)^2 * (a^2)^2 * (a^1)^2 * a
						所以，只要从指数的低位到高位遍历，同时每向高位移动一位，a = a^2；如果此位二进制为1，则结果与之相乘，否则不相乘，继续迭代到指数二进制所有位判断完毕

*/
class Solution1 {
public:
	double Power(double base, int exponent) {
		if (base == 0 && exponent > 0)
			return 0;
		else if (base == 0 && exponent <= 0)//包括0^0 与 分母为0两种情况
			return 0;
		else
		{
			if (exponent == 0)
				return 1;
			else
			{
				double result = 1.0;
				int ex = abs(exponent);
				while (ex)
				{
					if (ex & 1)
						result *= base;
					base *= base;
					ex = ex >> 1;
				}
				return exponent > 0 ?  result:  1.0 / result;
			}
		}

	}
};

int main()
{
	Solution s;
	cout << s.Power(3.1, 3) << endl;
	cout << s.Power(3.1, 0) << endl;
	cout << s.Power(3.1, -3) << endl;

	Solution1 s1;
	cout << s1.Power(3.1, 3) << endl;
	cout << s1.Power(3.1, 0) << endl;
	cout << s1.Power(3.1, -3) << endl;


    return 0;
}

