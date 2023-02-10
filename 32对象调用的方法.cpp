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
		this->ma = t.ma;
		cout << "operator=" << endl;
		return *this;
	}
private:
	int ma;
};
Test t0(10);	//	��һ�����죬�ڽ���main֮ǰ���������ʱ����
int main()
{
	cout << "----------------------" << endl;
	Test t1;
	Test t2(t1);
	Test t3 = t1;			//	��Ȼʹ�õ��ǿ��������ʼ��
	// Test(10)��ʾ������ʱ�����������ڣ����ڵ����
	Test t4 = Test(10);		//	��Test t4(10);û������
	cout << "----------------------" << endl;
	
	t4 = t2;				//	���� operator=
	t4 = Test(10);			//	��ʽ������ʱ����Test(10)���졢 operator=��Test(10)����
	t4 = (0, 10);			//	��ʽ������ʱ����(0,10)Ϊ���ű��ʽ��Test(10)���졢 operator=��Test(10)����
	cout << "----------------------" << endl;

	// Test* p = &Test(50);		//	p��ΪҰָ�룬Test(50)���졢 operator=��Test(50)����
	const Test& ref = Test(50);	//	Test(50)����,������
	cout << "----------------------" << endl;

	static Test t5 = Test(10);	//	��̬������Ȼ��.data�������ǳ�ʼ������䴦���������ʱ����
	cout << "----------------------" << endl;
	return 0;
}
Test t6(10);	//	�ڶ������죬�ڽ���main֮ǰ���������ʱ����
#endif