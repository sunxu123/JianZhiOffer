// jianzhioffer把数组排成最小的数.cpp : Defines the entry point for the console application.
//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//我的做法：从每个数字的最高位开始判断，找最小的
/*
{ 3,5,1,4,2 }
从最高位开始找最小的，
如果有唯一最小值，则将这个数取走。继续对这一位判断，一直到这一位没有唯一最小值为止
如果这一位没有唯一最小值，则将这几个最小值取出来，对这几个数的下一位进行判断
一直循环到所有位都被取走
{33,32,41}
如果其中某个数不存在下一位，如果其他数的后面所有位都比这个数的最后一位小，则把这个数放到后面，否则把这个数放到前面
3334,3,3333332 = 3333332 3 3334
3,323,32123 = 32123 323 3
*/
class Solution1 {
public:
	string result;
	void my_fun(vector<string> &strs, vector<string> &revised_strs, int i, int max_size)
	{
		if (i < max_size)
		{
			vector<int> min_ids;
			char min = 'a';
			for (int j = 0; j < revised_strs.size(); j++)//指定位找最小
			{
				if (revised_strs[j][i] < min)
				{
					min = revised_strs[j][i];
					min_ids.clear();
					min_ids.push_back(j);
				}
				else if (revised_strs[j][i] == min)
					min_ids.push_back(j);
			}
			if (min_ids.size() == 1)//找到唯一最小，则放到输出字符串中，并删掉这个数
			{
				result += strs[min_ids.back()];
				revised_strs[min_ids.back()] = "";
				for (int i = 0; i < max_size; i++)
					revised_strs[min_ids.back()].push_back('b');
				my_fun(strs, revised_strs, i, max_size);
			}
			else if (min_ids.size() > 1)//非唯一最小
			{
				if (i != max_size - 1)
				{
					vector<string> revised_strs_temp;//先在小的里面找最小的
					for (int k = 0; k < revised_strs.size(); k++)
					{
						string temp = "";
						for (int i = 0; i < max_size; i++)
							temp += 'b';
						revised_strs_temp.push_back(temp);
					}
					for (int k = 0; k < min_ids.size(); k++)
						revised_strs_temp[min_ids[k]] = revised_strs[min_ids[k]];

					my_fun(strs, revised_strs_temp, i + 1, max_size);

					vector<string> revised_strs_temp1;//再在剩余的大的里面找小的
					for (int k = 0; k < revised_strs.size(); k++)
					{
						string temp = "";
						for (int i = 0; i < max_size; i++)
							temp += 'b';
						revised_strs_temp1.push_back(temp);
					}
					for (int k = 0; k < revised_strs.size(); k++)
						if (find(min_ids.begin(), min_ids.end(), k) == min_ids.end())
							revised_strs_temp1[k] = revised_strs[k];

					my_fun(strs, revised_strs_temp1, i + 1, max_size);
				}
				else//针对如果两个数增大之后相等的情况，比如 1,11,111
					for (int i = 0; i < min_ids.size(); i++)
						result += strs[min_ids[i]];
			}
		}
	}
	string PrintMinNumber(vector<int> numbers) {
		int n = numbers.size();
		result = "";
		vector<string> strs(n);
		vector<string> revised_strs(n);
		int max_size = 0;
		for (int i = 0; i < n; i++)
		{
			strs[i] = to_string(numbers[i]);
			if (strs[i].size() > max_size)
				max_size = strs[i].size();
		}

		for (int i = 0; i < n; i++)
		{
			revised_strs[i] = strs[i];
			for (int j = strs[i].size(); j < max_size; j++)
				revised_strs[i] += strs[i].back();
		}
		my_fun(strs, revised_strs, 0, max_size);

		return result;
	}
};

/*推荐的做法：
要比较组合的情况，即对两个数{33,32}比较3332与3233哪个小，3233小,所以{32,33}，同理，找到最小的
sort中的比较函数compare要声明为静态成员函数或全局函数，不能作为普通成员函数，否则会报错。 
因为：非静态成员函数是依赖于具体对象的，而std::sort这类函数是全局的，因此无法再sort中调用非静态成员函数。
静态成员函数或者全局函数是不依赖于具体对象的, 可以独立访问，无须创建任何对象实例就可以访问。同时静态成员函数不可以调用类的非静态成员。
*/
class Solution {
public:
	static bool my_comp(string a, string b)
	{
		return (a + b<b + a) ? true : false;//按从小到大排序
	}
	string PrintMinNumber(vector<int> numbers) {
		int n = numbers.size();
		string result;
		vector<string> strs(n);
		for (int i = 0; i<n; i++)
			strs[i] = to_string(numbers[i]);
		sort(strs.begin(), strs.end(), my_comp);
		for (int i = 0; i<n; i++)
			result += strs[i];
		return result;
	}
};


int main()
{
	Solution s;
	//cout << s.PrintMinNumber({ 3,32,321 }) << endl;
	//cout << s.PrintMinNumber({ 3,5,1,4,2 }) << endl;
	//cout << s.PrintMinNumber({ 3334,3,3333332 }) << endl;
	//cout << s.PrintMinNumber({ 3,323,32123 }) << endl;
	cout << s.PrintMinNumber({ 1,11,111 }) << endl;
	return 0;
}

