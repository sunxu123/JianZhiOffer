// jianzhioffer二叉树的下一个结点.cpp : Defines the entry point for the console application.
//
/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

#include "stdafx.h"


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
	}
};
/*
中序遍历：左根右
*/
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode->left)
			return pNode->left;
		if(pNode)
	}
};

int main()
{
	return 0;
}

