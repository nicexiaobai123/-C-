#include <iostream>
#include <thread>
#include <atomic>
#include <list>
using namespace std;
#if 0

// ʹ��atomic���ͱ���++��--�ܱ�֤��ԭ�Ӳ��������̰߳�ȫ��
// ʹ��volatile����һ���̸߳ı�data�ε����ݺ�������߳��ܹ����Ϸ��ʵ�����ֵ��������һ������ֵ
// volatile���Ƿ�ֹ���̶߳Թ��������ȫ�ֱ��������л��棬���ʵ�ԭʼ�ڴ������ֵ
volatile std::atomic_bool isReady = false;
volatile std::atomic_int myCount = 0;

// ���̺߳���
void task()
{
	if (!isReady) {
		// ��ǰ�߳��ó�CPUʱ��Ƭ���ȴ��´ε���
		std::this_thread::yield();
	}
	// ʹ��myCount++���̰߳�ȫ��
	for (int i = 0; i < 100; i++) myCount++;
}
// ���̺߳���
int main()
{
	list<std::thread> tlist;
	for (int i = 0; i < 10; i++) {
		tlist.push_back(std::thread(task));
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
	isReady = true;
	cout << "myCount: " << myCount << endl;

	for (thread& t : tlist) {
		t.join();
	}
	return 0;
}
#endif