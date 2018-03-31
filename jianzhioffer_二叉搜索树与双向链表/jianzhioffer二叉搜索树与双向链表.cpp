// jianzhioffer二叉搜索树与双向链表.cpp : Defines the entry point for the console application.
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

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
/*
					8
			6				10
		3		7		 9		13
	1	  5       

我的做法：	二叉搜索树：左<根<右
			所以刚开始一直向左，直到没有左子树为止，此时，
			若这个节点为左节点：的左为这个节点的左子节点，右为其跟，
			若这个节点为根节点：的左为这个节点的左子节点，右为其右子节点
			若这个节点为右节点：的左为这个节点的根节点，右为其跟的跟
*/
class Solution {
public:
	vector<TreeNode *> nodes;
	void my_fun(TreeNode * root)
	{
		if (root->left)		my_fun(root->left);
		nodes.push_back(root);
		if (root->right)	my_fun(root->right);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		my_fun(pRootOfTree);

		if (nodes.size()) < 2)
		return nodes;
		nodes[0]->left = NULL;
		nodes[0]->right = nodes[1];
		nodes.back()->left = nodes[nodes.size()-2];
		nodes.back()->right = NULL;
		for (int i = 1; i < nodes.size() - 1; i++)
		{
			nodes[i]->left = nodes[i - 1];
			nodes[i]->right = nodes[i + 1];
		}
	}
};

int main()
{
	return 0;
}

