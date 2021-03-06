// jianzhioffer复杂链表的复制.cpp : Defines the entry point for the console application.
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
//我的做法：先通过一个数组来存储所有的节点，在得到节点的next关系，最后得到节点的random关系
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		vector<RandomListNode*> nodes;

		RandomListNode* node = pHead;
		while (node)
		{
			nodes.push_back(new RandomListNode(node->label));
			node = node->next;
		}
		for (int i = 0; i<nodes.size() - 1; i++)
			nodes[i]->next = nodes[i + 1];

		node = pHead;
		for (int i = 0; i<nodes.size(); i++)
		{
			if (node->random)
			{
				for (int j = 0; j<nodes.size(); j++)
				{
					if (nodes[j]->label == node->random->label)
					{
						nodes[i]->random = nodes[j];
						break;
					}
				}

			}
			node = node->next;
		}

		return nodes[0];
	}
};

int main()
{

	return 0;
}

