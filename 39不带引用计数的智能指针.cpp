#include <iostream>
#include <memory>
using namespace std;
#if 0
int main()
{
	//==== �������ü�����ָ�룬һ���ⲿ��Դֻ�ܱ�һ��ָ��ָ��ָ����unique�� ====
	//	1��auto_ptr����17�б��Ƴ��ˣ���Ҫ�л���14�����������ʹ��
	auto_ptr<int> p1(new int);
	auto_ptr<int> p2(p1);	//	ʹ��ǳ����������ԭ��p1��ָ��ָ��nullptr�����ʹ���߲�֪���ײ�ԭ��ʹ�������ǳ�Σ��
	*p2 = 10;				//	��ʾ��Դת��
	//*p1 = 10;				//	����nullptr

	//	2��C11�±�׼��boost::scoped_ptr
	//	����������͸�ֵɾ����
	// scoped_ptr(consts coped_ptr<T>& ptr) = delete;
	// scoped_ptr<T>& operator=(consts coped_ptr<T>& ptr) = delete;

	//	3���Ƽ�ʹ��unique_ptr��ͬ����������͸�ֵɾ���ˣ����ṩ����ֵ���ð汾��
	unique_ptr<int> p3(new int);
	unique_ptr<int> p4(std::move(p3));	//	ʹ������ʹ�ù����� ֪���Լ��Ѿ��ƶ��ˣ�auto_ptr�����û���֪����
	//*p3 = 20;	�Ѿ����ƶ��ˣ����ڳ�����Դ��
	*p4 = 10;
	cout << *p4 << endl;
	return 0;
}
#endif