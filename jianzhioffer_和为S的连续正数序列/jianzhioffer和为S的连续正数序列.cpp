// jianzhioffer和为S的连续正数序列.cpp : Defines the entry point for the console application.
//找出所有和为S的连续正数序列（至少包括两个数）?输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/*

*/
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > result;
		int high = sum / 2 + 1;
		int low = 1;
		bool falg = true;
		while (falg)
		{
			falg = false;
			int temp_sum = 0;
			vector<int> temp;
			for (int i = low; i <=high; i++)
			{
				temp.push_back(i);
				temp_sum += i;
				if (temp_sum == sum)
				{
					result.push_back(temp);
					falg = true;
					break;
				}
				else if (temp_sum > sum)
				{
					falg = true;
					break;
				}
			}
			low++;
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<int> > result = s.FindContinuousSequence(100);

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
    return 0;
}

