// jianzhioffer顺时针打印矩阵.cpp : Defines the entry point for the console application.
//
/*
1  2   3   4
5  6   7   8
9  10  11  12
13 14  15  16

1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
(0,0)、(0,1)、(0,2)、(0,n)

1->1
2->1
3->2
4->2
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

//我的做法，四个方向依次遍历
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) 
	{
		vector<int> val;
		int n = matrix.size();//行数，高
		int m = matrix[0].size();//列数，宽
		int cishu = n<m ? (n + 1) / 2 : (m + 1) / 2;
		int i, j;
		for (int cishu_index = 0; cishu_index < cishu; cishu_index++)
		{
			int jiange = cishu_index;//(jiange,jiange),(jiange,n-jiange),(n-jiange,n-jiange),(n-jiange,jiange)

			i = jiange;
			for (j = jiange; j < m - jiange; j++)
				val.push_back(matrix[i][j]);

			j = m - jiange - 1;
			for (i = jiange + 1; i < n - jiange; i++)
				val.push_back(matrix[i][j]);

			if (n - jiange - 1 > jiange)
			{
				i = n - jiange - 1;
				for (j = m - jiange - 1 - 1; j > jiange - 1; j--)
					val.push_back(matrix[i][j]);
			}

			if (jiange < m - jiange - 1)
			{
				j = jiange;
				for (i = n - jiange - 1 - 1; i > jiange; i--)
					val.push_back(matrix[i][j]);
			}
		}
		return val;
	}
};

//推荐的做法：无
int main()
{
	Solution s;
	//vector<int> a=s.printMatrix({{1, 2, 3, 4},{ 5, 6, 7, 8},{ 9, 10, 11, 12},{ 13, 14, 15, 16}});//[[1],[2],[3],[4],[5]]
	vector<int> a = s.printMatrix({ { 1 },{ 2 },{ 3 },{ 4 } });

	for (int i = 0; i<a.size(); i++)
		cout << a[i] << "\t";
	cout << endl;

	return 0;
}