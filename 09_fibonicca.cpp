#include<cstdio>
int fib(int n)
{
	int a[] = { 0, 1 };
	if (n < 2)
		return a[n];
	int minus2 = a[0];
	int minus1 = a[1];
	int minus0;
	for (int i = 2; i <= n; i++)
	{
		minus0 = minus1 + minus2;
		minus2 = minus1;
		minus1 = minus0;
	}
	return minus0;
}

void Test(int n, int expected)
{ 
	if (fib(n) == expected)
		printf("Test for %d in solution1 passed.\n", n);
	else
		printf("Test for %d in solution1 failed.\n", n);

}

int main(int argc, char* argv[])
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	Test(40, 102334155);

	return 0;
}