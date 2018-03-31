// jianzhioffer平衡二叉树.cpp : Defines the entry point for the console application.
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
/*
	1,2,3,4,5,#,#,#,#,6
				1
			2		3
		4     5   
		     6

	1,2,3,4,5,#,6,#,#,7
				1
			2		3
		4	  5			6
			7
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

//我的做法：根据平衡二叉树的定义：它是一 棵空树或它的左右两个子树的高度差的绝对值不超过1，
//		所以对此二叉树和它的子树进行求高度差判断
//		这里采用从根向左右子树逐个子树判断
class Solution {
public:
	int tree_depth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int i = tree_depth(root->left);
		int j = tree_depth(root->right);
		return i>j?i+1:j+1;
	}
	bool IsBalanced_Solution(TreeNode* pRoot) 
	{
		int ld = 0;
		int rd = 0;
		if (pRoot)
		{
			ld = tree_depth(pRoot->left);
			rd = tree_depth(pRoot->right);
		}
		
		if (abs(ld - rd)>1)
			return false;
		if (pRoot)
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
		else
			return true;
	}
};

//推荐的做法：
//不推荐采用前序遍历，中序遍历，推荐后序遍历，因为前两种会造成重复计算子树高度
class Solution1 {
public:
	bool is_balanced = true;
	int my_fun(TreeNode * root)
	{
		if (root == NULL)
			return 0;
		int left = my_fun(root->left);
		int right = my_fun(root->right);
		if (abs(left - right)>1)
			is_balanced = false;
		return left<right ? right + 1 : left + 1;
	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		my_fun(pRoot);
		return is_balanced;
	}
};

int main()
{
	vector<int> create_in = { 1, 2, 4, 0, 0, 5, 6, 0, 0, 0,3,0,0};
	TreeNode *root = NULL;
	create_index = 0;
	if (create_in[create_index] > 0)
	{
		root = new TreeNode(create_in[create_index]);
		root->left = create_binarytree(create_in);
		root->right = create_binarytree(create_in);
	}

	Solution s;
	cout << s.IsBalanced_Solution(root) << endl;

    return 0;
}

