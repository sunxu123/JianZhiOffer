// jianzhioffer反转链表.cpp : Defines the entry point for the console application.
//输入一个链表，反转链表后，输出链表的所有元素。

#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
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


class Solution {
public:
	ListNode* ReverseList(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}

		ListNode *first = head;
		ListNode *second = head->next;

		ListNode *temp;
		first->next = NULL;

		if (second == NULL)
		{
			return head;
		}
		while (second->next)
		{
			temp = second->next;
			second->next = first;
			first = second;
			second = temp;
		}

		second->next = first;

		return second;
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

	Solution s;
	ListNode *head_re=s.ReverseList(head);
	print_listNode(head_re);

	return 0;
}

