// jianzhioffer数字在排序数组中出现的次数.cpp : Defines the entry point for the console application.
//统计一个数字在排序数组中出现的次数。

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//我的做法：顺序查找
class Solution1 {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int begin_position = -1;
		int end_position = -1;

		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] == k)
			{
				if(begin_position < 0)
					begin_position = i;
			}
			else if(data[i]>k)
			{
				if (begin_position >= 0 && end_position < 0)
				{
					end_position = i;
					break;
				}
			}
		}
		if (begin_position >= 0 && end_position < 0)
			return data.size() - begin_position;
		else
		return end_position-begin_position;
	}
};


//在有序数组中查找某元素的起点和终点，推荐二分查找
//mid=(start+end)/2，这是一个存在潜在风险的写法，因为如果数组长度非常大，start+end就有可能会溢出，所以写法改为 mid=start+(end-start)/2，才算完美。
class Solution {
public:
	int get_begin(vector<int> data, int k)
	{
		int low = 0;
		int high = data.size();

		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (data[mid] > k)
				high = mid - 1;
			else if (data[mid] < k)
				low = mid + 1;
			else//已经找到k，找第一个k 
			{
				if (low == mid || (data[mid - 1] != k))//low==mid有两种情况：low=high,low+1=high
					return mid;
				high = mid - 1;
			}
		}
		return -1;
	}
	int get_end(vector<int> data, int k)
	{
		int low = 0;
		int high = data.size();

		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (data[mid] > k)
				high = mid - 1;
			else if (data[mid] < k)
				low = mid + 1;
			else//已经找到k，找最后一个k 
			{
				if (mid == high || (data[mid + 1] != k))//data[mid+1] != k为了防止mid+1=high的情况
					return mid;
				low = mid + 1;
			}
		}
		return -1;
	}
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		int begin_position = get_begin(data, k);
		int end_position = get_end(data, k);
		if (begin_position >= 0 && end_position >= 0)
			return end_position - begin_position + 1;
		else
			return 0;
	}
};


int main()
{
	Solution s;
	cout << s.GetNumberOfK({ 1,2,3,3,3,3,4,5 }, 3) << endl;
    return 0;
}

