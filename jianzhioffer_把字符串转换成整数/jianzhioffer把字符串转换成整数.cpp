// jianzhioffer把字符串转换成整数.cpp : Defines the entry point for the console application.
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
/*
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
1a33
输出
2147483647
0
*/
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//我的做法：从后往前计算
class Solution1{
public:
	int StrToInt(string str) {
		int result=0;
		int weishu = 0;
		for (int i = str.size() - 1; i > 0; i--)
		{
			int temp = str[i] - '0';
			if (temp > 9 || temp < 0)
				return 0;
			else
			{
				result += temp*pow(10, weishu);
				weishu++;
			}
		}
		
		if (str[0] <= '9' && str[0] >= '0')
			result += (str[0] - '0')*pow(10, weishu);
		else if (str[0] == '-' )
			result = -result;
		else if (str[0] != '+')
			result = 0;
		return result;
	}
};
//推荐的做法：使用位运算提升效率
class Solution {
public:
	int StrToInt(string str) {
		int result = 0;
		int s = 1;
		if (str[0] == '-') s = -1;

		for (int i = ((str[0] <= '9' && str[0] >= '0') ? 0 : 1); i < str.size(); i++)
		{
			cout << str[i] << endl;
			if (str[i] > '9' || str[i] < '0')
				return 0;
			else
			{
				result = (result << 1) + (result << 3) + (str[i] & 0xf);
			}
		}

		return result*s;
	}
};
int main()
{
	Solution s;
	cout << s.StrToInt("+2147483647") << endl;
	cout << s.StrToInt("1a33") << endl;
    return 0;
}

