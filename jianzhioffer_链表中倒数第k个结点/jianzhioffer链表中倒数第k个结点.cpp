// jianzhioffer链表中倒数第k个结点.cpp : Defines the entry point for the console application.
//输入一个链表，输出该链表中倒数第k个结点。

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

//我的做法：两次遍历
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int size = 0;
		ListNode* temp = pListHead;
		while (temp)
		{
			size++;
			temp = temp->next;
		}
		int a = size-k;
		if (a < 0)
			return NULL;
		else if (a == 0)
			return pListHead;
		else
		{
			while (a>0)
			{
				a--;
				pListHead = pListHead->next;
			}
			pListHead->next = NULL;
			return pListHead;
		}
	}
};

//推荐的做法：
//代码思路如下：两个指针，先让第一个指针和第二个指针都指向头结点，然后再让第一个指正走(k - 1)步，到达第k个节点。然后两个指针同时往后移动，当第一个结点到达末尾的时候，第二个结点所在位置就是倒数第k个节点了。。
class Solution1 {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* first=pListHead;
		ListNode *second=pListHead;
		while (first)
		{
			if (k)
				k--;
			else
				second = second->next;
			first = first->next;
		}
		return k ? NULL : second;//此处要注意如果k没减完说明长度不够，返回空
	}
}; 

int main()
{
	ListNode *head =NULL;
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
	/*node->next = new ListNode(6);
	node = node->next;
	node->next = new ListNode(7);
	node = node->next;
	node->next = new ListNode(8);
	node = node->next;
	*/
	print_listNode(head);

	Solution s;
	ListNode *head_re = s.FindKthToTail(head, 1);
	print_listNode(head_re);

	Solution1 s1;
	print_listNode(s1.FindKthToTail(head, 10));

    return 0;
}

