#include <iostream>
#include <functional>
#include <string>
using namespace std;
#if 0
/////////////////////////////////////////////////////////////
void hello(string str) { cout << str << endl; }
int sum(int a, int b) { return a + b; }
struct Test { int sum(int a, int b) { return a + b; } };
int main()
{
	// bind�Ǻ���ģ�� �����Զ�����ģ�����Ͳ���
	bind(hello, "hello bind!")();
	cout << bind(sum, 10, 10)() << endl;
	cout << bind(&Test::sum, Test(), 10, 10)() << endl;

	// ����ռλ�� ������binder���ֶ���,������bind1st��Щֻ�ܰ�һ��������
	// ����������䣬�޷�����ʹ��
	bind(hello, placeholders::_1)("hello bind2!");
	cout << bind(&Test::sum, Test(), 10, placeholders::_1)(20) << endl;

	// ��bind���صİ���binder��������
	function<void(string)> func = bind(hello, placeholders::_1);
	func("hello huawei");
	func("hello honor");

	return 0;
}
#endif