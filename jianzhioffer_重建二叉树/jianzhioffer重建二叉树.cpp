// jianzhioffer重建二叉树.cpp : Defines the entry point for the console application.
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
		cout<<root->val<<"\t";
	}
}

//我的做法：左右子树递归
int find_root(vector<int> mid,int left,int right, int n)
{
	for (int i = left; i < right+1; i++)
		if (n == mid[i])
			return i;
	return -1;
}


vector<int> root_point;
int find_left_bound(int r)
{
	int max = 0;//默认是左边界
	for (int i = 0; i < root_point.size() - 1; i++)
	{
		if (root_point[i] > max && root_point[i] < r)
			max = root_point[i];
	}
	return max;
}

int max_ss = 0;
int find_right_bound(int r)
{
	int min = max_ss;//默认是右边界
	for (int i = 0; i < root_point.size() - 1; i++)
	{
		if (root_point[i] < min && root_point[i] > r)
			min = root_point[i];
	}
	return min;
}


vector<int> pre_ss;

int i = 0;
int end_flag=0;
TreeNode *create_node(vector<int> mid,int left,int right, int find)
{
	TreeNode * node;

	int states = find_root(mid,left,right, find);


/*	cout << "root_point:" << endl;
	for (int ddd = 0; ddd < root_point.size(); ddd++)
		cout << root_point[ddd] << "\t";
	cout << endl;
	cout << "left = " << left << "\t";
	cout << "right = " << right << "\t";
	cout << "find = " << find << "\t";
	cout << "states = " << states << endl;
	cout << "i = " << i << endl;*/



	if (states < 0)
	{
		--i;
		node = NULL;
	}
	else if(i==pre_ss.size()-1)
	{
		node = new TreeNode(find);
		end_flag = 1;
		node->left =NULL;
		node->right = NULL;
	}
	else{
		root_point.push_back(states);
		node = new TreeNode(find);

		node->left = create_node(mid, find_left_bound(states), states, pre_ss[++i]);
		if (!end_flag)
			node->right = create_node(mid, states, find_right_bound(states), pre_ss[++i]);
		else
			node->right = NULL;
	}


	return node;
}

TreeNode *create_binarytree_from_pre_and_mid(vector<int> pre, vector<int> mid)
{
	TreeNode * node;
	max_ss = mid.size();
	pre_ss = pre;
	node = create_node(mid, 0, mid.size() - 1, pre[i]);

	return node;
}
//推荐的做法：懂得前序、中序、后序中的位置的意义。并递归求解
class Solution {
public:
	TreeNode *my_create_binarytree_from_pre_and_mid(vector<int> pre, vector<int> mid, int pre_l, int pre_r, int mid_l, int mid_r)
	{
		if (pre_l > pre_r || mid_l > mid_r)
			return NULL;
		TreeNode *node = new TreeNode(pre[pre_l]);
		for (int i = mid_l; i <= mid_r; i++)
		{
			if (mid[i] == pre[pre_l])
			{
				node->left = my_create_binarytree_from_pre_and_mid(pre, mid, pre_l + 1, pre_l + i - mid_l, mid_l, i - 1);
				node->right = my_create_binarytree_from_pre_and_mid(pre, mid, pre_l + i - mid_l + 1, pre_r, i + 1, mid_r); //pre_r-pre_l == mid_r-mid_l

				/*
				前序：根-左-右
				中序：左-右-根
				左子树：startpre + 1，指的是前序遍历左子树的开始位置，即前序遍历根节点的下一个节点。
				i - startin，i指的是中序遍历根节点的位置，减去中序遍历开始位置即左子树的长度。
				所以i - startiin + starpre是前序遍历左子树结束的位置。
				右子树：i - startiin + starpre是前序遍历左子树结束的位置。
				所以右子树的位置范围为i - startiin + starpre+1到endPre
				*/
				break;
			}
		}
		return node;
	}

	TreeNode *create_binarytree_from_pre_and_mid(vector<int> pre, vector<int> mid)
	{
		return my_create_binarytree_from_pre_and_mid(pre, mid, 0, pre.size() - 1, 0, mid.size() - 1);
	}
};

int main()
{
	//vector<int> pre = { 1,2,4,7,3,5,6,8 };
	//vector<int> mid = { 4,7,2,1,5,3,8,6 };
	vector<int> pre = { 1,2,3,4 };
	vector<int> mid = { 4,3,2,1 };

	TreeNode *root = create_binarytree_from_pre_and_mid(pre, mid);

	preTraverse_binarytree(root);
	cout << endl;
	midTraverse_binarytree(root);
	cout << endl;

	root = NULL;
	Solution s;
	root = s.create_binarytree_from_pre_and_mid(pre, mid);
	
	preTraverse_binarytree(root);
	cout << endl;
	midTraverse_binarytree(root);
	cout << endl;

    return 0;
}

