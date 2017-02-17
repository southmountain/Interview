
#include<cstdio>

void printmatrix(int**numbers, int cols, int rows, int start)
{
	int endx = cols - start - 1;
	int endy = rows - start - 1;
	for (int i = start; i <= endx; i++)
		printf("%d\t", numbers[start][i]);
	if (start < endy)
	{
		for (int i = start + 1; i <= endy; i++)
			printf("%d\t", numbers[i][endx]);
	}
	if (start < endx&&start<endy)
	{
		for (int i = endx-1; i >= start; i--)
			printf("%d\t", numbers[endy][i]);
	}
	if (start + 1 < endy&&start<endx)
	{
		for (int i = endy - 1; i > start; i--)
			printf("%d\t", numbers[i][start]);
	}

}
void PrintMatrixClockwisely(int**numbers, const int Cols, const int Rows)
{
	if (numbers == nullptr || Cols <= 0 || Rows <= 0)
		return;
	int start = 0;
	while (Cols > start * 2 && Rows > start * 2)
	{
		printmatrix(numbers, Cols, Rows, start);
		++start;

	}

}

// ====================²âÊÔ´úÂë====================
void Test(int columns, int rows)
{
	printf("Test Begin: %d columns, %d rows.\n", columns, rows);

	if (columns < 1 || rows < 1)
		return;

	int** numbers = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
		}
	}

	PrintMatrixClockwisely(numbers, columns, rows);
	printf("\n");

	for (int i = 0; i < rows; ++i)
		delete[](int*)numbers[i];

	delete[] numbers;
}

int main(int argc, char* argv[])
{
	/*
	1
	*/
	Test(1, 1);

	/*
	1    2
	3    4
	*/
	Test(2, 2);

	/*
	1    2    3    4
	5    6    7    8
	9    10   11   12
	13   14   15   16
	*/
	Test(4, 4);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14   15
	16   17   18   19   20
	21   22   23   24   25
	*/
	Test(5, 5);

	/*
	1
	2
	3
	4
	5
	*/
	Test(1, 5);

	/*
	1    2
	3    4
	5    6
	7    8
	9    10
	*/
	Test(2, 5);

	/*
	1    2    3
	4    5    6
	7    8    9
	10   11   12
	13   14   15
	*/
	Test(3, 5);

	/*
	1    2    3    4
	5    6    7    8
	9    10   11   12
	13   14   15   16
	17   18   19   20
	*/
	Test(4, 5);

	/*
	1    2    3    4    5
	*/
	Test(5, 1);

	/*
	1    2    3    4    5
	6    7    8    9    10
	*/
	Test(5, 2);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14    15
	*/
	Test(5, 3);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14   15
	16   17   18   19   20
	*/
	Test(5, 4);

	return 0;
}