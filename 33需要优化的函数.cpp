#include <iostream>
using namespace std;
#if 0
class Test
{
public:
	//��ͨ����
	Test(int x = 5) :ma(x) { cout << "Test(int)" << endl; }
	//��������
	Test(const Test& t) :ma(t.ma) { cout << "Test(Test)" << endl; }
	//��������
	~Test() { cout << "~Test()" << endl; }
	//������ֵ
	Test& operator = (const Test& t)
	{
		cout << "operator=" << endl;
		this->ma = t.ma;
		return *this;
	}
	int getData() { return ma; }
private:
	int ma;
};

//	��Ҫ�Ż��ĺ���
//	3.ʵ�θ��β��ǳ�ʼ�������ÿ�������
//	4.tmp���캯��
Test GetObject(Test t)
{
	int val = t.getData();
	Test tmp(val);
	return tmp;
	//	5.tmp��main�е���ʱ���󣬿�������
	//	6.tmp����	7.�β�t����
}
int main()
{
	Test t1(10);		//1. t1���캯��
	Test t2;			//2. t2���캯��	
	t2 = GetObject(t1);	//8. t2��operator=   9.��ʱ��������
	return 0;
	//10. t2����
	//11. t1����
}
#endif