// jianzhioffer合并两个排序的链表.cpp : Defines the entry point for the console application.
// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
//1       2       3       4       5       6       7       8		b
//2       4       6       8       10      11      12      13	a
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

//我的做法：从头向尾比较，遇到合适的就插入
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode *node;
		ListNode *head = pHead1;
		int a, b;
		int a1, b1;
		while (pHead1 && pHead2)
		{
			a = pHead1->val;
			b = pHead2->val;
			if ((pHead1->next) )
			{
				a1 = pHead1->next->val;

				if (a <= b && a1 <= b)
				{
					if (pHead1->next)
						pHead1 = pHead1->next;
				}
				else if (a <= b && a1 > b)
				{
					node = new ListNode(pHead2->val);
					node->next = pHead1->next;
					pHead1->next = node;

					pHead2 = pHead2->next;
				}
				else if(a>b)
				{
					node = new ListNode(pHead1->val);//将p2小值插到p1前
					pHead1->val = pHead2->val;
					node->next = pHead1->next;
					pHead1->next = node;

					pHead2 = pHead2->next;
					pHead1 = pHead1->next;
				}
			}
			else
			{
				while (pHead2)
				{
					pHead1->next = new ListNode(pHead2->val);
					pHead1=pHead1->next;
					pHead2 = pHead2->next;
				}
				break;
			}
			
		}
		return head;
	}
};

//推荐的做法：利用递归，从头到尾遍历，并从尾到头添加
/*
	例如：	head1= 1, 3, 5
			head2= 2, 4, 6

*/
class Solution1 {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		if (pHead1->val <= pHead2->val)
		{
			pHead1->next = Merge(pHead1->next, pHead2);
			return pHead1;
		}
		else
		{
			pHead2->next = Merge(pHead1, pHead2->next);
			return pHead2;
		}
	}
};

int main()
{
	ListNode *head;
	ListNode *node = new ListNode(1);
	head = node;
	node->next = new ListNode(3);
	node = node->next;
	node->next = new ListNode(5);
	node = node->next;
	/*node->next = new ListNode(4);
	node = node->next;
	node->next = new ListNode(5);
	node = node->next;
	node->next = new ListNode(6);
	node = node->next;
	node->next = new ListNode(7);
	node = node->next;
	node->next = new ListNode(8);
	node = node->next;
	*/
	ListNode *head1;
	node = new ListNode(2);
	head1 = node;
	node->next = new ListNode(4);
	node = node->next;
	node->next = new ListNode(6);
	node = node->next;
	/*node->next = new ListNode(8);
	node = node->next;
	node->next = new ListNode(10);
	node = node->next;
	node->next = new ListNode(11);
	node = node->next;
	node->next = new ListNode(12);
	node = node->next;
	node->next = new ListNode(13);
	node = node->next;
	*/

	print_listNode(head);
	print_listNode(head1);

	Solution s;
	//print_listNode(s.Merge(head, head1));
	Solution1 s1;
	print_listNode(s1.Merge(head, head1));

	return 0;
}

