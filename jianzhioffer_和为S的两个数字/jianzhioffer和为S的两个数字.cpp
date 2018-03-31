// jianzhioffer和为S的两个数字.cpp : Defines the entry point for the console application.
//输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。对应每个测试案例，输出两个数，小的先输出。

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//我的做法：小的数从前往后，大的数从后往前，第一个相等的就是结果
class Solution1 {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> result;
		int a; int b;

		if (array.size() < 2)
		return result;

		for (int i = 0; i < array.size()-1; i++)
		{
			a = array[i];
			for (int j = array.size() - 1; j > i; j--)
			{
				int b = array[j];
				if (a + b == sum)
				{
					result = { a,b };
					break;
				}
				else if (a + b < sum)
					break;
			}
			if (result.size())
				break;
		}

		return result;
	}
};


/*推荐的做法：思想相同，但相对于我的时间复杂度要低很多，
因为若array[left] + array[right] < sum
array[left] + array[right+1] > sum 则array[left+1] + array[right+1] > sum
所以left+1后，right不需要从最后一位往前找，因为所有>right都是不可能的
*/
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> result;
		int left = 0;
		int right = array.size() - 1;
		while (left < right)
		{
			if (array[left] + array[right] == sum)
			{
				result.push_back(array[left]);
				result.push_back(array[right]);
				break;
			}
			else if (array[left] + array[right] > sum)
				right--;
			else
				left++;
		}
		return result;
	}
};

int main()
{
	vector<int> result;
	Solution s;
	result = s.FindNumbersWithSum({ 1,2,4,7,11,15 }, 15);
	cout << result[0] << "  " << result[1] << endl;
	result = s.FindNumbersWithSum({ 1,2,4,7,11,16 }, 17);
	cout << result[0] << "  " << result[1] << endl;
	result = s.FindNumbersWithSum({ 1,2,4,7,11,16 }, 10);
	//cout << result[0] << "  " << result[1] << endl;
	result = s.FindNumbersWithSum({ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 }, 21);
	cout << result[0] << "  " << result[1] << endl;
	result = s.FindNumbersWithSum({  }, 0);
	//cout << result[0] << "  " << result[1] << endl;

    return 0;
}

