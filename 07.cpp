#include<stack>
#include<cstdio>
using namespace std;

template<typename T>class CQueue
{
public:
	CQueue(){

	}
	~CQueue(){
		while (!stack1.empty())
		{
			stack1.pop();
		}
		while (!stack2.empty())
		{
			stack2.pop();
		}
	}
	void appendTail(const T&node);
	T deleteHead();
private:
	stack<T>stack1;
	stack<T>stack2;
};


template<typename T>void CQueue<T>::appendTail(const T&node)
{
	stack1.push(node);
}

template<typename T>T CQueue<T>::deleteHead()
{
	if (!stack2.empty())
	{
		T tmp = stack2.top();
		stack2.pop();
		return tmp;
	}
	else
	{
		if (stack1.empty())
			throw exception("empty");
		while (!stack1.empty())
		{
			T tmp = stack1.top();
			stack1.pop();
			stack2.push(tmp);
		}
		T tmp = stack2.top();
		stack2.pop();
		return tmp;
	}
}


// ====================≤‚ ‘¥˙¬Î====================
void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');

	return 0;
}