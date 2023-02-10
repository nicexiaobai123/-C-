#include <iostream>
#include <memory>
#include <thread>
using namespace std;
#if 0
// ��
class Test
{
public:
	Test() :_ptr(new int(20)) { cout << "Test()" << endl; }
	~Test()
	{
		delete _ptr;
		_ptr = nullptr;
		cout << "~Test()" << endl;
	}
	void show() { cout << "show:" << *_ptr << endl; }
private:
	int* volatile _ptr;
};

// �̻߳ص�����
void threadPro1(Test* p)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	p->show();
}
void threadPro2(weak_ptr<Test> p)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	// ��������ָ��������ǿ����ָ��
	shared_ptr<Test> sp = p.lock();
	if (sp != nullptr) {
		sp->show();
	}
}

// ������
int main()
{
	Test* p1 = new Test;
	std::thread t1(threadPro1, p1);
	//delete p1;	������������ᵼ�����̷߳��ʲ�������Ķ�������Ƿ���
	t1.join();

	// ǿ��ָ������һ���ڶ��߳��ϵ�Ӧ��
	shared_ptr<Test> p2(new Test);
	std::thread t2(threadPro2, weak_ptr<Test>(p2));
	t2.join();
	t2.detach();	// ���óɷ����߳������̻߳���ִ���꣬��������ֱ������
					// �����ǿ��ָ���ϵĺô�������֪����������Ƿ���ڣ���������ھͲ�ִ��show()
	return 0;
}
#endif