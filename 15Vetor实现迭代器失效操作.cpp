#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

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

											//	������¼������������
		Iterator_Base* pre = &this->_head;
		Iterator_Base* it = this->_head._next;
		while (it != nullptr)
		{
			it->_cur->_pVec = nullptr;
			pre->_next = it->_next;
			delete it;
			it = pre->_next;
		}
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
		verify(_last, _last);				//	���Ԫ�صĵ�����ʧЧ
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
		verify(_first, _end);				//	ȫ����Χ��������ʧЧ

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
		friend class Vector<T, Alloc>;
		iterator(Vector<T, Alloc>* _pvec = nullptr, T* p = nullptr)
			:_ptr(p), _pVec(_pvec)
		{
			Iterator_Base* itb = new Iterator_Base(this, _pVec->_head._next);
			_pVec->_head._next = itb;
		}
		iterator& operator ++ ()
		{
			if (_pVec == nullptr)
			{
				//	������ʧЧ�ľ����쳣
				_STL_REPORT_ERROR("iterator invalid");
				//throw "iterator invalid";
			}
			++_ptr;
			return *this;
		}
		bool operator != (const iterator& it) const
		{
			//	��� �������Ϸ��� �� ͬһ����
			if (_pVec == nullptr || _pVec != it._pVec)
			{
				_STL_REPORT_ERROR("iterator incompatabke");
				//throw "iterator incompatabke";
			}
			return _ptr != it._ptr;
		}
		T& operator * ()
		{
			if (_pVec == nullptr)
			{
				_STL_REPORT_ERROR("iterator invalid");
				//throw "iterator invalid";
			}
			return *_ptr;
		}
		const T& operator * () const
		{
			if (_pVec == nullptr)
			{
				_STL_REPORT_ERROR("iterator invalid");
				//throw "iterator invalid";
			}
			return *_ptr;
		}
	private:
		T* _ptr;
		//	��ǰ���������ĸ���������
		Vector<T, Alloc>* _pVec;
	};

	//	ÿ����begin����end���صĵ���������һ�������¼
	//	�����ṩbegin����
	iterator begin()
	{
		return iterator(this,_first);
	}
	//	�����ṩend����
	iterator end()
	{
		return iterator(this,_last);
	}
	//	����
	iterator insert(iterator& it, const T& val)
	{
		if (isFull())
		{
			expand();
		}
		verify(it._ptr, _last);
		T* temp = _last;
		while (temp > it._ptr)
		{
			//	������Ҫʹ�ÿռ������������������
			allocator.construct(temp, *(temp - 1));
			allocator.destroy(temp - 1);
			//*temp = *(temp - 1);
			 temp--;
		}
		allocator.construct(it._ptr, val);
		*it._ptr = val;
		++_last;
		return iterator(this, it._ptr);
	}
	//	ɾ��
	iterator erase(iterator& it)
	{
		verify(it._ptr, _last);
		T* temp = it._ptr;
		while (temp < _last - 1)
		{
			allocator.destroy(temp);
			allocator.construct(temp, *(temp + 1));
			//*temp = *(temp + 1);
			temp++;
		}
		allocator.destroy(temp);
		--_last;
		return iterator(this, it._ptr);
	}

private:
	//	ֻҪ�������е���������first - last֮�䣬��ʧЧ
	void verify(T* first,T* last)
	{
		Iterator_Base* pre = &this->_head;
		Iterator_Base* it = this->_head._next;
		while (it != nullptr)
		{
			if (it->_cur->_ptr >= first && it->_cur->_ptr <= last)
			{
				//	�õ�����ʧЧ�����ǰ�ָ��ǰ������ָ���ÿ�
				it->_cur->_pVec = nullptr;
				//	�����жϺ����ڵ��Ƿ�ʧЧ
				pre->_next = it->_next;
				delete it;
				it = pre->_next;
			}
			else 
			{
				pre = it;
				it = it->_next;
			}
		}
	}
	//	����������ʧЧ���Ӵ���
	struct Iterator_Base
	{
		Iterator_Base(iterator* c = nullptr, Iterator_Base* n = nullptr)
			:_cur(c), _next(n) {}
		iterator* _cur;
		Iterator_Base* _next;
	};
	Iterator_Base _head;	//	����ͷ
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

	Vector<int> vec1;
	for (int i = 0; i < 15; i++) {
		vec1.push_back(rand() % 50 + i);
	}

	//	��ӡ
	Vector<int>::iterator it = vec1.begin();
	for (; it != vec1.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//	ʹ��pop_back�������һ��������ʧЧ
	cout << "=======================";
	Vector<int>::iterator it1 = vec1.end();
	vec1.pop_back();	//	���һ��������ʧЧ
	//++it1;

	//	ɾ���������������е�ż����ɾ��
	cout << "=======================" << endl;
	Vector<int>::iterator it2 = vec1.begin();
	while (it2 != vec1.end()) 
	{
		if (*it2 % 2 == 0) 
		{
			//	��һ�ε���eraseʱ��������it��ʧЧ��
			//	��Ҫ����it
			it2 = vec1.erase(it2);
		}
		else 
		{
			++it2;
		}
	}
	for (int x : vec1)
	{
		cout << x << " ";
	}
	cout << endl;

	//	���룬����������������ǰ�����һ��+1������
	cout << "=======================" << endl;
	auto it3 = vec1.begin();
	for (; it3 != vec1.end(); ++it3)
	{
		if (*it3 % 2 != 0)
		{
			//	�ڵ���insert֮�󣬵�������ʧЧ��
			//	��Ҫ���£�ͬʱȷ�������߼���ȷ
			it3 = vec1.insert(it3, *it3 + 1);
			++it3;
		}
	}
	for (int x : vec1)
	{
		cout << x << " ";
	}
	cout << endl;

	//	���룬string���Ͳ���
	cout << "=======================" << endl;
	Vector<string> vec2;
	for (int i = 0; i < 5; i++)
	{
		vec2.push_back("123456");
	}
	auto it4 = vec2.begin();
	for (; it4 != vec2.end(); ++it4)
	{
		if (it4 != vec2.end())
		{
			//	�ڵ���insert֮�󣬵�������ʧЧ��
			//	��Ҫ���£�ͬʱȷ�������߼���ȷ
			it4 = vec2.insert(it4, "456789");
			++it4;
		}
	}
	for (string x : vec2)
	{
		cout << x << endl;
	}
	return 0;
}
#endif