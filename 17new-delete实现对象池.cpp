#include <iostream>
using namespace std;
//	��ʱ��Ƶ����ʹ��push��pop���������кܶ��new��delete����������
//	����new��delete�������ڴ�   -----  �����
//	������һ���㹻����ڴ棬ֱ��ʹ��������ڴ�; ����malloc��free����

//	���У��ײ�ʹ���������
template <typename T>
class Queue
{
public:
	Queue()
	{
		//	����ͷ�ڵ�
		_front = _rear = new QueueItem();
	}
	~Queue()
	{
		//	�ȹ黹�ڴ棬���ͷ��ڴ�أ����������Ὣ����������ڴ�黹����
		//	�����������ͷų�ֻ��Ŀǰ�ķ�����STL���������ɲ��ܰ������ͷų�
		//	�ⷽ������ȱ�㣺һ���ز��������������أ��ͷŵ�ʱ��ֻ���ͷ�һ����
		QueueItem* cur = _front;
		while (cur != nullptr)
		{
			_front = _front->_next;
			delete cur;
			cur = _front;
		}
		//	�ͷų�
		QueueItem::destory();
	}
	T& front() const { return  _front->_next->_data; }
	bool isEmpty() const { return _rear == _front; }
	//	��ӣ��Ƚ��ȳ�
	void push_back(const T& val)
	{
		QueueItem* ptr = new QueueItem(val);
		_rear->_next = ptr;
		_rear = ptr;
	}
	//	����
	void pop_front() 
	{
		if (isEmpty()) return;
		QueueItem* n = _front->_next;
		_front->_next = n->_next;
		delete n;
		//	ɾ�������û�нڵ���
		if (_front->_next == nullptr)
		{
			_rear = _front;
		}
	}
private:
	struct QueueItem
	{
		//	Ĭ�Ϲ��죬T()
		QueueItem(T data = T())
			:_data(data), _next(nullptr) {}
	public:
		//	�����ڴ�
		static void* operator new (size_t size)
		{
			//	��һ�ξ�������һ���㹻����ڴ棬��������Ϊ���ء�
			if (QueueItem::_itemPool == nullptr)
			{
				QueueItem::_itemPool = (QueueItem*)new char[QueueItem::POOL_ITEM_SIZE * sizeof(QueueItem)];
				QueueItem* ptr = _itemPool;
				//	���һ���next��ֵΪnullptr
				for (; ptr < _itemPool + POOL_ITEM_SIZE - 1; ptr++)
				{
					ptr->_next = (ptr + 1);
				}
				ptr->_next = nullptr;
			}
			//	�ӳ��з���
			QueueItem* p = _itemPool;
			_itemPool = _itemPool->_next;
			return p;
		}
		//	�ͷ��ڴ�	
		static void operator delete (void* ptr)
		{
			//	ֱ�ӽ��ͷŵ��ڴ������оͿ�����,����free
			QueueItem* cur = (QueueItem*)ptr;
			cur->_next = _itemPool;
			_itemPool = cur;
		}
		//	�ͷų�
		static void destory()
		{
			if (_itemPool != nullptr)
			{
				free(_itemPool);
			}
		}
	public:
		T _data;
		QueueItem* _next;
		static QueueItem* _itemPool;
		//	��̬������Ա��������ֱ�����г�ʼ��
		static const int POOL_ITEM_SIZE = 1000;	
	};
private:
	QueueItem* _front;	//	ָ��ͷ��β
	QueueItem* _rear;	//	ָ���β	
};
//	typename���Ը��߱���������һ����һ������
template<typename T>
typename Queue<T>::QueueItem* Queue<T>::QueueItem::_itemPool = nullptr;

#if 0
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Queue<int> Que;
	for (int i = 0; i < 1000; i++)
	{
		Que.push_back(15);
	}
	for (int i = 0; i < 1000; i++)
	{
		Que.pop_front();
	}
	cout << Que.isEmpty() << endl;
	return 0;
}
#endif