#include<string>
#include<iostream>
using namespace std;
class CMyString{
public:
	CMyString(char*p = NULL) {
		if (p == NULL)
		{
			m_pData = new char[1];
			m_pData[0] = '\0';
		}
		else
		{
			m_pData = new char[strlen(p) + 1];
			strcpy(m_pData, p);
		}
	}
	CMyString(const CMyString&rhs)
	{
		m_pData = new char[strlen(rhs.m_pData) + 1];
		strcpy(m_pData, rhs.m_pData);
	}
	CMyString&operator=(const CMyString&rhs)
	{
		if (this!=&rhs)
		{
			CMyString tmp(rhs);
			char*t = m_pData;
			m_pData = tmp.m_pData;
			tmp.m_pData = t;
		}
		return *this;
	}
	~CMyString(){
		delete[]m_pData;
	}
	void print()
	{
		cout << m_pData << endl;
	}
private:
	char*m_pData;
};

void Test1()
{
	printf("Test1 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.print();
	printf(".\n");
}
int main()
{
	Test1();
	Test2();
	Test3();

	return 0;

}