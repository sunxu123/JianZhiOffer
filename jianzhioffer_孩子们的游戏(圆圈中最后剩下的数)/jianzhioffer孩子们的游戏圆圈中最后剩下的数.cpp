// jianzhioffer孩子们的游戏圆圈中最后剩下的数.cpp : Defines the entry point for the console application.
/*
首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
/*
	n=1 -> 0
	n=2 m%n=1-> 1
	n=2 m%n=2-> 0
	n=3 m%n=1-> 0
	n=3 m%n=2-> 0
	n=3 m%n=3-> 0
*/
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0)
			return -1;

		vector<int> people(n);
		for (int i = 0; i < n; i++)
			people[i] = i;

		int last = 0;

		while (n > 1)
		{
			int index;
			index = (last + m-1)%n;
			people.erase(people.begin() + index);

			n--;
			last = index;
		}
		return people[0];
	}
};

int main()
{
	Solution s;

	cout << s.LastRemaining_Solution(5, 3) << endl;
    return 0;
}


