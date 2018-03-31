// jianzhioffer丑数.cpp : Defines the entry point for the console application.
//把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

/*
	1--1
	2--2
	3--3
	4--4
	5--5
	6--6
	7--8
	8--9
	9--10
	10--12
	11--15
	1500--859963392
*/
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//我的做法：从1开始，用求因子的方式判断每一个数是不是丑数
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		vector<int> inzi_good = { 2,3,5 };//1 2 3 5 7 11 13 17 29
		vector<int> inzi = { 7 };
		int num = 1;
		index--;
		while (index)
		{
			num++;

			//cout << "num =" << num << endl;

			bool maybe = false;
			bool is_ugly = true;
			for (int i = 0; i < inzi_good.size(); i++)//如果这个数存在2.3.5.因子
			{
				if (num % inzi_good[i] == 0)
				{
					maybe = true;
					break;
				}
			}

			//cout << "maybe =" << maybe << endl;

			if (maybe != false)
			{	//break;
				for (int j = 0; j < inzi.size(); j++)
				{
					if (num > inzi.back())//数字比最大的因子还大，则要找下一个因子
					{
						int temp_inzi = inzi.back() + 1;
						//cout << "temp_inzi = " << temp_inzi << endl;
						while (temp_inzi < num)
						{
							bool is_inzi = true;
							for (int i = 0; i < inzi_good.size(); i++)
							{
								if (temp_inzi %inzi_good[i] == 0)
								{
									is_inzi = false;
									break;
								}
							}
							for (int i = 0; i < inzi.size(); i++)
							{
								if (temp_inzi %inzi[i] == 0)
								{
									is_inzi = false;
									break;
								}
							}
							if (is_inzi)
							{
								inzi.push_back(temp_inzi);
								//cout << "temp_inzi = " << temp_inzi << endl;
							}
							temp_inzi++;
						}
					}

					if (num < inzi[j])
						break;

					if (num % inzi[j] == 0)
					{
						is_ugly = false;
					}
				}
				//cout << "is_ugly =" << is_ugly << endl;
				if (is_ugly)
					index--;
			}
		}

		return num;
	}
};
//简化版本1：如果p是丑数，那么p=2^x * 3^y * 5^z
/*
由于1是最小的丑数，那么从1开始，把2*1，3*1，5*1，进行比较，得出最小的就是1
的下一个丑数，也就是2*1，
    这个时候，多了一个丑数‘2’，也就又多了3个可以比较的丑数，2*2，3*2，5*2，
	这个时候就把之前‘1’生成的丑数和‘2’生成的丑数加进来也就是
	(3*1,5*1,2*2，3*2，5*2)进行比较，找出最小的。。。。如此循环下去就会发现，
	每次选进来一个丑数，该丑数又会生成3个新的丑数进行比较。
	*/
class Solution2 {
public:
	int find_vector_min(vector<long long> &v)
	{
		long long min = v[0];
		int min_id = 0;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] < min)
			{
				min = v[i];
				min_id = i;
			}
			else if (v[i] == min)
				v.erase(v.begin() + i);
		}
		return min_id;
	}

	int GetUglyNumber_Solution(int index) {
		if (index == 0)
			return 0;
		vector<int> UglyNumber(index, 0);
		vector<long long> possible = { 1 };

		for (int i = 0; i<index; i++)
		{
			int min_id = find_vector_min(possible);
			UglyNumber[i] = possible[min_id];
			possible.push_back(possible[min_id] * 2);
			possible.push_back(possible[min_id] * 3);
			possible.push_back(possible[min_id] * 5);
			possible.erase(possible.begin() + min_id);

		}
		//print_vector(UglyNumber);
		return UglyNumber.back();
	}
};
//简化版本2：版本1中存在的问题是possible中要比较的数会越来越多（因为每加一个丑数，就要加3个possisle的丑数）
//          但其实
/*          例如：  Ugly = 1     possible = 2,3,5
Ugly = 1 2   possible = 3,5  ,4,6,10
但其实6,10是没有必要拿进来比较的，因为Ugly[0]<Ugly[1],则Ugly[0]*3<Ugly[1]*3、Ugly[0]*5<Ugly[1]*5
所以，真正要比较的是：
Ugly = 1        possible = 2,3,5    Ugly[0]*2, Ugly[0]*3, Ugly[0]*5
Ugly = 1 2      possible = 3,5,4    Ugly[0]*3, Ugly[0]*5, Ugly[1]*2,
Ugly = 1 2 3    possible = 5,4,6    Ugly[1]*3, Ugly[0]*5, Ugly[1]*2,
所以，当前取得是*几作为丑数，则下次就比较下一个丑数×几
*/
class Solution1 {
public:
	int min_3(int a, int b, int c)
	{
		int temp = a<b ? a : b;
		return temp<c ? temp : c;
	}
	int GetUglyNumber_Solution(int index) {
		if (index == 0)
			return 0;
		vector<int> UglyNumber(index, 0);
		UglyNumber[0] = 1;
		int index_2 = 0;
		int index_3 = 0;
		int index_5 = 0;
		for (int i = 1; i<index; i++)
		{
			UglyNumber[i] = min_3(UglyNumber[index_2] * 2, UglyNumber[index_3] * 3, UglyNumber[index_5] * 5);
			if (UglyNumber[i] == UglyNumber[index_2] * 2)    index_2++;
			if (UglyNumber[i] == UglyNumber[index_3] * 3)    index_3++;
			if (UglyNumber[i] == UglyNumber[index_5] * 5)    index_5++;
		}
		return UglyNumber.back();
	}
};

int main()
{
	Solution s;
	/*cout << s.GetUglyNumber_Solution(1) << endl;
	cout << s.GetUglyNumber_Solution(2) << endl;
	cout << s.GetUglyNumber_Solution(3) << endl;
	cout << s.GetUglyNumber_Solution(4) << endl;
	cout << s.GetUglyNumber_Solution(5) << endl;
	cout << s.GetUglyNumber_Solution(6) << endl;
	cout << s.GetUglyNumber_Solution(7) << endl;
	cout << s.GetUglyNumber_Solution(8) << endl;
	cout << s.GetUglyNumber_Solution(9) << endl;
	cout << s.GetUglyNumber_Solution(10) << endl;
	cout << s.GetUglyNumber_Solution(11) << endl;*/
	//cout << s.GetUglyNumber_Solution(1500) << endl;

	for (int i = 1; i < 50; i++)
	{
		cout << i << "\t" << s.GetUglyNumber_Solution(i) << endl;
	}

    return 0;
}

