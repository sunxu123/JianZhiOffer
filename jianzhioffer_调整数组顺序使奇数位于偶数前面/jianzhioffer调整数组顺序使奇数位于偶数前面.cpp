// jianzhioffer调整数组顺序使奇数位于偶数前面.cpp : Defines the entry point for the console application.
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//例：{ 1,2,3,4,5,6,7 }

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//我的做法：遇到奇数就把这个数与前一个奇数之间的偶数后移一位，并将此奇数移到前面一位。
//			注意:右移时要注意从高位开始
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int center = 0;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 1)
			{
				int temp = array[i];
				for (int j = i-1; j >= center; j--)
				{
					array[j+1] = array[j];
				}
				array[center] = temp;
				center ++;
			}
		}
	}
};

//其他做法：一、冒泡排序法
//			二、新建一个数组：此方法空间变大，时间变短

int main()
{
	vector<int> a = { 1,2,3,4,5,6,7 };

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << "\t";
	cout << endl;

	Solution s;
	s.reOrderArray(a);

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << "\t";
	cout << endl;

    return 0;
}

