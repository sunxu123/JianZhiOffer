// jianzhioffer第一个只出现一次的字符.cpp : Defines the entry point for the console application.
//在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
/*
	google -->4
*/

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>

using namespace std;

//我的做法：这道题无论采用vector下标计数也好，map计数也好，关键在于第二次迭代要迭代string,而不是迭代count
class Solution {
public:
	int FirstNotRepeatingChar(string str) {

		map<int,int> count;
		for (int i = 0; i < str.size(); i++)
			count[str[i]] ++;

		for (int i = 0; i < str.size(); i++)
			if (count[str[i]] == 1)
				return i;

		return 0;
	}
};

//推荐的做法：无

int main()
{
	Solution s;
	cout << s.FirstNotRepeatingChar("NXWtnzyoHoBhUJaPauJaAitLWNMlkKwDYbbigdMMaYfkVPhGZcrEwp") << endl;
	cout << s.FirstNotRepeatingChar("google") << endl;

    return 0;
}

