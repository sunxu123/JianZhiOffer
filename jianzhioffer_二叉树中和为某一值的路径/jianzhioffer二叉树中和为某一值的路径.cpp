// jianzhioffer二叉树中和为某一值的路径.cpp : Defines the entry point for the console application.
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
/*
				10
			5		12
		4	   7

		有多少叶子节点就有多少条路径
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
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

//我的做法：使用栈+深度优先来实现
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<bool> visited(20,false);
		vector<TreeNode* > node_stack;
		vector<vector<int> > result;
		TreeNode* node = root;
		while (node || !node_stack.empty())
		{
			while (node)
			{
				node_stack.push_back(node);
				visited[node_stack.size()] = false;
				node = node->left;
			}

			if (!node_stack.empty())
			{

				/*
				for (int j = 0; j < node_stack.size(); j++)
				{
					cout << node_stack[j]->val << "\t";
				}
				cout << endl;
				*/

				node = node_stack.back();

				//cout << "node = " << node->val << endl;

				if(visited[node_stack.size()] == true)
					node_stack.pop_back();
				else
				{
					visited[node_stack.size()] = true;
				
				if (node->right == NULL)//叶子节点
				{
					int sum = 0;

					for (int i = 0; i < node_stack.size(); i++)
						sum += node_stack[i]->val;
					if (sum == expectNumber)//找到了一条路径
					{
						vector<int> temp_v;
						for (int i = 0; i < node_stack.size(); i++)
						{
							temp_v.push_back(node_stack[i]->val);
						}
						result.push_back(temp_v);

						/*
						for (int i = 0; i < result.size(); i++)
						{
							for (int j = 0; j < result[i].size(); j++)
							{
								cout << result[i][j] << "\t";
							}
							cout << endl;
						}
						cout << endl;
						*/

					}
					node_stack.pop_back();
					//node = node_stack.back();
				}
				}
				node = node->right;
			}
		}
		return result;
	}
};

//推荐的做法：使用递归版本的DFS
class Solution1 {
public:
	vector<int> node_stack;
	vector<vector<int> > result;
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return result;
		node_stack.push_back(root->val);
		expectNumber -= node_stack.back();
		if (expectNumber == 0 && root->left == NULL && root->right == NULL)
			result.push_back(node_stack);
		FindPath(root->left, expectNumber);
		FindPath(root->right, expectNumber);
		node_stack.pop_back();
		return result;
	}
};

int main()
{
	//vector<int> create_in = { 1, 2, 3, 4, 0, 5, 6, 0, 0, 7, 0, 0, 8, 0, 0, 0, 9, 10, 0, 0, 11, 0, 0 };
	vector<int> create_in={10,5,4,0,0,7,0,0,12,0,0};
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
	vector<vector<int> > v = s.FindPath(root, 22);
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	Solution1 s1;
	vector<vector<int> > v1 = s1.FindPath(root, 22);
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v1[i].size(); j++)
		{
			cout << v1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}

