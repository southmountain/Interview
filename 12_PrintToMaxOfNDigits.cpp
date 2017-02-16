#include<stdio.h>
#include<memory.h>
#include<string>


void print(char*a)
{
	if (a == nullptr)
		return;
	int i = 0;
	while (a[i] == '0')
	{
		++i;
	}
	while (a[i] != '\0')
	{
		printf("%c", a[i++]);
	}
	printf("\t");
}

bool Increment(char*a)
{
	bool isoverflow = false;
	int flag = 0;
	int nlength = strlen(a);
	for (int i = nlength - 1; i >= 0; i--)
	{
		int number = a[i] - '0' + flag;
		if (i == nlength - 1)
			++number;
		if (number >= 10)
		{
			if (i == 0)
			{
				isoverflow = true;
				return isoverflow;
			}
			number -= 10;
			flag = 1;
			a[i] = number+'0';

		}
		else
		{
			a[i] = number+'0';
			break;
		}
	}
	return isoverflow;

}
void printNdigit(int n)
{
	if (n <= 0)
		return;
	char* a = new char[n + 1];
	memset(a, '0', n);
	a[n] = '\0';
	while (!Increment(a))
	{
		print(a);
	}

}



void printNd(char*a, int length, int index)
{
	if (index == length - 1)
	{
		print(a);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		a[index+1] = '0' + i;
		printNd(a, length, index+1);
	}
}

void printNdigit2(int n)
{
	if (n <= 0)
		return;
	char *a = new char[n + 1];
	a[n] = '\0';
	for (int i = 0; i <= 9; i++)
	{
		a[0] = '0' + i;
		printNd(a, n, 0);
	}

}
int main()
{
	printNdigit2(-1);
	return 0;
}