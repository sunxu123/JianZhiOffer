// jianzhioffer翻转单词顺序列.cpp : Defines the entry point for the console application.
//例如，“student. a am I”。正确的句子应该是“I am a student.”。

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//我的做法：把字符移位，空间复杂度n
class Solution1 {
public:
	string ReverseSentence(string str) {
		string result = "";
		int lastposition = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				if (lastposition)
					result = str.substr(lastposition, i - lastposition + 1) + result;
				else
					result = str.substr(lastposition, i - lastposition) + result;//第一个字符，不需要在后面补空格
				lastposition = i + 1;
			}
		}
		if (str.size() - lastposition >= 0)
		{
			if (lastposition)
				result = str.substr(lastposition, str.size() - lastposition) + ' ' + result;//如果只有一个单词，不需要在后面补空格
			else
				result = str.substr(lastposition, str.size() - lastposition) + result;
		}
		return result;
	}
};


//推荐的做法：空间复杂度为1
//两次翻转，先翻转整个句子，再翻转每个单词
class Solution {
public:
	string ReverseSentence(string str)
	{
		reverse(str.begin(), str.end());
		int low = 0;
		int high = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				high = i;
				reverse(str.begin() + low, str.begin() + high);
				low = high + 1;
			}
		}
		reverse(str.begin() + low, str.begin() + str.size());

		return str;
	}
};
int main()
{
	Solution s;
	cout << s.ReverseSentence("student. a am I") << endl;
	cout << s.ReverseSentence("I am a student.") << endl;

    return 0;
}

