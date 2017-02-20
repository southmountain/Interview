#include<iostream>
#include<string>
using namespace std;

void compute_next(const string&pattern)
{
	int pattern_length = pattern.size();
	int *next = new int[pattern_length];//next数组
	int index;
	next[0] = -1;//匹配0个时设为-1，1个设为0...
	for (int i = 1; i < pattern_length; i++)
	{
		index = next[i - 1];//next数组前一位
		while (index >= 0 && pattern[i] != pattern[index + 1])
		{
			index = next[index];
		}
		if (pattern[i] == pattern[index + 1])
		{
			next[i] = index + 1;
		}
		else
		{
			next[i] = -1;
		}
	}
	for (int i = 0; i < pattern_length; i++)
	{
		cout << next[i] << endl;
	}

	delete[]next;
}

int kmp_find(const string&target, const string &pattern)
{
	int target_length = target.size();
	int pattern_length = pattern.size();
	int*next = new int[pattern_length];
	next[0] = -1;
	int index = 0;
	for (int i = 1; i < pattern_length; i++)
	{
		index = next[i - 1];
		while (index >= 0 && pattern[i] != pattern[index + 1])
		{
			index = next[index];
		}
		if (pattern[i] == pattern[index + 1])
		{
			next[i] = index + 1;
		}
		else
		{
			next[i] = -1;
		}
	}

	//match algorithm start
	int pattern_index = 0;
	int target_index = 0;
	while (pattern_index < pattern_length&&target_index < target_length)
	{
		if (target[target_index] == pattern[pattern_index])
		{
			++target_index;
			++pattern_index;
		}
		else if (pattern_index == 0)
		{
			++target_index;
		}
		else
		{
			pattern_index = next[pattern_index - 1] + 1;
		}
	}
	if (pattern_index == pattern_length)
		return target_index - pattern_length;
	else
	{
		return -1;
	}
	delete[]next;
}

int main()
{
	//compute_next("abaabcaba");//[-1,-1,0,0,1,-1,0,1,2];
	string source = "annbcdanacadsannannabnna";
	string pattern = "bcd";
	cout << kmp_find(source, pattern) << endl;

	return 0;
}