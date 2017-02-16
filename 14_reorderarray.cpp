#include<string>
#include<stdio.h>
void ReorderOddEven_1(int*data, int length)
{
	if (data == nullptr || length <= 0)
		return;
	int head = 0;
	int end = length - 1;
	while (end > head)
	{
		while((data[head] & 0x1) == 1)
			++head;
		while((data[end] & 0x1) == 0)
			--end;
		if (end > head)
			std::swap(data[head], data[end]);

	}
}
int iseven(int number)
{
	if (number & 0x1 == 1)
		return 1;
	else
	{
		return 0;
	}
}

void ReorderOddEven_2(int*data, int length, int(*func)(int))
{
	if (data == nullptr || length <= 0)
		return;
	int head = 0;
	int end = length - 1;
	while (end > head)
	{
		while (func(data[head]))
			++head;
		while (!func(data[end]))
			--end;
		if (end > head)
			std::swap(data[head], data[end]);

	}
}

// ====================²âÊÔ´úÂë====================
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = numbers[i];
	}

	printf("Test for solution 1:\n");
	PrintArray(numbers, length);
	ReorderOddEven_1(numbers, length);
	PrintArray(numbers, length);

	printf("Test for solution 2:\n");
	PrintArray(copy, length);
	ReorderOddEven_2(copy, length,iseven);
	PrintArray(copy, length);

	delete[] copy;
}

void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
	int numbers[] = { 1 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
	int numbers[] = { 2 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
	Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}