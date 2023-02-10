#include <iostream>
#include <functional>
#include <string>
#include <thread>
#include <vector>
using namespace std;
#if 0

// �߳���Ϣ  function�������� 
class Thread
{
public:
	Thread(function<void(int)> func, int no)
		: _func(func), _no(no)
	{	}
	thread start() { return thread(_func, _no); }
private:
	function<void(int)>	_func;	// �ص�����
	int _no;					// ����
};

// �̳߳�  bind�󶨳�Ա���� 
class ThreadPool
{
public:	
	ThreadPool() {}
	~ThreadPool() { for (auto v : _pool) delete v; }
	void startPool(int size) 
	{
		for (int i = 0; i < size; i++) 
			// ��Ҫ������������Ϊ�̻߳ص����������ǳ�Ա������������thisָ��
			_pool.push_back(new Thread(bind(&ThreadPool::runInThread, this, placeholders::_1), i));

		for (Thread* t : _pool)
			_handlers.push_back(t->start());

		for (thread& handler : _handlers)
			handler.join();
	}
private:
	// ��runInThread�����Ա�����䵱�̺߳���
	void runInThread(int no) {
		cout << "call runInThread id: " << no << endl;
	}
private:
	vector<Thread*> _pool;
	vector<thread> _handlers;
};
//////////////////////////////////////////////////////////////
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ThreadPool pool;
	pool.startPool(10);
	return 0;
}
#endif