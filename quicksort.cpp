#include<iostream>
#include<exception>
#include<random>
#include<time.h>
#include"stdlib.h"
using namespace std;

int RandomInt(int start, int end)
{
	default_random_engine generator(time(0));
	uniform_int_distribution<int> random(start, end);
	return random(generator);
}

int partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new exception("Invalid Input");
	int index = RandomInt(start, end);
	swap(data[end], data[index]);
	int cursor = start - 1;
	for (int i = start; i < end; i++)
	{
		if (data[i] <= data[end])
		{
			++cursor;
			swap(data[cursor], data[i]);
		}
	}
	swap(data[++cursor], data[end]);
	return cursor;
}
void quicksort(int data[], int length, int start, int end)
{
	if (data == nullptr)
		return;
	int index = partition(data, length, start, end);
	if (index > start)
		quicksort(data, length, start, index - 1);
	if (end > index)
		quicksort(data, length, index + 1, end);
}

int main()
{
	int a[] = { 9, 8, 5, 6, 7, 1 };
	quicksort(a, 10, 0, 5);
	for (auto &c : a)
		cout << c << endl;
	return 0;
}
