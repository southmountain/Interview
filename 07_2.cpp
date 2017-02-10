#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;

template<typename T>class Cstack{
public:
	Cstack(){}
	~Cstack(){
		while (!q1.empty())
		{
			q1.pop();
		}
		while (!q2.empty())
		{
			q2.pop();
		}
	}
	void Push(T data)
	{
		if (q2.empty())
		{
			q1.push(data);
		}
		else
		{
			q2.push(data);
		}
	}
	T Pop()
	{
		if (q1.empty() && q2.empty())
			throw exception("empty");
		if (q2.empty())
		{
			while (q1.size() > 1)
			{
				T tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
			T tmp = q1.front();
			q1.pop();
			return tmp;
		}
		if (q1.empty())
		{
			while (q2.size() > 1)
			{
				T tmp = q2.front();
				q2.pop();
				q1.push(tmp);
			}
			T tmp = q2.front();
			q2.pop();
			return tmp;
		}

	}
private:
	queue<T>q1;
	queue<T>q2;
};


int main()
{
	Cstack<int>a;
	a.Push(1);
	a.Push(2);
	a.Push(3);
	cout << a.Pop() << endl;
	cout << a.Pop() << endl;
	a.Push(4);
	cout << a.Pop() << endl;
	cout << a.Pop() << endl;
	return 0;
}