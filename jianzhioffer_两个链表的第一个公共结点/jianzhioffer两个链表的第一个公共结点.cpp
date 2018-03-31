// jianzhioffer两个链表的第一个公共结点.cpp : Defines the entry point for the console application.
//输入两个链表，找出它们的第一个公共结点。

#include "stdafx.h"
#include<iostream>
#include<vector>

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

//我的做法：
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {

		while (pHead1)
		{
			ListNode * temp = pHead2;
			while (temp)
			{
				if (pHead1->val == temp->val)
					return pHead1;
				temp = temp->next;
			}
			pHead1 = pHead1->next;
		}

		return NULL;

	}
};

//推荐的做法：
/*
注意这两种方法的区别：
	方法2的复杂度远低于方法1
	方法2最多只需要执行pHead1.size()+pHead2.size()就可以得出结果
	方法1最多需要执行pHead1.size()与pHead2.size()的最小公约数次
		原因：方法2第一遍结束后可以得到两链表的长度差
			第二次长的停留长度差后找（因为公共结点后面的所有元素相同）

*/
class Solution1
{
public:
	ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
	{
		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;
		while (p1 != p2)
		{
			//方法1
			//p1 = (p1 == NULL ? pHead1 : p1->next);
			//p2 = (p2 == NULL ? pHead2 : p2->next);
			//方法2
			p1 = (p1 == NULL ? pHead2 : p1->next);
			p2 = (p2 == NULL ? pHead1 : p2->next);

		}
		return p1;
	}
};
int main()
{
	ListNode *head = NULL;
	ListNode *node = new ListNode(1);
	head = node;
	node->next = new ListNode(2);
	node = node->next;
	node->next = new ListNode(3);
	node = node->next;
	node->next = new ListNode(6);
	node = node->next;
	node->next = new ListNode(7);
	node = node->next;

	ListNode *head1 = NULL;
	node = new ListNode(4);
	head1 = node;
	node->next = new ListNode(5);
	node = node->next;
	node->next = new ListNode(6);
	node = node->next;
	node->next = new ListNode(7);
	node = node->next;

	print_listNode(head);
	print_listNode(head1);

	Solution s;
	print_listNode(s.FindFirstCommonNode(head, head1));
	Solution1 s1;
	print_listNode(s1.FindFirstCommonNode(head, head1));

    return 0;
}

