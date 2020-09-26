#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
typedef struct ListNode
{
	int data;
	struct ListNode* pNext;
}NODE,*pNODE;


void create_list(pNODE head_node, int length)
{
	pNODE pNew, pBefore;
	if (head_node == nullptr)
	{
		head_node = new ListNode;
	}
	pBefore = head_node;
	for (int i = 0; i < length; i++)
	{
		pNew = new ListNode;
		std::cin >> pNew->data;
		pNew->pNext = nullptr;
		pBefore->pNext = pNew;
		pBefore = pNew;
	}
}


void traverse_list(pNODE head_node)
{
	pNODE pNew ;
	if (head_node != nullptr)
	{
		pNew = head_node;
		while (pNew != nullptr)
		{
			std::cout << pNew->data << std::endl;
			pNew = pNew->pNext;
		}
	}
}

void reversePrintList(pNODE pHead)
{
	/*
		方法一：通过栈来逆向输出链表；
	*/
	stack<int>stk;
	pNODE pNew = pHead;
	while (pNew != nullptr)
	{
		stk.push(pNew->data);
		pNew = pNew->pNext;
	}
	while (!stk.empty())
	{
		cout << stk.top() << endl;
		stk.pop();
	}
}


void ReversePrintList(pNODE pHead)
{
	/*
		方法二：通过迭代来实现；
	*/
	if (pHead != nullptr)
	{
		if (pHead->pNext != nullptr)
		{
			ReversePrintList(pHead->pNext);
		}
		cout << pHead->data << "  " << endl;
	}

}


int main()
{
	void create_list(pNODE head_node, int length);
	void traverse_list(pNODE head_node);
	void ReversePrintList(pNODE pHead);
	pNODE Head_node = new ListNode;
	Head_node->data = 0;
	create_list(Head_node, 5);
	//traverse_list(Head_node);
	ReversePrintList(Head_node);
	return 0;
}