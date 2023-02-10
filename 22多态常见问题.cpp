#include <iostream>
using namespace std;

#if 0

//	����
class Animal {
public:
	Animal(const string& str) :name(str) {}
	virtual void bark() {}
protected:
	string name;
};
//	��
class Dog :public Animal {
public:
	Dog(const string& str) :Animal(str) { }
	virtual void bark() {
		cout << name << ": wangwang" << endl;
	}
};
//	��
class Pig :public Animal{
public:
	Pig(const string& str) :Animal(str) { }
	virtual void bark() {
		cout << name << ": hengheng" << endl;
	}
};

//	����
class Base
{
public:
	virtual void show(int i = 10) {
		cout << "call Base::show i:" << i << endl;
	}
	virtual void print() {
		cout << "call Base::print" << endl;
	}
};
//	������
class Derive : public Base
{
public:
	virtual void show(int i = 20) {
		cout << "call Derive::show i:" << i << endl;
	}
private:
	virtual void print() {
		cout << "call Derive::print" << endl;
	}
};

//	����
class A
{
public:
	A() { 
		cout << "A::ctor" << endl; 
		clear(); 
	}
	virtual void show() { cout << "A::show" << endl; }
private:
	void clear() { memset(this, 0, sizeof(*this)); }
};
//	������
class B : public A
{
public:
	B() { cout << "B::ctor" << endl; }
	virtual void show() { cout << "B::show" << endl; }
};

//	
int main()
{
	//	����һ�����������vfptr
	Animal* p1 = new Pig("pppp");
	Animal* p2 = new Dog("wwww");

	int temp = *(int*)p1;
	*(int*)p1 = *(int*)p2;
	*(int*)p2 = temp;

	p1->bark();
	p2->bark();
	delete p1;
	delete p2;

	//	������� �麯��Ӧ�ñ���ʹ��Ĭ�ϲ���
	cout << "=======================" << endl;
	Base* b1 = new Derive();

	//	����ѹջ���ڱ���׶ξ��Ѿ�ȷ���õģ���ָ��������Base*�����ָ���Ͼͻ�ѹջ10
	//	��̬���Ƿ��������н׶Σ���call ecx֮ǰ���������Ѿ�ѹ���� 
	b1->show();			//	call Derive::show i:10
	delete b1;

	//	�������� ����׶εķ�������
	cout << "=======================" << endl;
	Base* b2 = new Derive();

	//	ΪʲôDerive����˽�еķ����������ˣ�
	//	��Ϊ�����Ƿ��������н׶εģ���Ա�����ܲ��ܵ��ã�����˵�����ķ���Ȩ���Ƿ���public�����ڱ���׶ξ�ȷ���õ�
	//	���ȿ�b2->print����Ϊ�����е��麯�������ͱ���ͨ���ˣ����ж�̬�󶨣����н׶ξͲ��ῴʲôpublic��private��
	b2->print();		//	call Derive::print
	delete b2;

	//	�����ģ� vfptr��д��ʱ��
	cout << "=======================" << endl;
	
	// A* c1 = new A;
	// c1->show();
	// delete c1;
	
	//	Ϊʲô���治����������ԣ�
	//	1.A���캯������Ὣvfptr���㣬ʹ���麯��show�Ƕ�̬�󶨣�����ʱvfptrû��ָ����ȷ��vftable
	//	2.B�̳�A���ȵ���A���캯��������vfptr���ٵ���B�Ĺ��캯����Ϊvfptr��ֵ��ָ��B���vftable������������麯��show������ȷ����
	A* c2 = new B;
	c2->show();			//	B::show
	delete c2;

	return 0;
}
#endif