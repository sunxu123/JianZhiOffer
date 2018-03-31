// jianzhioffer包含min函数的栈.cpp : Defines the entry point for the console application.
//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//这题到底是啥意思？
class Solution {
public:
	vector<int> stack;
	void push(int value) {
		stack.push_back(value);
	}
	void pop() {
		stack.erase(stack.end()-1);
	}
	int top() {
		return stack.back();
	}
	int min() {
		int min = stack[0];
		for (auto it = stack.begin(); it < stack.end(); it++)
		{
			if (*it < min)
				min = *it;
		}
		return min;
	}
};

int main()
{
	Solution s;
	s.push(2);
	s.push(3);
	cout << s.min() << endl;
	cout << s.top()<<endl;
	s.pop();
	s.push(4);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
    return 0;
}

