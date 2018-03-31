// jianzhioffer左旋转字符串.cpp : Defines the entry point for the console application.
//汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//我的做法：将字符串前半部分移到后面
class Solution {
public:
	string LeftRotateString(string str, int n) {
		int size = str.size();
		if (size == 0)
			return "";
		int abs = n%size;
		
		return str.substr(abs, size - abs) + str.substr(0, abs);
	}
};
//其他做法：将字符串后面补好，取指定位置
class Solution1 {
public:
	string LeftRotateString(string str, int n) {
		int size = str.size();
		if (size == 0)
			return "";
		str += str;
		return str.substr(n%size, size);
	}
};


int main()
{
	Solution s;
	cout << s.LeftRotateString("abcXYZdef", 3) << endl;;
    return 0;
}

