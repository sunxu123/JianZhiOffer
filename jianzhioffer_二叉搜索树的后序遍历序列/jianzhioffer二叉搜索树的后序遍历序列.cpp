// jianzhioffer二叉搜索树的后序遍历序列.cpp : Defines the entry point for the console application.
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
/*
[7,4,6,5]	false
[4,8,6,12,16,14,10]	true

				  5
			3			9
		2	   4	
		pos = 2 4 3 9 5
		1						5
		 2					   4
		  3					  3
		   4			     2
		    5			    1
		pos= 5 4 3 2 1     1 2 3 4 5 
		
		root = sequence.back()
		left = 4
		right= 7 6
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//我的做法：根据后序遍历的特点，前一半是左子树，右一半是右子树，最后一个是跟，且根据二叉搜索树的特点，左子树<跟，右子树>跟，所以递归判断即可
class Solution {
public:
	bool my_VerifySquenceOfBST(vector<int> sequence,int left,int right)
	{
		//if (left > right)
		//	return true;
			//left = right;
		int root = right;
		for (int it = left; it < right; it++)
		{
			if (sequence[it] > sequence[right])
			{
				cout << "sequence[it]=" << sequence[it] << endl;
				cout << "it=" << it << endl;
				root = it;
				break;
			}
		}
		for (int i = left; i < root; i++)
		{
			if (sequence[i] > sequence[root])
			{
				cout << "left wrong" << endl;
				return false;
			}
		}
		for (int i = root; i < right; i++)
		{
			cout << "sequence[i] , sequence[right]" << sequence[i] << "-" << sequence[right]<< endl;
			if (sequence[i] < sequence[right])//注意右子树的根是sequence[right]，而不是sequence[root]
			{
				cout << "right wrong" << endl;
				return false;
			}
		}

		if (left < root - 1)
		{
			if (my_VerifySquenceOfBST(sequence, left, root - 1) == false)
				return false;
		}
		//return my_VerifySquenceOfBST(sequence, left, root - 1);
		if (root<right - 1) {
			if (my_VerifySquenceOfBST(sequence, root, right - 1) == false)
				return false;
		}
		//return my_VerifySquenceOfBST(sequence, root, right-1);
		return true;

	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		return my_VerifySquenceOfBST(sequence,0, sequence.size()-1);
	}
};

//推荐的做法

int main()
{
	Solution s;
	cout << s.VerifySquenceOfBST({ 7, 4, 6, 5 }) << endl;
	cout << s.VerifySquenceOfBST({ 4,8,6,12,16,14,10 }) << endl;
	cout << s.VerifySquenceOfBST({ 5,4,3,2,1 }) << endl;

    return 0;
}

