// jianzhioffer删除链表中重复的结点.cpp : Defines the entry point for the console application.
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

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

//我的做法：用一个flag来标记头结点，用单独一个指针来记录下一个有可能位置
class Solution1 {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		if (pHead->next == NULL)
			return pHead;
		bool is_head = true;
		ListNode * head = NULL;//头结点
		ListNode * not_dup = NULL;//最后一个确定非重复的节点
		ListNode * last_not_dup = pHead;//最后一个可能非重复的节点
		ListNode * traverse = pHead->next;

		while (traverse)
		{
			while ((traverse )&& (traverse->val == last_not_dup->val))
					traverse = traverse->next;
			
			if (traverse == last_not_dup->next)
			{
				if (is_head)
				{
					is_head = false;
					not_dup = last_not_dup;
					not_dup->next = NULL;
					head = not_dup;
				}
				else
				{
					not_dup->next = last_not_dup;
					not_dup = not_dup->next;
					not_dup->next = NULL;
				}
			}
			last_not_dup = traverse;
			if (traverse == NULL)
				break;
			traverse = traverse->next;
		}
		if (not_dup)
		{
			not_dup->next = last_not_dup;
			if (last_not_dup != NULL)
			{
				not_dup = not_dup->next;
				not_dup->next = NULL;
			}
		}
		else if(last_not_dup)
		{
			not_dup = last_not_dup;
			not_dup->next = NULL;
			head = not_dup;
		}
		return head;
	}
};

//推荐的做法
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode * head = new ListNode(0);//关键点1：创建一个临时头结点，避免第一个元素就是重复的问题
		head->next = pHead;
		ListNode * node = pHead;//用于遍历的节点
		ListNode * last = head;//最后一个确定不同的节点、last->next表示最后一个可能的节点
		while (node != NULL&&node->next != NULL)
		{
			if (node->val == node->next->val)
			{
				int temp = node->val;
				node = node->next;
				while (node != NULL && (node->val == temp))
					node = node->next;
				last->next = node;//关键点2：这里还没遍历下一节点，所以这个node与前一节点不同，所以这是一个可能的节点。如果node->val == node->next->val，则last不变，
			}
			else
			{
				last = node;//只有在当前节点确定与下一结点不同时才给last
				node = node->next;
			}
		}
		return head->next;
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
	node->next = new ListNode(4);
	node = node->next;
	node->next = new ListNode(5);
	node = node->next;
	node->next = new ListNode(6);
	node = node->next;
	node->next = new ListNode(7);
	node = node->next;
	
	/*
	ListNode *node = new ListNode(1);
	head = node;
	node->next = new ListNode(1);
	node = node->next;
	node->next = new ListNode(1);
	node = node->next;
	*/
	print_listNode(head);

	Solution s;
	ListNode *headq = s.deleteDuplication(head);
	print_listNode(headq);

	return 0;
}

