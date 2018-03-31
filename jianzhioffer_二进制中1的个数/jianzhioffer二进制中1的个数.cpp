// jianzhioffer二进制中1的个数.cpp : Defines the entry point for the console application.
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

/*
	11=1011;
	-11 = 0100+1=0101

	10 =1010
	-10=0101+1

	1=1;
	-1=1111111111 0 +1
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//我的做法：
//	正数时：直接逐位右移再与1相与，就可以得到
//	负数时：由于 ！右移高位会补充符号位！ ，所以若用正数的方法会陷入死循环。
//			所以此处负数采用原始的计算补码方式来实现。但也要注意 INT_MIN 直接转化为正数时会出现溢出的错误，INT_MIN =(-INT_MAX - 1)
class Solution {
public:
	int  NumberOf1(int n)
	{
		int temp = 1;
		int weishu = 0;
		vector<bool> bit_of_n(32,0);
		if (n < 0)
		{
			long long n1 = n;
			n1 = -n1;
			while (temp <= n1&& weishu<32)//正数的原码
			{
				if (n1 & temp)
					bit_of_n[weishu] = 1;
				//n >>= 1;
				weishu++;
				temp = pow(2, weishu);
			}

			for (int i = 0; i < bit_of_n.size(); i++)//反码
				bit_of_n[i] = 1-bit_of_n[i];

			for (int i = 0; i < bit_of_n.size(); i++)//补码
			{
				if (bit_of_n[i] == 1 )
					bit_of_n[i] = 0;
				else
				{
					bit_of_n[i] = 1;
					break;
				}
			}
			
			return count(bit_of_n.begin(), bit_of_n.end(), true);
		}
		else
		{
			while (temp <= n)
			{
				if (n & temp)
					bit_of_n[weishu] = 1;
				//n >>= 1;
				weishu++;
				temp = pow(2, weishu);
			}
			return count(bit_of_n.begin(), bit_of_n.end(), true);
		}
	}
};

//推荐的做法：
//	原理：如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。
class Solution1 {
public:
	int  NumberOf1(int n)
	{
		int count = 0;
		while (n)
		{
			count++;
			n = n&(n - 1);
		}
		return count;
	}
};

//注意程序中不应当直接给int型变量赋最小值，会有warning，所以-2147483648改写为-2147483647-1（http://blog.csdn.net/theonegis/article/details/43490935）
int main()
{
	Solution s;
	cout << s.NumberOf1(0) << endl;
	cout << s.NumberOf1(-11) << endl;
	cout << s.NumberOf1(-1) << endl;
	cout << s.NumberOf1(-2147483647 - 1) << endl;

	Solution1 s1;
	cout << s1.NumberOf1(0) << endl;
	cout << s1.NumberOf1(-11) << endl;
	cout << s1.NumberOf1(-1) << endl;
	cout << s1.NumberOf1(-2147483647 - 1) << endl;

    return 0;
}

