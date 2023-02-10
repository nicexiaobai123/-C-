#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
#if 0
//	===== ���⣺����ʵ������+����ģ�� ���Խ�һ�������͵�ϸ�����ͽ������͵Ĳ����� =====
// T�������д�����
template <typename T>
void func(T arg)
{
	cout << typeid(T).name() << endl;
}
// �Ҹ�������ָ�����ͣ���ѷ���ֵ����������ȡ����
template <typename R, typename A1, typename A2>
void func2( R(*a)(A1, A2) )
{
	cout << "����: ";
	cout << typeid(R).name() << "  ";
	cout << typeid(A1).name() << "  ";
	cout << typeid(A2).name() << endl;
}
// ������ʶ�����еķ���: �ֿ�ʶ�������ࡢ����ֵ������
template <typename R, typename T,typename A1, typename A2>
void func3(R(T::*a)(A1, A2))
{
	cout << "�෽������: ";
	cout << typeid(R).name() << "  ";
	cout << typeid(T).name() << "  ";
	cout << typeid(A1).name() << "  ";
	cout << typeid(A2).name() << endl;
}
// ������
class Test
{
public:
	void show(char, int) { cout << "Test::show()" << endl; }
};
int sum(int a, int b) { return a + b; }
int main()
{
	func(20);
	func("aaa");
	// ����ָ��
	cout << endl;
	func(sum);
	func2(sum);
	// ���еķ���
	cout << endl;
	func(&Test::show);
	func3(&Test::show);
	return 0;
}
#endif