// jianzhioffer整数中1出现的次数从1到n整数中1出现的次数.cpp : Defines the entry point for the console application.
//求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

/*
	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24……31……41……51……61……71……81……91……100	101	102	109	110	111
	0	1	1	1	1	1	1	1	1	1	2	4	5	6	7	8	9	10	11	12	12	13	13	13	13……14……15……16……17……18……19……20……21	23	24	31	33	36

	6 ：  第一位为0，sum+=0*1
		  第二位为6>=1, sum+=1

	16 ： 第一位为1，sum+=1*1 + 6+1
		  第二位为6>=1, sum+=1

	23 ： 第一位为2，sum+=2*1 + 10
		  第二位为3>=1, sum+=1

	91:	  第一位为9，sum+=9*1 + 10
		  第二位为1>=1, sum+=1

	103:  第一位为1，sum+=1*20 + 03+1
		  第二位为0, sum+=0
		  第三位为3, sum+=1

	111:  第一位为1，sum+=1*20 + 11+1 + (11个数)
		  第二位为1, sum+=1*1 + 1+1
		  第三位为1, sum+=1


	*/
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//我的做法：
class Solution {
public:
	//int sum = 0;
	int my_fun(int n, int weishu)
	{
		int lastbase, lastchushu, lastyushu, lastweishu;
		int base = pow(10, weishu);
		int chushu = n % (base * 10) / base;
		int yushu = n % base;
		lastbase = base;
		lastchushu = chushu;
		lastyushu = yushu;
		lastweishu = weishu;

		while (chushu != 0 || yushu != n)//数字已到最高位，一直找到数字的最高位开始
		{
			lastbase = base;
			lastchushu = chushu;
			lastyushu = yushu;
			lastweishu = weishu;
			weishu++;
			base = pow(10, weishu);
			chushu = n % (base * 10) / base;
			yushu = n % base;
		}

		base = lastbase;//得到最高位所在的位数，基数，最高位数字，低位数字
		chushu = lastchushu;
		yushu = lastyushu;
		weishu = lastweishu;

		if (chushu == 1)
		{
			if (weishu > 0)
				return  1 * my_fun(base - 1, 0) + yushu + 1 + my_fun(yushu, 0);//针对最高位为1的特殊情况
			else
				return 1;//针对个位数的特殊情况
		}
		else if (chushu > 1)
		{
			if (weishu > 0)
				return (chushu - 1)* my_fun(base - 1, 0) + my_fun(2 * base - 1, 0) - my_fun(base - 1, 0) + my_fun(yushu, 0);//但最高位不等于1是，仍然将处理最高位为1的情况my_fun(2 * base - 1, 0) - my_fun(base - 1, 0)
			else
				return 1;//针对个位数的特殊情况
		}
		else
			return 0;
	}
	int NumberOf1Between1AndN_Solution(int n)
	{
		return my_fun(n, 0);
	}
};

int main()
{
	Solution s;
	cout << s.NumberOf1Between1AndN_Solution(6) << endl;//1
	cout << s.NumberOf1Between1AndN_Solution(10) << endl;//2
	cout << s.NumberOf1Between1AndN_Solution(16) << endl;//9
	cout << s.NumberOf1Between1AndN_Solution(23) << endl;//13
	cout << s.NumberOf1Between1AndN_Solution(91) << endl;//20
	cout << s.NumberOf1Between1AndN_Solution(111) << endl;//36
	cout << s.NumberOf1Between1AndN_Solution(10000) << endl;//4001
	cout << s.NumberOf1Between1AndN_Solution(21345) << endl;//18821 = 2*fun(9999) + fun(19999)-fun(9999)
	//01101			11101
	return 0;
}

