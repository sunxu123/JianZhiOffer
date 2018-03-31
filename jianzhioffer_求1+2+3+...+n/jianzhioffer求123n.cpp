// jianzhioffer求123n.cpp : Defines the entry point for the console application.
//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）

#include "stdafx.h"
#include <iostream>

using namespace std;

//我的解法：套公式
class Solution {
public:
	int Sum_Solution(int n) {
		return (int(n + pow(n, 2))) >> 1;
	}
};

//推荐的解法：递归求解
//			目标就是在n=0是，return的是0
class Solution1 {
public:
	/*int Sum_Solution(int n) {
		return n && (n + Sum_Solution(n - 1));
	}*/
	int Sum_Solution(int n) {
		int sum = n;
		n && (sum += Sum_Solution(n - 1));//当n==0时，不执行后面的累加，直接返回n==0，n!=0时，返回的为累加值
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.Sum_Solution(10) << endl;
	Solution1 s1;
	cout << s1.Sum_Solution(10) << endl;

    return 0;
}

