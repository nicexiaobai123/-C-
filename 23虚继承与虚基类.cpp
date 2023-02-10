#include <iostream>
#include <vector>
using namespace std;

#if 0

//	����
class Base {
public:
	virtual void show() { cout << "A::show()" << endl; }
	void operator delete(void* p)
	{
		cout << "free��ַ��" << p << endl;
		free(p);
	}
private:
	int ma;
};
//	������ Derive����̳У���ʱ��Base�������
class Derive : virtual public Base {
public:
	void show() { cout << "B::show()" << endl; }
	void* operator new (size_t size)
	{
		void* p = malloc(size);
		cout << "malloc�����ַ: " << p << endl;
		return p;
	}
private:
	int mb;
};
int main()
{
	//	�������ͨ�ļ̳�
	// cout << sizeof(Base) << endl;	//	vfptr��ma 8�ֽ�
	// cout << sizeof(Derive) << endl;	//	vfptr��ma��mb 12�ֽ�

	//	�������̳У����һ��vbptr��ָ��vbtable
	//	vbtable[0]��vbptr������ƫ�ƣ�vbtable[1]����������ݵ�ƫ��

	cout << sizeof(Derive) << endl;	//	vbptr��mb����������ݣ�vfptr��ma����16�ֽ�

	cout << "=====================" << endl;
	//	��̳�+�麯����vs�������ϻ���ִ���Linux��g++�ϲ���
	//	����ԭ��: �ͷ��ڴ��ַ��������ڴ��ַ��һ��
	Base* p = new Derive;

	cout << "new���صĵ�ַ��" << p << endl;
	p->show();

	delete p;
	/*
		malloc�����ַ: 00B6DCF8
		new���صĵ�ַ��00B6DD00
		B::show()
		free��ַ��00B6DD00
	*/
	return 0;
}
#endif