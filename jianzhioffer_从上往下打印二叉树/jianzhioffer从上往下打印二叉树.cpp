// jianzhioffer从上往下打印二叉树.cpp : Defines the entry point for the console application.
//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
/*
/*
			1
		2           9
	3           10      11
4       8
	5
6       7
pre=1   2  3 4 5 6 7 8   9 10 11
mid=4 6 5 7 3 8  2   1   10 9 11
pos=6 7 5 4 8 3 2   10 11 9   1

result=1 2 9 3 10 11 4 8 5 6 7

1->0
2 9->1
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
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
vector<int> pre_v;
vector<int> preTraverse_binarytree(TreeNode *root)
{
	if (root)
	{
		pre_v.push_back(root->val);
		preTraverse_binarytree(root->left);
		preTraverse_binarytree(root->right);
	}
	return pre_v;
}
vector<int> mid_v;
vector<int> midTraverse_binarytree(TreeNode *root)
{
	if (root)
	{
		midTraverse_binarytree(root->left);
		mid_v.push_back(root->val);
		midTraverse_binarytree(root->right);
	}
	return mid_v;
}


//由前序遍历与中序遍历的结果得到其前序的节点深度结果，再有深度和前序求出遍历结果
class Solution {
public:
	vector<int> depth;
	void my_PrintFromTopToBottom(vector<int> pre, vector<int> mid, int pre_l, int pre_r, int mid_l, int mid_r, int depth_i  )
	{
		if (pre_l > pre_r || mid_l > mid_r)
			return ;
		for (int i = mid_l; i <= mid_r; i++)
		{
			if (mid[i] == pre[pre_l])
			{
				depth[pre_l] = depth_i;
				//cout << "pre_l = " << pre_l <<"\t  depth_i = "<< depth_i << endl;
				/*for (auto iter = depth.begin(); iter != depth.end(); iter++)
					cout << *iter << "\t";
				cout << endl;*/
				my_PrintFromTopToBottom(pre, mid, pre_l + 1, pre_l + i - mid_l, mid_l, i - 1, ++depth_i);
				my_PrintFromTopToBottom(pre, mid, pre_l + i - mid_l + 1, pre_r, i + 1, mid_r, depth_i); //pre_r-pre_l == mid_r-mid_l
				break;
			}
		}
	}

	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> val;
		vector<int> pre = preTraverse_binarytree(root);
		vector<int> mid = midTraverse_binarytree(root);
		//vector<int> depth(pre.size(),0);
		for (int i = 0; i < pre.size(); i++)
			depth.push_back(0);
		if(root)
		{

			my_PrintFromTopToBottom(pre, mid, 0, pre.size()-1, 0, mid.size()-1, 0);

			/*for (auto iter = depth.begin(); iter != depth.end(); iter++)
				cout << *iter << "\t";
			cout << endl;*/

			bool end = true;
			int d = 0;
			while (end)
			{
				end = false;
				for (int i = 0; i < depth.size(); i++)
				{
					if (d == depth[i])
					{
						end = true;
						val.push_back(pre[i]);
					}
				}
				d++;
			}

			/*val.push_back(pre[0]);
			int left = 0;
			int right = mid.size();
			int position = -1;
			for (int i = 0; i < pre.size(); i++)
			{
				position = find_root(mid, left, right, pre[i]);
				right = position - 1;

				if (right>=left)
					val.push_back(pre[i]);

			}*/
		}
		return val;
	}
};

//推荐的做法：使用队列实现广度优先搜索
class Solution1 {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> val;
		queue<TreeNode* > node;
		TreeNode* temp;
		node.push(root);
		while (!node.empty())
		{
			temp = node.front();
			node.pop();
			if (temp == NULL)	continue;
			val.push_back(temp->val);
			node.push(temp->left);
			node.push(temp->right);
		}

		return val;
	}
};


int main()
{
	vector<int> create_in = { 1, 2, 3, 4, 0, 5, 6, 0, 0, 7, 0, 0, 8, 0, 0, 0, 9, 10, 0, 0, 11, 0, 0 };

	TreeNode *root=NULL;
	create_index = 0;
	if (create_in[create_index] > 0)
	{
	root = new TreeNode(create_in[create_index]);
	root->left = create_binarytree(create_in);
	root->right = create_binarytree(create_in);
	}


	Solution s;
	vector<int> result = s.PrintFromTopToBottom(root);

	for (auto iter = result.begin(); iter != result.end(); iter++)
		cout << *iter << "\t";
	cout << endl;

	Solution1 s1;
	vector<int> result1 = s1.PrintFromTopToBottom(root);

	for (auto iter = result1.begin(); iter != result1.end(); iter++)
		cout << *iter << "\t";
	cout << endl;

    return 0;
}

