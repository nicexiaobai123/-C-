#include <iostream>
#include <vector>
using namespace std;

//Allocator	�����ռ�������
template<typename T>
struct Allocator {
	//	�����ڴ�
	T* allocate(size_t size) {
		return (T*)malloc(sizeof(T) * size);
	}
	//	�ͷ��ڴ�
	void deallocate(T* p) {
		free(p);
	}
	//	ֻ���죬ʹ�ö�λnew�����õĿ������죻
	void construct(T* p, const T& val) {
		new (p) T(val);
	}
	//	ֻ����~T()����T���͵���������
	void destroy(T* p) {
		p->~T();
	}
};

template<typename T, typename Alloc = Allocator<T>>
class Vector {
public:
	//	����
	Vector(int size = 10) 
	{			
		_first = allocator.allocate(size);	//	��ֱ��new�����ˣ�����ֻ���ٿռ�
		_last = _first;
		_end = _first + size;
	}
	//	����
	~Vector()
	{
		//delete[] _first;
		for (T* f = _first; f != _last; f++)
		{
			allocator.destroy(f);
		}
		allocator.deallocate(_first);		//	����������ЧԪ�أ�Ȼ���ͷ�_firstָ��Ŀռ�
		_first = _last = _end = nullptr;
	}
	//	��������
	Vector(const Vector<T>& rhs) 
	{
		int size = rhs._end - rhs._first;
		int len = rhs._last - rhs._first;
		_first = allocator.allocate(size);	//	������ռ�͹������ֿ�����
		for (int i = 0; i < len; i++)
		{
			allocator.construct(&_first[i], rhs[i]);
		}
		_last = _first + len;
		_end = _first + size;

	}
	//	������ֵ
	Vector<T>& operator=(const Vector<T>& rhs) 
	{
		if (this == &rhs) {
			return *this;
		}

		// delete[] _first;
		for (T* f = _first; f != _last; f++) 
		{
			allocator.destroy(f);
		}
		allocator.deallocate(_first);

		int size = rhs._end - rhs._first;
		int len = rhs._last - rhs._first;
		_first = allocator.allocate(size);
		for (int i = 0; i < len; i++)
		{
			allocator.construct(&_first[i], rhs[i]);
		}
		_last = _first + len;
		_last = _first + size;
	}
	//	�����
	void push_back(const T& val)
	{
		if (isFull()) {
			expand();
		}
		allocator.construct(_last, val);	//	_lastָ����ڴ湹��һ��ֵΪval�Ķ���
		++_last;
	}
	//	����
	void pop_back()
	{
		if (isEmpty())
			return;
		allocator.destroy(--_last);			//	����Ҫ--_last����������ɾ����Ԫ��
	}
	//	�����
	T& back() const {
		if (isEmpty()) 
		{
			throw "vector is empty";
		}
		return *(_last - 1);
	}
	//	Ϊ��
	bool isEmpty() const { return _first == _last; }
	//	Ϊ��
	bool isFull() const { return _last == _end; }
private:
	//	������������
	void expand() 
	{
		int size = _end - _first;
		T* ptem = allocator.allocate(size * 2);
		for (int i = 0; i < size; i++) 
		{
			allocator.construct(&ptem[i], _first[i]);
		}

		for (T* f = _first; f != _last; f++) 
		{
			allocator.destroy(f);
		}
		allocator.deallocate(_first);

		_first = ptem;
		_last = _first + size;
		_end = _first + 2 * size;
	}
public:
	//	������
	class iterator 
	{
	public:
		iterator(T* p = nullptr) :_ptr(p) {}
		iterator& operator ++ ()
		{
			++_ptr;
			return *this;
		}
		bool operator != (const iterator& it) const
		{
			return _ptr != it._ptr;
		}
		T& operator * ()
		{
			return *_ptr;
		}
		const T& operator * () const
		{
			return *_ptr;
		}
	private:
		T* _ptr;
	};
	//	�����ṩbegin����
	iterator begin() 
	{
		return iterator(_first);
	}
	//	�����ṩend����
	iterator end()
	{
		return iterator(_last);
	}

private:
	T* _first;	//	��������ʼԪ��λ��
	T* _last;	//	��������ЧԪ�صĺ��
	T* _end;	//	����ռ�ĺ��
	Alloc allocator;
};

#if 0
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Vector<int> ve1;
	for (int i = 0; i < 5; i++) 
	{
		ve1.push_back(rand() % 100 + 1);
	}

	Vector<int>::iterator it;
	it = ve1.begin();
	for (; it != ve1.end(); ++it) 
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
#endif