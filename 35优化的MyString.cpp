#include <iostream>
using namespace std;
#if 0
class MyString
{
public:
	MyString(const char* p = nullptr)
	{
		cout << "MyString(char*)" << endl;
		if (p != nullptr)
		{
			_ptr = new char[strlen(p) + 1]{ 0 };
			strcpy(_ptr, p);
		}
		else
		{
			_ptr = new char[1];
			*_ptr = '\0';
		}
	}
	~MyString()
	{
		cout << "~MyString()" << endl;
		delete[] _ptr;
		_ptr = nullptr;
	}
	MyString(const MyString& str)
	{
		cout << "MyString(MyString)" << endl;
		_ptr = new char[strlen(str._ptr) + 1]{ 0 };
		strcpy(_ptr, str._ptr);
	}
	MyString(MyString&& str)
	{
		cout << "MyString(MyString&&)" << endl;
		_ptr = str._ptr;
		str._ptr = nullptr;
	}
	MyString& operator= (const MyString& str)
	{
		cout << "MyString(operator=)" << endl;
		if (this == &str) return *this;
		delete[] _ptr;
		_ptr = new char[strlen(str._ptr) + 1]{ 0 };
		strcpy(_ptr, str._ptr);
		return *this;
	}
	MyString& operator= (MyString&& str)
	{
		cout << "MyString(operator=&&)" << endl;
		if (this == &str) return *this;
		delete[] _ptr;
		_ptr = str._ptr;
		str._ptr = nullptr;
		return *this;
	}
	char* c_str()const { return _ptr; }
private:
	char* _ptr;
};

//	���Ż�����
//	��������������ܱ��Ż��ˣ�����޸�MyString�࣬����Ч�ʸ�Щ?
MyString GetObject(MyString& t)
{
	char* ptr = t.c_str();
	MyString tmpStr(ptr);
	return tmpStr;
}
int main()
{
	MyString str1 = "123456789";
	MyString str2;
	str2 = GetObject(str1);
	cout << str2.c_str() << endl;
	/*
	* �Ż�class֮��û�и���������ڴ桢�ͷ��ڴ�Ĳ���
	MyString(char*)
	MyString(char*)
	MyString(char*)
	MyString(MyString&&)	----> tmpStrǳ������main����ջ֡�ϵ���ʱ����
	~MyString()
	MyString(operator=&&)	----> main����ջ֡�ϵ���ʱ�����str2��ֵ��ֻ��ֵָ��
	~MyString()
	~MyString()
	~MyString()
	*/

	/*
	* û���Ż�class֮ǰ��
	MyString(char*)
	MyString(char*)
	MyString(char*)
	MyString(MyString)	 ----> tmpStr��������main����ջ֡�ϵ���ʱ����
	~MyString()
	MyString(operator=)	 ----> main����ջ֡�ϵ���ʱ�����str2��ֵ
	~MyString()
	~MyString()
	~MyString()
	*/
	return 0;
}
#endif