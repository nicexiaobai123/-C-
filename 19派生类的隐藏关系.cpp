#include <iostream>
using namespace std;
#if 0
class Base
{
public:
	Base(int data) :ma(data) {}
	void show() { cout << "Base::show()" << endl; }
	void show(int a) { cout << "Base::show(int)" << endl; }
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
	Base base(10);
	Drived dri(20);

	//	������� <- ���������	���ʹ��µ��ϵ�ת����Y
	base = dri;	
	//	��������� <- �������	���ʹ��ϵ��µ�ת����N
	//	dri = base;
	
	//	����ָ�루���ã� <- ���������	���ʹ��µ��ϵ�ת����Y
	Base* pb = &dri;
	pb->show();
	//	������ָ�루���ã� <- �������	���ʹ��ϵ��µ�ת����N
	//	Drived* pd = (Drived*)&base;	//����ȫ���漰���Ƿ��ڴ�ķ���

	cout << "======================" << endl;
	Drived dr1(10);
	//	dr1.show();			//	Drived::show()
	//	dr1.show(10);		//	�������л���ͬ�����������౾ͬ������ȫ��������
	dr1.Base::show();	//	Base::show()	������
	dr1.Base::show(10);	//	Base::show(int)	������

	return 0;
}
#endif