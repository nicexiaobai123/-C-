#include <iostream>
#include <memory>
using namespace std;

#if 0

// �������ʱ����ǿ����ָ��shared_ptr���������ط����ö���ʱ��ʹ��������ָ��weak_ptr

class B;
class A
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
public:
	// ������ָ��
	weak_ptr<B> ptr_b;
};

class B
{
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
public:
	// ������ָ��
	weak_ptr<A> ptr_a;
};

int main()
{
	//	һ����������Ӧһ��������Դ
	shared_ptr<A> ptr1(new A);		// A�����ü���Ϊ1
	shared_ptr<B> ptr2(new B);		// B�����ü���Ϊ1

	ptr1->ptr_b = ptr2;				// ������ָ�벻��������ü�������ֻ��һ���۲��ߵ�����
	ptr2->ptr_a = ptr1;				// ������ָ�벻��������ü�������ֻ��һ���۲��ߵ�����

	cout << ptr1.use_count() << endl;
	cout << ptr2.use_count() << endl;

	//	��������A��B�����ü���-1�����ü���Ϊ0����ȷ�ͷ���Դ
	/*
		A()
		B()
		1
		1
		~B()
		~A()
	*/
	return 0;
}
#endif