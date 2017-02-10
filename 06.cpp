#include<cstdio>
#include<exception>
using namespace std;
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode*m_pleft;
	BinaryTreeNode*m_pright;
	BinaryTreeNode(int a) :m_nValue(a), m_pleft(nullptr), m_pright(nullptr){}
};

BinaryTreeNode*core(int*pre_start, int*pre_end, int*in_start, int*in_end)
{
	BinaryTreeNode*head = new BinaryTreeNode(pre_start[0]);
	if (pre_start == pre_end)
	{
		if (in_start == in_end && in_start[0] == pre_start[0])
		{
			return head;
		}
		else
		{
			throw exception("Invalid input");
		}
	}
	int *root = in_start;
	while (root < in_end)
	{
		if (root[0] == pre_start[0])
			break;
		++root;
	}
	if (root == in_end&&root[0] != pre_start[0])
		throw exception("Invalid input");
	int leftlength = root - in_start;
	if (leftlength > 0)
	{
		head->m_pleft = core(pre_start + 1, pre_start + leftlength, in_start, in_start + leftlength - 1);
	}
	int rightlength = in_end - root;
	if (rightlength > 0)
	{
		head->m_pright = core(pre_start + leftlength + 1, pre_end, root + 1, in_end);
	}
	return head;
}

BinaryTreeNode* structBinaryTree(int*preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	return core(preorder, preorder + length - 1, inorder, inorder + length - 1);
}


void PrintTree(BinaryTreeNode*head)
{
	if (head != nullptr)
	{
		printf("Tree head is %d\n", head->m_nValue);
		if (head->m_pleft)
		{
			printf("left tree is %d\n", head->m_pleft->m_nValue);
		}
		else
		{
			printf("no left tree\n");
		}
		if (head->m_pright)
		{
			printf("right tree is %d\n", head->m_pright->m_nValue);
		}
		else
		{
			printf("no right tree\n");
		}
		PrintTree(head->m_pleft);
		PrintTree(head->m_pright);
	}
	else
	{
		return;
	}
}

void DestroyTree(BinaryTreeNode*head)
{
	if (head)
	{
		BinaryTreeNode*left = head->m_pleft;
		BinaryTreeNode*right = head->m_pright;
		delete head;
		head = nullptr;
		DestroyTree(left);
		DestroyTree(right);
	}
}
// ====================测试代码====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		BinaryTreeNode* root = structBinaryTree(preorder, inorder, length);
		PrintTree(root);

		DestroyTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
	Test("Test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
void Test7()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	Test("Test7: for unmatched input", preorder, inorder, length);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}