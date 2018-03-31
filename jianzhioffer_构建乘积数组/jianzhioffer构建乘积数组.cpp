// jianzhioffer构建乘积数组.cpp : Defines the entry point for the console application.
//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
/*
测试用例:
[1,2,3,4,5]

对应输出应该为:

[120,60,40,30,24]

*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/*
	b[0]=a[1]*a[2]……a[n-1]//缺a[0]
	b[1]=a[0]*a[2]……a[n-1]//缺a[1]
	b[2]=a[0]*a[1]……a[n-1]//缺a[2]
*/
class Solution {
public:
	int my_fun(int index, int mul, const vector<int>& A, vector<int>& result)
	{
		if (index < A.size() - 1)
		{
			int temp = my_fun(index + 1, mul*A[index], A, result);//一路从前往后乘
			result[index] = mul *temp;
			return temp*A[index];//一路从后往前乘
		}
		else
		{
			result[index] = mul;
			return A[index];
		}
	}
	vector<int> multiply(const vector<int>& A) {
		vector<int> result(A.size());
		my_fun(0, 1, A, result);
		return result;
	}
};

int main()
{
	Solution s;
	
	vector<int> result = s.multiply({ 1,2,3,4,5 });

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "  ";
	cout << endl;

    return 0;
}

