#include<iostream>
#include<cstdio>
#include<exception>
using namespace std;
int searchMin(int*number, int node1, int node2)
{
	int m = number[node1];
	while (node1 != node2)
	{
		m = number[++node1] < m ? number[node1] : m;
	}
	return m;
}
int Min(int *numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		throw new exception("Invalid input");
	int node1 = 0;
	int node2 = length - 1;
	int nodemid = node1;
	while (numbers[node1] >= numbers[node2])
	{
		if (node2 - node1 == 1)
		{
			nodemid = node2;
			break;
		}
		nodemid = (node2 + node1) / 2;
		if (numbers[node1] == numbers[nodemid]&&numbers[node2] == numbers[nodemid])
			return searchMin(numbers,node1, node2);
		if (numbers[nodemid] > numbers[node1])
		{
			node1 = nodemid;
		}
		else if (numbers[nodemid] < numbers[node2])
		{
			node2 = nodemid;
		}
	}
	return numbers[nodemid];
}



// ====================���Դ���====================
void Test(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = Min(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...)
	{
		if (numbers == nullptr)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

int main(int argc, char* argv[])
{
	// �������룬��������������һ����ת
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// ���ظ����֣������ظ������ָպõ���С������
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// ������ֻ��һ������
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// ����nullptr
	Test(nullptr, 0, 0);

	return 0;
}