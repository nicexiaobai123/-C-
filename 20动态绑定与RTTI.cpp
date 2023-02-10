#include <iostream>
#include <typeinfo>
using namespace std;
#if 0
class Base
{
public:
	Base(int data) :ma(data) {}
	virtual void show() { cout << "Base::show()" << endl; }
	virtual void show(int a) { cout << "Base::show(int)" << endl; }
	void print() { cout << "Base::print()" << endl; }
protected:
	int ma;
};
class Drived : public Base
{
public:
	Drived(int data) :Base(data), mb(data) {}
	void show() { cout << "Drived::show()" << endl; }
protected:
	int mb;
};

int main()
{
	Drived d(20);
	Base* bp = &d;
	bp->print();		//	��̬��
	bp->show();			//	��̬��

	//	��Ϣ
	cout << "================" << endl;
	cout << sizeof(Base) << endl;
	cout << sizeof(Drived) << endl;
	cout << typeid(bp).name() << endl;
	cout << typeid(*bp).name() << endl;		//	��������麯����*pdʶ��ľ�������ʱ�ڵ����ͣ�������RTTI
	return 0;
}
#endif