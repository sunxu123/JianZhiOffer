// jianzhioffer树的子结构.cpp : Defines the entry point for the console application.
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

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

//我的做法：大树从根->左->右依次递归判断能否找到小树的根，找到了，就判断大树从这点开始，递归判断是不是左树与小树左树相同，右树与小树右树相同
class Solution {
public:
	bool flag = false;
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{

		//if (pRoot1 == NULL || pRoot2 == NULL)
			//return false;
		if (pRoot1 == NULL)
			return false;
		if (pRoot2 == NULL)
			return true;
		if (pRoot1)
		{
			if (pRoot1->val == pRoot2->val && pRoot2->left == NULL && pRoot2->right == NULL)
				return true;
			}
			if (pRoot1->val == pRoot2->val)
			{
				flag = true;
				if (pRoot2->left == NULL || HasSubtree(pRoot1->left, pRoot2->left))
					if (pRoot2->right == NULL || HasSubtree(pRoot1->right, pRoot2->right))
						return true;
			}
			
				if (flag)
				{
					flag = false;
					return false;
				}
				if (HasSubtree(pRoot1->left, pRoot2))
					return true;
				else
					return HasSubtree(pRoot1->right, pRoot2);
		}
};

//推荐的做法：将上面的两个递归分开写，减少复杂度。
class Solution1 {
public:
	bool IsSubTree(TreeNode* pRoot1, TreeNode* pRoot2)//递归判断是不是左树与小树左树相同，右树与小树右树相同
	{
		if (pRoot2 == NULL)	return true;//细节：proot2判断要放在proot1前
		if (pRoot1 == NULL)	return false;
		if (pRoot1->val == pRoot2->val)
			return IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
		else
			return false;
	}

	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)//递归判断能否找到小树的根
	{
		if (pRoot1 == NULL || pRoot2 == NULL) return false;
		return IsSubTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
		
	}
};

int main()
{
	//vector<int> create_in = { 8,6,5,0,0,7,0,0,10,9,0,0,11,0,0 };//{8,8,7,9,2,#,#,#,#,4,7},{8,9,2}
	//vector<int> create_in1 = { 10,9,0,0,11,0,0 };	
	//vector<int> create_in = { 8,8,7,9,2,0,0,0,0,4,7,0,0,0,0 };//{8,8,7,9,2,#,#,#,#,4,7},{8,9,2}
	//vector<int> create_in1 = { 8,9,2,0,0,0,0 };
	//vector<int> create_in = { 8,8,9,0,0,2,4,0,0,7,0,0,7,0,0 };//{8,8,7,9,2,#,#,#,#,4,7},{8,9,2}
	//vector<int> create_in1 = { 8,9,0,0,2,0,0 };
	//vector<int> create_in2 = { 10,9,0,0,1,0,0 };
	/*{8,8,#,9,#,2,#,5},{8,9,#,2}
					 8				
				8		 7
			9		2
				  4		7

				  8
				9   2
	*/

	//vector<int> create_in = { 8,8,9,2,5,0,0,0,0,0,0 };//{8,8,#,9,#,2,#,5},{8,9,#,2}
	//vector<int> create_in1 = { 8,9,2,0,0,0,0 };
	//vector<int> create_in2 = { 8,9,2,0,0,0,0 };
	/*
					8
				8
			9
		2
	5

					8
				9
			2
	
	*/ 
	vector<int> create_in = { 8,0,8,0,9,0,2,0,5,0,0 };//{8, #, 8, #, 9, #, 2, #, 5}, { 8,#,9,#,2 }
	vector<int> create_in1 = { 8,0,9,0,2,0,0 };
	vector<int> create_in2 = { 8,0,9,0,2,0,0 };
	/*
					8
						8
							9
								2
									5
	
	*/
	TreeNode *root = NULL;
	create_index = 0;
	if (create_in[create_index] > 0)
	{
		root = new TreeNode(create_in[create_index]);
		root->left = create_binarytree(create_in);
		root->right = create_binarytree(create_in);
	}

	//preTraverse_binarytree(root);
	cout << endl;

	TreeNode *root1 = NULL;
	create_index = 0;
	if (create_in[create_index] > 0)
	{
		root1 = new TreeNode(create_in1[create_index]);
		root1->left = create_binarytree(create_in1);
		root1->right = create_binarytree(create_in1);
	}

	//preTraverse_binarytree(root1);
	cout << endl;

	TreeNode *root2 = NULL;
	create_index = 0;
	if (create_in[create_index] > 0)
	{
		root2 = new TreeNode(create_in2[create_index]);
		root2->left = create_binarytree(create_in2);
		root2->right = create_binarytree(create_in2);
	}

	//preTraverse_binarytree(root2);
	cout << endl;

	Solution s;
	cout << s.HasSubtree(root, root1) << endl;
	//cout << s.HasSubtree(root, root2) << endl;

	Solution1 s1;
	cout << s1.HasSubtree(root, root1) << endl;
    return 0;
}

