void sortage(int age[], int length)
{
	if (age == nullptr || length <= 0)
		return;
	int agedistri[100];
	for (int &i : agedistri)
		i = 0;
	for (int i = 0; i < length;i++)
	{
		++agedistri[age[i]];
	}
	int index = 0;
	for (int i = 0; i <= 99; i++)
		for (int j = 0; j < agedistri[i]; j++)
			age[index++] = i;
}