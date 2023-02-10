#include <iostream>
#include <vector>
using namespace std;
#if 0
//	����
class Base
{
public:
	virtual void show() { cout << "Base::show" << endl; }
};
//	������
class Derive01 : public Base
{
public:
	void show() { cout << "Derive01::show" << endl; }
};
class Derive02 : public Base
{
public:
	void show() { cout << "Derive02::show" << endl; }
	//	�������¹��ܵ�API�ӿ�
	void Derive02Show() { cout << "Derive02::Derive02Show" << endl; }
};
//	�ṩ�ӿ�
void showFunc(Base* ptr)
{
	//	���ܣ������Derive02���͵ģ��򲻵���show������������Derive02Show���������������show����
	//	dynamic_cast��ʹ�ã�RTTI��Ϣʶ������ת����	��RTTI��Ϣ����ת�������������ĵ�ַ������ת������nullptr
	//	p->vfptr->vftable RTTI��Ϣ������ǣ�dynamic_castת���ɹ�
	Derive02* p = dynamic_cast<Derive02*>(ptr);		//	��ptr��RTTI��Ϣ�Ƿ���Derive02���͵�
	if (p != nullptr) {
		p->Derive02Show();
	}
	else {
		ptr->show();
	}
}
//	�ṩ�ӿ�
void showFunc02(Base* ptr)
{
	//	�����ʹ��static_cast����ת�������������ڱ���ʱ�ڵ�ת�������漰ʶ��RTTI��Ϣ����ÿ�ζ���ת���ɹ�
	Derive02* p = static_cast<Derive02*>(ptr);
	if (p != nullptr) {		//	ʼ�ն���ת���ɹ�������Ϊnullptr
		p->Derive02Show();		//	�п���p2������Derive02*���ͣ�����Derive01*����
	}
	else {
		ptr->show();
	}
}

int main()
{
	// =======================================
	//	1: const_cast��ʹ��
	//	ָ��������ÿ���
	int a = 10;
	const int* p = &a;
	//	ָ�루���ã�����
	int* q0 = const_cast<int*>(p);
	
	const int b = 20;
	//	��ͨ���ͣ�������
	// int q1 = const_cast<int>(b);

	// =======================================
	//	2: static_cast��ʹ��
	int num = 10;
	//	û����ϵ�����Ͳ����ã���������Ϊ��ȫ�����Ͳſ���
	//short* q2 = static_cast<short*>(&num);

	// =======================================
	//	3: reinterpret_cast��ʹ�ã�C����ǿת
	int num1 = 10;
	double* q3 = reinterpret_cast<double*>(&num);

	// =======================================
	Derive01 Der1;
	Derive02 Der2;
	showFunc(&Der1);
	showFunc(&Der2);
	cout << "==========================" << endl;
	showFunc02(&Der1);
	showFunc02(&Der2);

	return 0;
}
#endif