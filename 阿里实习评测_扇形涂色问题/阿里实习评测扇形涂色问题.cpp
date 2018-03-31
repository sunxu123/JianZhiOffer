// 阿里实习评测扇形涂色问题.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int fun(int n, int m) {
	int r;
	if (n == 1) r = m;
	else if (n == 2) r = m * (m - 1);
	else if (n == 3) r = m * (m - 1)*(m - 2);
	else {
		r = fun(n - 1, m)*(m - 2) + fun(n - 2, m)*(m - 1);
	}
	return r;
}
int my_fun(int n, int m) {
	if (n == 1)
		return m;
	if (n == 2)	
		return m*(m - 1);
	if (n == 3)	
		return m*(m - 1)*(m - 2);
	return	(m-1) * 1 * my_fun(n-2,m) + (m-2)*my_fun(n-1,m);//对倒数第二个扇形分为与第一个扇形是否相等两种情况
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << "m=" << m << "n=" << n << endl;
	cout << fun(n, m) << endl;
	cout <<my_fun(n,m) << endl;
	return 0;
}

