// jianzhioffer对称的二叉树.cpp : Defines the entry point for the console application.
//请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。


#include "stdafx.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	bool my_fun(TreeNode * left_node, TreeNode * right_node)
	{
		if (left_node == NULL && right_node == NULL)
			return true;
		if (left_node != NULL && right_node != NULL)
		{
			if (left_node->val == right_node->val)//该节点相同，判断下一节点
				return  my_fun(left_node->left, right_node->right) && my_fun(left_node->right, right_node->left);
			else
				return false;
		}
		return false;
	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		return my_fun(pRoot->left, pRoot->right);
	}
};

int main()
{
	return 0;
}

