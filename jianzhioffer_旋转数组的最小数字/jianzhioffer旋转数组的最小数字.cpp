// jianzhioffer旋转数组的最小数字.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

//我的做法：顺序查找
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size()==0)
			return 0;
		int min=rotateArray[0];
		for (int i = 0; i < rotateArray.size(); i++)
		{
			if (rotateArray[i] < min)
				return rotateArray[i];
		}
		return min;
	}
};

//推荐的做法：二分查找法。因为最小值极有可能出现在中间位置。所以二分查找会带来更高的效率
class Solution1 {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int left = 0;
		int right = rotateArray.size();
		int mid = 0;
		int min = rotateArray[0];
		while (left <= right)
		{
			//cout << "left = " << left << "  right = " << right << endl;
			mid = (left + right) / 2;
			if (min > rotateArray[mid])
			{
				right = mid-1;
				min = rotateArray[mid];
			}
			else
			{
				left = mid+1;
			}
		}
		
		return min;
	}
};

int main()
{
	vector<int> rotateArray = { 6501, 6828, 6963, 7036, 7422, 7674, 8146, 8468, 8704, 8717, 9170, 9359, 9719, 9895, 9896, 9913, 9962, 154, 293, 334, 492, 1323, 1479, 1539, 1727, 1870, 1943, 2383, 2392, 2996, 3282, 3812, 3903, 4465, 4605, 4665, 4772, 4828, 5142, 5437, 5448, 5668, 5706, 5725, 6300, 6335 };

	Solution s;
	cout << "min = " << s.minNumberInRotateArray(rotateArray) << endl;
	Solution1 s1;
	cout << "min = " << s1.minNumberInRotateArray(rotateArray) << endl;
    return 0;
}

