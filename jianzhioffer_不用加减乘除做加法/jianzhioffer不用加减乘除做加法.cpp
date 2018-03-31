// jianzhioffer不用加减乘除做加法.cpp : Defines the entry point for the console application.
//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

#include "stdafx.h"
#include <iostream>

using namespace std;

/*
我的做法：二进制位逐位相加，判断进位
*/
class Solution1 {
public:
	int result=0;
	int flag = 1;
	void my_fun(int num1, int num2, int jinwei)
	{
		if (num1 == 0 && num2 == 0 || flag ==0)//正数满足前面的条件，负数满足后面的条件
			return;
		flag = flag << 1;
		int a =( num1 & 1 )&(num2 & 1);
		int o = (num1 | num2) & 1 ;

		//cout << "a=" << a << "o=" << o << "jinwei=" << jinwei << endl;

		int ciwei = 0;
		if (a == 0 && o == 1)
		{
			if (jinwei)
			{
				ciwei = 0;
			}
			else
			{
				ciwei = 1;
				jinwei = 0;
			}
		}
		else if (a == 0 && o == 0)
		{
			ciwei = jinwei;
			jinwei = 0;
		}
		else if (a == 1 && o == 1)
		{
			if (jinwei)
			{
				ciwei = 1;
			}
			else
			{
				ciwei = 0;
				jinwei = 1;
			}
		}

		my_fun(num1 >> 1, num2 >> 1, jinwei);

		result = result << 1;
		if (ciwei)
			result = result | 1;
		//cout << "result =" << result << endl;
	}
	int Add(int num1, int num2)
	{
		result = 0;
		flag = 1;
		my_fun(num1, num2, 0);
		return result;
	}
};

/*
推荐的做法：调用加法器公式
同样我们可以用三步走的方式计算二进制值相加： 5-101，7-111 第一步：相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111。

第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1。

第三步重复上述两步， 各位相加 010^1010=1000，进位值为100=(010&1010)<<1。
继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果。
*/
class Solution {
public:
	//变量优化版本
	int Add(int num1, int num2)
	{
		int sum;
		while (num2)
		{
			sum = num1 ^ num2; //和
			num2 = (num1 & num2) << 1; //进位
			num1 = sum;
		}

		return num1;
	}
	//好理解版本
	int Add1(int num1, int num2)
	{
		int sum = num1 ^ num2;
		int carry = num1 & num2;
		while (carry)
		{
			sum = num1 ^ num2; //和
			carry = num1 & num2; //进位
			num1 = sum;
			num2 = carry << 1;
		}

		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.Add(5, 10) << endl;
	cout << s.Add(1, 2) << endl;
	cout << s.Add(111, 899) << endl;
	cout << s.Add(-1, 2) << endl;
	cout << s.Add(1, -2) << endl;
	return 0;
}

