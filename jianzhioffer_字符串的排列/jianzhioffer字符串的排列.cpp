// jianzhioffer字符串的排列.cpp : Defines the entry point for the console application.
//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

template <typename Type>
void print_vector(vector<Type> result)
{
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "  ";
	cout << endl;
}

class Solution {
public:
	vector<string> result;
	void my_fun(string str,string  one,vector<int>  used)
	{
		bool flag = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (find(used.begin(), used.end(), i) == used.end())
			{
				flag = true;
				vector<int> used1 = used;
				string one1 = one;
				used1.push_back(i);
				one1.push_back(str[i]);
				my_fun(str, one1, used1);
			}
		}
		if (flag == false)
		{
			if(find(result.begin(), result.end(), one) == result.end())
			result.push_back(one);
		}
	}
	vector<string> Permutation(string str) {
		if (str == "")
			return result;
		
		sort(str.begin(), str.end());//排序

		for (int i = 0; i < str.size(); i++)//创建排列
		{
			string one;
			vector<int> used;
			used.push_back(i);
			one.push_back(str[i]);
			my_fun(str,one,used);
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<string> result = s.Permutation("cbca");

	print_vector( result);

    return 0;
}

