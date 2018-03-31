// jianzhioffer从尾到头打印链表.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode
{
	ListNode *next;
	int val;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_listNode(ListNode *head)
{
	while (head)
	{
		cout << head->val << "\t";
		head = head->next;
	}
	cout << endl;
}

//我的方法：将原链表所有指针反过来指。注意空链表的特殊情况处理
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> a;

		if (head == NULL)
		{
			return a;
		}

		ListNode *first = head;
		ListNode *second = head->next;

		ListNode *temp;
		first->next = NULL;

		if (second == NULL)
		{
			a.push_back(head->val);
			return a;
		}
		while (second->next)
		{
			temp = second->next;
			second->next = first;
			first = second;
			second = temp;
		}

		temp = second->next;
		second->next = first;
		first = second;
		second = NULL;

		while (first)
		{
			a.push_back(first->val);
			first = first->next;
		}
		return a;
	}
};

//推荐做法：递归的找到最后一个节点，并从后往前得到结果
class Solution1
{
public:
	vector<int> a;
	vector<int> printListFromTailToHead(ListNode* head) {
		if (head)
		{
			printListFromTailToHead(head->next);
			a.push_back(head->val);
		}
		return a;
	}
};

int main()
{
	ListNode *head;
	ListNode *node = new ListNode(1);
	head = node;
	node->next = new ListNode(2);
	node = node->next;
	node->next = new ListNode(3);
	node = node->next;
	node->next = new ListNode(4);
	node = node->next;
	node->next = new ListNode(5);
	node = node->next;
	node->next = new ListNode(6);
	node = node->next;
	node->next = new ListNode(7);
	node = node->next;
	node->next = new ListNode(8);
	node = node->next;

	print_listNode(head);

	Solution1 s1;
	vector<int> out1 = s1.printListFromTailToHead(head);
	for (int i = 0; i < out1.size(); i++)
	{
		cout << out1[i] << "\t";
	}
	cout << endl;

	Solution s;
	vector<int> out = s.printListFromTailToHead(head);
	for (int i = 0; i < out.size(); i++)
	{
	cout << out[i] << "\t";
	}
	cout << endl;

    return 0;
}

