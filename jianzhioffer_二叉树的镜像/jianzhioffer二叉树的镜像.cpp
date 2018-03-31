// jianzhioffer二叉树的镜像.cpp : Defines the entry point for the console application.
//

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

void preTraverse_binarytree(TreeNode *root)//前序遍历
{
	if (root)
	{
		cout << root->val << "\t";
		preTraverse_binarytree(root->left);
		preTraverse_binarytree(root->right);
	}
}

void midTraverse_binarytree(TreeNode *root)//中序遍历
{
	if (root)
	{
		midTraverse_binarytree(root->left);
		cout << root->val << "\t";
		midTraverse_binarytree(root->right);
	}
}

void postTraverse_binarytree(TreeNode *root)//后序遍历
{
	if (root)
	{
		postTraverse_binarytree(root->left);
		postTraverse_binarytree(root->right);
		cout << root->val << "\t";
	}
}
//我的做法：递归交换
void Mirror(TreeNode *pRoot) 
{
	if (pRoot == NULL)
		return ;
	else
	{
		TreeNode *temp;
		temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
}
//推荐的做法：无

int main()
{
	vector<int> create_in = {8,6,5,0,0,7,0,0,10,9,0,0,11,0,0 };
	/*源二叉树
		  8
		 / \
		6   10
	   / \  / \
	  5  7  9 11
		镜像二叉树
		 8
		/ \
	   10   6
	   / \  / \
	   11 9 7  5
	   8 10 11 9 6 7 5
		*/
	TreeNode *root=NULL;
	create_index = 0;
	if (create_in[create_index] > 0)
	{
		root = new TreeNode(create_in[create_index]);
		root->left = create_binarytree(create_in);
		root->right = create_binarytree(create_in);
	}

	preTraverse_binarytree(root);
	cout << endl;

	Mirror(root);

	preTraverse_binarytree(root);
	cout << endl;

    return 0;
}

