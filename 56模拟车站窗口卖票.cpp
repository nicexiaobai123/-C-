#include <iostream>
#include <list>
#include <thread>
#include <mutex>
using namespace std;
#if 0

// ����߳̾���ͬһ��Դ�ĵ�ʱ��ͻᣬ�������Դ����˳�����У��ͻ���ھ�̬����
int ticketCount = 100;
mutex mtx;
void sellTicket(int index)
{
	while (ticketCount > 0) {
		// ��Ҫ���� + ˫���ж�
		/* ԭ����ticketCount = 1��ʱ��, �߳�1����>0, ����, ticketCount--ʱʱ��Ƭ����;
				�߳�2ͬ������>0,lock�����ȴ��߳�1ִ����; ʱ��Ƭ�л����߳�1,ticketCount--���,unlock
				��ʱticketCount=0�����߳�2������ִ��,ʹ����ticketCount=0,�߼�����������Ҫ �� + ˫���ж�
		*/
		//mtx.lock();
		//ticketCount--;
		//mtx.unlock();
		// 
		{
			// ��ֱ��ʹ��mutex������lock_guard��lock_guard���൱������ָ�������scope_ptr(û��������͸�ֵ)
			// ��ֹ�ٽ����������Ϊ�쳣��������������ȷ�ͷţ��������
			lock_guard<mutex> lock(mtx);
			if (ticketCount > 0) {
				// ���¾�̬�����Ĵ�����->�ٽ�������Ҫ����һ����ԭ�Ӳ���������Ҫ�̼߳以��->ʹ��mutex
				cout << "����:" << index << " ������" << ticketCount << "Ʊ�ˣ�" << endl;
				ticketCount--;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
int main()
{
	list<thread> thdList;
	for (int i = 1; i <= 3; i++) {
		thdList.push_back(std::thread(sellTicket, i));
	}
	for (thread& t : thdList) {
		t.join();
	}
	cout << "��Ʊ�Ѿ�ȫ������!" << endl;
	return 0;
}
#endif