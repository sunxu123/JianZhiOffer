// jianzhioffer扑克牌顺子.cpp : Defines the entry point for the console application.
//
/*
一副牌原本是54张,随机从中抽出了5张牌,大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size()<5)
			return false;

		int sum = count(numbers.begin(), numbers.end(), 0);
		sort(numbers.begin(), numbers.end());

		int index = sum;
		int temp1 = 0;
		for (int i = index + 1; i < numbers.size(); i++)
		{
			int temp = numbers[i] - numbers[index] + index - i - temp1;
			temp1 += temp;
			if (temp < 0)
				return false;
			if (temp>0)
			{
				sum -= temp;
				if (sum < 0)
					return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.IsContinuous({ 1,3,2,6,4 }) << endl;//false
	cout << s.IsContinuous({ 1,3,2,5,4 }) << endl;//ture
	cout << s.IsContinuous({ 0,3,2,6,4 }) << endl;//ture
	cout << s.IsContinuous({ 1,3,0,7,0 }) << endl;//false
	cout << s.IsContinuous({ 1,0,0,1,0 }) << endl;//false
    return 0;
}

