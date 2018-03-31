// jianzhioffer栈的压入弹出序列.cpp : Defines the entry point for the console application.
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的
/*
	1,2,3,4,5
	4,5,3,2,1
	4,3,5,1,2
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//我的做法：按出栈顺序判断出栈的元素在入栈的位置，如果相邻的两次出栈出现大于1的偏差，说明出错
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
	{
		int last_position = -1;
		int position;

		for (int i = 0; i < popV.size(); i++)
		{
			auto itor = find(pushV.begin(), pushV.end(), popV[i]);
			if (itor == pushV.end())
				return false;
			position = itor - pushV.begin();

			pushV.erase(itor);
			
			if (position < last_position - 1)
				return false;
			else
				last_position = position;
		}

		return true;
	}
};

//其他做法：按照出栈顺序模拟入栈
//注意这里第二个while循环的写法，很特殊，
class Solution1 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{

		vector<int> stack;
		int j = 0;
		for (int i = 0; i < pushV.size(); i++)
		{
			stack.push_back(pushV[i]);

			while (j<popV.size() && stack.back() == popV[j]) //注意：这里得把j<popV.size()，不然先取pop[j]会溢出
			{
				stack.pop_back();
				j++;
			}
		}

		return stack.empty();
	}
};

int main()
{
	vector<int> pushv = { 1, 2, 3, 4, 5 };
	vector<int> popv = { 4, 5, 3, 2, 1 };
	//vector<int> pushv = { 1 };
	//vector<int> popv = {2 };
	vector<int> popv1 = { 4,3,5,1,2 };

	Solution s;
	cout << s.IsPopOrder(pushv, popv) << endl;
	cout << s.IsPopOrder(pushv, popv1) << endl;
	Solution1 s1;
	cout << s1.IsPopOrder(pushv, popv) << endl;
	cout << s1.IsPopOrder(pushv, popv1) << endl;


    return 0;
}

