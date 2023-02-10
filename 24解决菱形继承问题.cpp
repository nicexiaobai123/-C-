#include <iostream>
using namespace std;
#if 0
// =======================================
// ���ϵĻ���
class A {
public:
	A(int data) :ma(data) { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
protected:
	int ma;
};
// =======================================
// һ�ؼ̳�
class B : virtual public A{
public:
	B(int data) :A(data), mb(data) { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
protected:
	int mb;
};
class C : virtual public A {
public:
	C(int data) :A(data), mc(data) { cout << "C()" << endl; }
	~C() { cout << "~C()" << endl; }
protected:
	int mc;
};
// =======================================
// ���μ̳У���Ҫ���ϲ�̳иĳ���̳�
class D : public B, public C {
public:
	//	��A::A��: û�к��ʵ�Ĭ�Ϲ��캯������
	//	ֻ��һ��A::ma�ˣ�A::ma�ǿ���D�ϵģ���ȻҪD��ʼ��
	//  B,C����̳е�A��vbtable���洢int ma����D��ͨ�̳�B��C����������vbtable�����int ma��һ���ģ�ֱ�Ӻϳ�һ��������D��
	//	���﷨������⣺A::maֻ��һ�ݣ���B��C�����Գ�ʼ����������˭Ϊ׼�أ�Ӧ��D�Լ�����ʼ������D�Լ�Ϊ׼
	D(int data) :A(data), B(data), C(data), md(data) { cout << "D()" << endl; }
	~D() { cout << "~D()" << endl; }
protected:
	int md;
};

int main()
{
	//	���μ̳е����⣬��������ma��ma��ma��mb��mc��md
	//	����취��B��C����̳�A����A��������
	cout << sizeof(D) << endl;
	D d1(10);

	//	D��ʵ�������ڴ沼��(D������̳У��������D��vbptr)��
	/*
	class D size(24) :
			+-- -
		0	| +--- (base class B)
		0	| | {vbptr}
		4   | | mb
			| +---
		8	| +--- (base class C)
		8   | | {vbptr}
		12  | | mc
			| +---
		16	| md
			+---
			+--- (virtual base A)
		20	| ma
			+ ---
	*/
	return 0;
}
#endif