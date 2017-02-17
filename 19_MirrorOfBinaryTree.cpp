#include "BinaryTree.h"
#include<cstdio>
#include<stack>
using namespace std;
void MirrorRecursively(BinaryTreeNode*head)
{
	if (head == nullptr)
		return;
	if (head->m_pLeft == nullptr&&head->m_pRight == nullptr)
		return ;
	BinaryTreeNode*tmp = head->m_pLeft;
	head->m_pLeft = head->m_pRight;
	head->m_pRight = tmp;
	if (head->m_pLeft)
		MirrorRecursively(head->m_pLeft);
	if (head->m_pRight)
		MirrorRecursively(head->m_pRight);
}

void MirrorIteratively(BinaryTreeNode*head)
{
	if (head == nullptr)
		return;
	stack<BinaryTreeNode*>a;
	a.push(head);
	while (a.size() > 0)
	{
		BinaryTreeNode*phead = a.top();
		a.pop();
		BinaryTreeNode*tmp = phead->m_pLeft;
		phead->m_pLeft = phead->m_pRight;
		phead->m_pRight = tmp;
		if (phead->m_pLeft)
			a.push(phead->m_pLeft);
		if (phead->m_pRight)
			a.push(phead->m_pRight);
	}
}
// ====================���Դ���====================
// ������ȫ������������Ҷ�ӽڵ㣬�����ڵ㶼�������ӽڵ�
//            8
//        6      10
//       5 7    9  11
void Test1()
{
	printf("=====Test1 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	PrintTree(pNode8);

	printf("=====Test1: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test1: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
//            8
//          7   
//        6 
//      5
//    4
void Test2()
{
	printf("=====Test2 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNodes(pNode8, pNode7, nullptr);
	ConnectTreeNodes(pNode7, pNode6, nullptr);
	ConnectTreeNodes(pNode6, pNode5, nullptr);
	ConnectTreeNodes(pNode5, pNode4, nullptr);

	PrintTree(pNode8);

	printf("=====Test2: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test2: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
//            8
//             7   
//              6 
//               5
//                4
void Test3()
{
	printf("=====Test3 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNodes(pNode8, nullptr, pNode7);
	ConnectTreeNodes(pNode7, nullptr, pNode6);
	ConnectTreeNodes(pNode6, nullptr, pNode5);
	ConnectTreeNodes(pNode5, nullptr, pNode4);

	PrintTree(pNode8);

	printf("=====Test3: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test3: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// ���Կն������������Ϊ��ָ��
void Test4()
{
	printf("=====Test4 starts:=====\n");
	BinaryTreeNode* pNode = nullptr;

	PrintTree(pNode);

	printf("=====Test4: MirrorRecursively=====\n");
	MirrorRecursively(pNode);
	PrintTree(pNode);

	printf("=====Test4: MirrorIteratively=====\n");
	MirrorIteratively(pNode);
	PrintTree(pNode);
}

// ����ֻ��һ�����Ķ�����
void Test5()
{
	printf("=====Test5 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

	PrintTree(pNode8);

	printf("=====Test4: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test4: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}