// jianzhioffer最小的K个数.cpp : Defines the entry point for the console application.
//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
/*

*/

#include "stdafx.h"

#include<iostream>
#include<vector>

using namespace std;
//我的做法：类似于冒泡
class Solution {
public:
	int fmax(vector<int> v)
	{
		int max1 = v[0];
		int id = 0;
		for (int i = 0; i<v.size(); i++)
		{
			if (v[i]>max1)
			{
				max1 = v[i];
				id = i;
			}
		}
		return id;
	}
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result;
		if (k == input.size())
			return input;
		if (k <= 0 || k>input.size())
			return result;
		for (int i = 0; i<k; i++)
			result.push_back(input[i]);
		int max_id = fmax(result);
		for (int i = k; i<input.size(); i++)
		{
			if (input[i]<result[max_id])
			{
				result[max_id] = input[i];
				max_id = fmax(result);
			}
		}
		return result;
	}
};

//推荐的做法：这种求前几大或前几小的一般都是用堆排序来实现，时间复杂度为log(n)*(n/2+k)
//			按从小到大排序要最大堆，但求前k个最小值要用最小堆
class Solution1
{
public:
	void Min_Fix_Heap(vector<int> &input, int i, int n)
	{
		int index = i;
		int temp;
		while (index < n)
		{
			index = index * 2 + 1;
			if (index < n && input[i] > input[index])
			{
				temp = input[i];
				input[i] = input[index];
				input[index] = temp;
				Min_Fix_Heap(input, index, n);
			}
			index++;
			if (index < n && input[i] > input[index])
			{
				temp = input[i];
				input[i] = input[index];
				input[index] = temp;
				Min_Fix_Heap(input, index, n);
			}
			if (input[i] <= input[index])
				break;
		}
	}
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> result;
		int size = input.size();
		if (k>size)
			return result;
		for (int i = (size - 1) / 2; i >= 0; i--)
		{
			Min_Fix_Heap(input, i, size);
		}

		int temp;
		while (k--)
		{
			result.push_back(input[0]);
			input[0] = input[--size];
			Min_Fix_Heap(input, 0, size);
		}

		return result;
	}
};


int main()
{
	Solution s;
	vector<int> v = s.GetLeastNumbers_Solution({ 4,5,1,6,2,7,3,8 }, 4);

	for (int i = 0; i<v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;

	Solution1 s1;
	vector<int> v1 = s1.GetLeastNumbers_Solution({ 4, 5, 1, 6, 2, 7, 3, 8 }, 4);

	for (int i = 0; i<v1.size(); i++)
		cout << v1[i] << "\t";
	cout << endl;

	return 0;
}