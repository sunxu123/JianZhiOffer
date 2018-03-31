// jianzhioffer二叉树的深度.cpp : Defines the entry point for the console application.
//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
int create_index;
TreeNode *create_binarytree(vector<int> in)
{
	create_index++;
	if (in[create_index])
	{
		TreeNode *node = new TreeNode(in[create_index]);
		node->left = create_binarytree(in);
		node->right = create_binarytree(in);

		return node;
	}
	else
		return NULL;
}

//我的做法，将深度作为函数参数递归。从前往后递归，从前往后递增
class Solution {
public:
	int maxd = 0;
	void my_depth(TreeNode * node, int d)
	{
		if (node->left)		my_depth(node->left, d + 1);
		else if (d > maxd)	maxd = d;
		if (node->right)	my_depth(node->right, d + 1);
		else if (d > maxd)	maxd = d;
	}
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)	return 0;
		my_depth(pRoot,1);
		return maxd;
	}
};

//推荐的做法：将深度作为参数返回，这样就不需要再创建一个函数，不需要全局变量。从前往后递归，从后往前递增
class Solution1 {
public:
	int TreeDepth(TreeNode* pRoot) {
		if (pRoot == NULL)		return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return left > right ? left + 1 : right + 1;
	}
};

int main()
{
		vector<int> create_in = { 1, 2, 3, 4, 0, 5, 6, 0, 0, 7, 0, 0, 8, 0, 0, 0, 9, 10, 0, 0, 11, 0, 0 };
		//vector<int> create_in={1,2,4,0,7,0,0,0,3,5,0,0,6,8,0,0,0};
		/*
		1
		2           9
		3           10      11
		4       8
		5
		6       7
		mid=4 6 5 7 3 8 2 1 10 9 11
		post=6 7 5 4 8 3 2 10 11 9 1
		*/
		TreeNode *root=NULL;
		create_index = 0;
		if (create_in[create_index] > 0)
		{
		root = new TreeNode(create_in[create_index]);
		root->left = create_binarytree(create_in);
		root->right = create_binarytree(create_in);
		}

		Solution s;
		cout << s.TreeDepth(root) << endl;
		Solution1 s1;
		cout << s1.TreeDepth(root) << endl;

    return 0;
}

