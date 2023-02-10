#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;
#if 0
void hello(string str)
{
	cout << str << endl;
}
class Test
{
public:
	void show(string str) { cout << str << endl; }
};
int main()
{
	// function������������
	function<void(string)> func1 = hello;
	func1("hello function");

	// ����������������
	function<int(int, int)> func2 = [](int a, int b)->int {return a + b; };
	cout << func2(100, 100) << endl;

	// ������ĳ�Ա��������
	function<void(Test*, string)> func3 = &Test::show;
	Test tmp;
	func3(&tmp, "Test::show() call");

	cout << "--------------------------" << endl;

	// C���Եĺ���ָ�����lambda
	int(*fptr)(int,int) = [](int a, int b)->int {return a + b; };
	cout << fptr(100, 100) << endl;

	// C���Ժ���ָ���޷��������հ������صĺ������󣻶�ǿ���function�Ϳ���
	// bool(*fptr1)(int) = bind1st(less<int>(), 10);
	function<bool(int)> func4 = bind1st(less<int>(), 10);
	cout << func4(11) << endl;
	return 0;
}
#endif 