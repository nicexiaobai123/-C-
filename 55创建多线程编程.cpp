#include <iostream>
#include <thread>
using std::cout;
using std::endl;
#if 0

void threadHandle1(int time) {
	// ˯��time��
	std::this_thread::sleep_for(std::chrono::seconds(time));
	cout << "hello thread1!" << endl;
}
void threadHandle2(int time) {
	// ˯��time��
	std::this_thread::sleep_for(std::chrono::seconds(time));
	cout << "hello thread2!" << endl;
}
int main()
{
	// ����һ���̶߳��󣬴���һ���̺߳������߳̾�������
	std::thread t1(threadHandle1,2);
	std::thread t2(threadHandle2, 3);
	// ���̵߳ȴ����߳̽������������̣߳������̼߳���ִ��
	t1.join();
	t2.join();
	// ���߳���������̬������̬�ͷǷ���̬��Ĭ��һ��Ϊ�Ƿ���̬
	// ����������߳�Ϊ����̬�������߳̾ͻ��Զ�����
	// t1.detach();
	cout << "hello main thread!" << endl;
	return 0;
}
#endif
