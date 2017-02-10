#include<stack>
#include<cstdio>
using namespace std;
struct ListNode{
	int m_nKey;
	ListNode*m_pNext;
	ListNode(int a) :m_nKey(a), m_pNext(nullptr){}
};
void ConnectListNodes(ListNode*&first, ListNode*&second)
{
	first->m_pNext = second;
}
void DestroyList(ListNode*&head)
{
	ListNode*tmp;
	while (head != nullptr)
	{
		tmp = head;
		head = head->m_pNext;
		delete tmp;
	}
}

void PrintList(ListNode*head)
{
	while (head != nullptr)
	{
		printf("%d\t", head->m_nKey);
		head = head->m_pNext;
	}
}
void PrintListReverse(ListNode*head)
{
	if (head == nullptr)
		return;
	stack<int>a;
	while (head != nullptr)
	{
		a.push(head->m_nKey);
		head = head->m_pNext;
	}
	while (!a.empty())
	{
		printf("%d\t", a.top());
		a.pop();
	}
}

void PrintListReverse2(ListNode*head)
{
	if (head != nullptr)
	{
		if (head->m_pNext != nullptr)
			PrintListReverse2(head->m_pNext);
		printf("%d\t", head->m_nKey);
	}
}


// ====================测试代码====================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	printf("\n");
	PrintListReverse(pHead);
	printf("\n");
	PrintListReverse2(pHead);
}

// 1->2->3->4->5
void Test1()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = new ListNode(1);
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(3);
	ListNode* pNode4 = new ListNode(4);
	ListNode* pNode5 = new ListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = new ListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
void Test3()
{
	printf("\nTest3 begins.\n");

	Test(nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}
