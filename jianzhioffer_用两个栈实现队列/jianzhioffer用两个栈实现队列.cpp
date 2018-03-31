// jianzhioffer用两个栈实现队列.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

//我的做法：下次push前如果上次的栈还没有出空，则把它倒回到入栈里面去。
class Solution
{
public:
	void push(int node) {
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.push(node);
	}

	int pop() {

		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int value = stack2.top();
		stack2.pop();
		return value;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

//推荐的做法：下次push前如果上次的栈还没有出空，则下次pop时继续从原出栈里继续出栈，出空了之后才重新计算出栈。
class Solution1
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int value = stack2.top();
		stack2.pop();
		return value;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};


int main()
{
	Solution s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << s.pop() << "\t";
	cout << s.pop() << "\t";
	cout << s.pop() << "\t";
	//cout << endl;

	s.push(6);
	s.push(7);

	cout << s.pop() << "\t";
	cout << s.pop() << "\t";
	cout << s.pop() << "\t";
	cout << s.pop() << "\t";
	cout << endl;


	Solution1 s1;

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);

	cout << s1.pop() << "\t";
	cout << s1.pop() << "\t";
	cout << s1.pop() << "\t";
	//cout << endl;

	s1.push(6);
	s1.push(7);

	cout << s1.pop() << "\t";
	cout << s1.pop() << "\t";
	cout << s1.pop() << "\t";
	cout << s1.pop() << "\t";
	cout << endl;

	return 0;
}

