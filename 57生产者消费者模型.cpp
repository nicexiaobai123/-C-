#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;
#if 0
// ������������ģ�ͣ�����������һ����Ʒ��֪ͨ�����ߣ��������ˣ���������֪ͨ�����߼���������Ʒ

std::mutex mtx;				// ���廥�����������̼߳�Ļ���
std::condition_variable cv;	// ���������������������̼߳��ͬ��ͨ�Ų���

template<typename T = int>
class Queue {
public:
	// ============ ���� =============
	void put(T val) {
		unique_lock<std::mutex> lok(mtx);
		// Ϊʲô��while������if�� ���������һ�������߳�һ�������߳���if�������������߳����������Ѿͻ����
		while (!Que.empty()) {
			// ��Ϊ�գ�����Բ���������
			// 1��wait������������ԭ�ӣ���#1�ȴ��ź�  #2�ͷ���
			// 2��wait��������(notify_all)������ȴ�����������ȡ������
			cv.wait(lok); 
		}
		Que.push(val);
		// �����֪꣬ͨ����������
		// �����̻߳�õ���֪ͨ���ͻ᣺�ȴ�״̬=>����״̬=>��ȡ�����ż���ִ��
		cv.notify_all();
		cout << "������ ����" << val << "����Ʒ" << endl;
	}
	// ============ ���� =============
	T get() {
		unique_lock<std::mutex> lok(mtx);
		// �������û�У�������
		while (Que.empty()) {
			cv.wait(lok);
		}
		T val = Que.front();
		Que.pop();
		cv.notify_all();
		cout << "������ ����" << val << "����Ʒ" << endl;
		return val;
	}
private:
	queue<T> Que;
};
// �������̺߳���
void consumer(Queue<int>* que)
{
	for (int i = 1; i <= 10; i++) {
		que->put(i);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
// �������̺߳���
void producer(Queue<int>* que)
{
	for (int i = 1; i <= 10; i++) {
		que->get();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
// ���̺߳���
int main()
{
	// -��Ʒ-
	Queue<int> que;
	std::thread t1(consumer,&que);
	std::thread t2(producer,&que);
	t1.join();
	t2.join();
	return 0;
}
#endif