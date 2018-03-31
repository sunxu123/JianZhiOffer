// jianzhioffer替换空格.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//我的做法：1、在main里定义str时，不可以用char* str=""，的方式，此方式等价于const char* str=""，其内容不可修改。
//		   2、也不可以用char str[]=""，的方式，否则strcpy()时会出现”在变量XX周围的堆栈已损坏“的问题。
//所以，必须预留足够的空间？？？所以可以直接在原字符串上修改？？？
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int i = 0;
		vector<int> i_position;
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
			{
				length += 2;
				i_position.push_back(i);
			}
			++i;
		}
		char *str1 = (char *)malloc(sizeof(char) * (length+1));
		i = 0;
		for (int j = 0; j<length; j++)
		{
			if ( i<i_position.size() && j - 2 * i == i_position[i])
			{
				/*str1[j] = '%%';
				str1[j + 1] = '2';
				str1[j + 2] = '0';此段可替换为下面
				j += 2;*/
				str1[j] = '%%';
				str1[ ++j] = '2';
				str1[ ++j] = '0';
				i++;
				
			}
			else
			{
				str1[j] = str[j - 2 * i];
			}
		}
		str1[length] = '\0';
		//cout << str1 << endl;
		strcpy_s(str, strlen(str1) + 1, str1);
	}
};

//简单做法：基于string类来实现
class Solution1 {
public:
	void replaceSpace(char *str, int length) {
		string s(str);
		int i = 0;
		while ((i = s.find(' ', i))>-1) {
			s.erase(i, 1);
			s.insert(i, "%20");

		}
		auto ret = s.c_str();
		strcpy_s(str, strlen(ret) + 1, ret);
	}
};

int main()
{
	char str[100] = "We Are Happy";

	Solution s;
	s.replaceSpace(str, strlen(str));
	cout << str << endl;

	char str2[100] = "We Are Happy";

	Solution1 s1;
	s1.replaceSpace(str2, strlen(str2));
	cout << str2 << endl;

    return 0;
}

