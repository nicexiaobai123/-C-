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
	int getData()const { return ma; }
private:
	int ma;
};
//	�Ż�
//	1�������������ã������βεĹ���������
Test GetObject(Test& t)
{
	int val = t.getData();
	//Test tmp(val);
	//return tmp;
	return Test(val);
	//	2�����ض���ʱ��������ʱ����
	//	����ʱ���󿽱��¶�����ʱ�����Ż���������ʱ����Ĺ���������
}
int main()
{
	Test t1(10);
	//	3������ʱ������ʼ����ʽ���ն����Ǹ�ֵ��ʽ
	//	����ʱ���󿽱��¶�����ʱ�����Ż���������ʱ����Ĺ���������
	Test t2 = GetObject(t1);
	//	t2 = GetObject(t1);		//�ø�ֵ��ʽʱmain���������ʱ����
	return 0;
	return 0;
}
#endif