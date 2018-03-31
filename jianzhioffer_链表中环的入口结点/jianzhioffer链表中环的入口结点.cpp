// jianzhioffer链表中环的入口结点.cpp : Defines the entry point for the console application.
//一个链表中包含环，请找出该链表的环的入口结点。

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//我的做法：访问过某节点后设置标志位
class Solution1 {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		map<ListNode *, bool> flag;
		ListNode *node = pHead;
		while (node != NULL)
		{
			if (flag[node])
				return node;
			else
			{
				flag[node] = true;
				node = node->next;
			}
		}
		return NULL;
	}
};

/*
推荐做法：先使用两个快慢指针找相遇点，再从相遇点找入口点
链接：https://www.nowcoder.com/questionTerminal/253d2c59ec3e4bc68da16833f79a38e4

假设x为环前面的路程，a为环入口到相遇点的路程， c为环的长度
当快慢指针相遇的时候：
(n和m为其绕环圈数)
此时慢指针走的路程为Sslow = x + m * c + a
快指针走的路程为Sfast = x + n * c + a
2 Sslow = Sfast
2 * ( x + m*c + a ) = (x + n *c + a)
从而可以推导出：
x = (n - 2 * m )*c - a
= (n - 2 *m -1 )*c + c - a
即环前面的路程 = 数个环的长度（为可能为0） + c - a
什么是c - a？这是相遇点后，环后面部分的路程。
所以，我们可以让一个指针从起点开始走，让一个指针从相遇点开始继续往后走，
2个指针速度一样，那么，当从原点的指针走到环入口点的时候（此时刚好走了x）
从相遇点开始走的那个指针也一定刚好到达环入口点。
所以2者会相遇，且恰好相遇在环的入口点。

*/


class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode * slow = pHead;
		ListNode * fast = pHead;
		while (slow->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)//有相遇点，有环
			{
				slow = pHead;
				while (slow != fast)
				{
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return NULL;
	}
};

/*
其他做法：
如果确定有环的话，还可以采用断链法。需要修改原链表
*/
class Solution2 {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
			return NULL;
		ListNode * current = pHead;
		ListNode * next = current->next;
		while (next)
		{
			current->next = NULL;
			current = next;
			next = next->next;
		}
		return current;
	}
};

