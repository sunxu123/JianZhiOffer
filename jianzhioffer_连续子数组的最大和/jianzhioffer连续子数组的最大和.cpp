// jianzhioffer连续子数组的最大和.cpp : Defines the entry point for the console application.
//需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？(子向量的长度至少是1)
/*
	例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
	{ 1,-2,3,10,-4,7,2,-5 }  -> 3 10 -4 7 2 ==18
	{ -2, -8, -1, -5, -9 }  -> -1
*/
#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

//我的解法：从前往后，从第一个正数开始作为初始最大值，如果右边是正，则，最大值+，如果右边为负值，则计算初始最大值一直加到下一个正数位置时是正是负，是正，则保留，是负，就丢弃（因为前面这部分对后面没有正贡献），从这个新的正数开始重复上述过程（注意，每次丢弃前，应该把旧的最大值保留下来，因为有可能后面部分最大值还没前面这部分大）
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max = 0;
		int area_max = 0;
		int temp_sum = 0;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] > 0 && temp_sum > 0)
			{
				//area_max += temp_sum;
				area_max = array[i] + temp_sum;
				temp_sum += array[i];
			}
			if (array[i] > 0 && temp_sum == 0)//此段的第一个正数
			{
				area_max += array[i];
				temp_sum += array[i];
			}
			
			if (array[i] < 0 && temp_sum != 0)
			{
				temp_sum += array[i];
			}
			if (array[i] < 0 && temp_sum == 0)
			{
				continue;
			}
			if (array[i] > 0 && temp_sum < 0)
			{
				if(area_max>max)
				max = area_max;
				area_max = array[i];
				temp_sum = array[i];
			}

		}
		if (area_max>max)
			max = area_max;
		if (max == 0)//如果输入全为负，则返回负的最大
		{
			max = array[0];
			for (int i = 0; i<array.size(); i++)
			{
				if (array[i]>max)
					max = array[i];
			}
		}
		return max;
	}
};

//推荐的做法：同样是要一个max和一个临时max,并默认它们是第一个元素，如果tempmax+下个元素小于tempmax,则最大为下个元素
class Solution1 {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max = array[0];
		int temp = array[0];
		for (int i = 1; i<array.size(); i++)
		{
			temp = temp + array[i]<array[i] ? array[i] : temp + array[i];
			max = max>temp ? max : temp;
		}
		return max;
	}
};


int main()
{
	Solution s;
	cout << s.FindGreatestSumOfSubArray({ 6,-3,-2,7,-15,1,2,2 }) << endl;
	cout << s.FindGreatestSumOfSubArray({ 1,-2,3,10,-4,7,2,-5 }) << endl;
		cout << s.FindGreatestSumOfSubArray({ -2, -8, -1, -5, -9 }) << endl;

    return 0;
}

