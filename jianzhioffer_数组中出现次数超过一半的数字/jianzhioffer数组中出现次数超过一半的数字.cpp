// jianzhioffer数组中出现次数超过一半的数字.cpp : Defines the entry point for the console application.
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
/*

*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//我的做法：使用map统计每个元素出现的次数
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> count;
		int n = numbers.size();
		for (int i = 0; i<n; i++)
		{
			auto iter = count.find(numbers[i]);
			if (iter == count.end())
				//count.insert(pair<int,int>(numbers[i],1));//第一次
			{
				count[numbers[i]] = 1;
				if (n<2)
					return numbers[i];

			}
			else
			{
				iter->second++;//以后
				if (iter->second>n / 2.0)
					return iter->first;
			}
		}
		return 0;
	}
};

//推荐的做法一：因为如果存在这样一个数字满足个数>一半，那么将这个数组排序后，这个数一定会出现在中间位置。（但要进行判断，因为如果此数组不存在这样一个数，中间位置的数会出错）

//推荐的做法二：因为若存在这样一个数，则这个数个数>一半，与这个数不相等的数的个数<一半，所以若让不相等的数相互抵消，则最后剩下的一定是这个数。（但与推荐做法一相同，若不存在这样一个数，按照此法依然可以得到一个结果，所以要对最后的结果判断）
class Solution1 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int number;
		int count = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (count == 0)
			{
				number = numbers[i];
				count = 1;
			}
			else
			{
				if (number == numbers[i])
					count++;
				else
					count--;
			}
		}

		count = 0;
		for (int i = 0; i < numbers.size(); i++) 
			if (numbers[i] == number) 
				count++;

		if (count > numbers.size() / 2.0)
			return number;
		else
			return 0;
	}
};

int main()
{
	Solution s;
	cout << s.MoreThanHalfNum_Solution({ 1,2,3,2,2,2,5,4,2 }) << endl;
	Solution1 s1;
	cout << s1.MoreThanHalfNum_Solution({ 1,2,3,2,2,2,5,4,2 }) << endl;
    return 0;
}

