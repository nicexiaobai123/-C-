#include <iostream>
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
	void construct(T* p,const T& val) {
		new (p) T(val);
	}
	//	ֻ����~T()����T���͵���������
	void destroy(T* p) {
		p->~T();		
	}
};

template<typename T,typename Alloc = Allocator<T>>
class Vector {
public:
	//	����
	Vector(int size = 10) {
		//_first = new T[size];				//	��ֱ��new�����ˣ�����ֻ���ٿռ�
		_first = allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	//	����
	~Vector() {
		//delete[] _first;
		for (T* f = _first; f != _last; f++) {
			allocator.destroy(f);
		}
		allocator.deallocate(_first);		//	����������ЧԪ�أ�Ȼ���ͷ�_firstָ��Ŀռ�
		_first = _last = _end = nullptr;
	}
	//	��������
	Vector(const Vector<T>& rhs) {
		int size = rhs._end - rhs._first;
		int len = rhs._last - rhs._first;
		/*_first = new T[size];
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs[i];
		}*/
		_first = allocator.allocate(size);	//	������ռ�͹������ֿ�����
		for (int i=0; i< len; i++)
		{
			allocator.construct(&_first[i], rhs[i]);
		}
		_last = _first + len;
		_end = _first + size;
		
	}
	//	������ֵ
	Vector<T>& operator=(const Vector<T>& rhs) {
		if (this == &rhs) {
			return *this;
		}

		// delete[] _first;
		for (T* f = _first; f != _last; f++) {
			allocator.destroy(f);
		}
		allocator.deallocate(_first);

		int size = rhs._end - rhs._first;
		int len = rhs._last - rhs._first;
		/*_first = new T[size];
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs[i];
		}*/
		_first = allocator.allocate(size);
		for (int i = 0; i < len; i++)
		{
			allocator.construct(&_first[i], rhs[i]);
		}
		_last = _first + len;
		_last = _first + size;
	}
	//	�����
	void push_back(const T& val) {
		if (isFull()) {
			expand();
		}
		//*_last++ = val;
		allocator.construct(_last, val);	//	_lastָ����ڴ湹��һ��ֵΪval�Ķ���
		++_last;
	}
	//	����
	void pop_back() {
		if (isEmpty())
			return;
		//_last--;
		allocator.destroy(--_last);			//	����Ҫ--_last����������ɾ����Ԫ��
	}
	//	�����
	T& back() const {
		if (isEmpty()) {
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
	void expand() {
		int size = _end - _first;
		//T* ptem = new T[size * 2];
		T* ptem = allocator.allocate(size * 2);
		for (int i = 0; i < size; i++) {
			allocator.construct(&ptem[i], _first[i]);
		}

		//delete[] _first;
		for (T* f = _first; f != _last; f++) {
			allocator.destroy(f);
		}
		allocator.deallocate(_first);

		_first = ptem;
		_last = _first + size;
		_end = _first + 2 * size;
	}
private:
	T* _first;	//	��������ʼԪ��λ��
	T* _last;	//	��������ЧԪ�صĺ��
	T* _end;	//	����ռ�ĺ��
	Alloc allocator;
};


//	��
class Test {
public:
	Test() {
		cout << "Test" << endl;
	}
	~Test() {
		cout << "~Test" << endl;
	}
	Test(const Test& ) {
		cout << "Test(const Test& t)" << endl;
	}
};


#if 0
int main()
{
	Test t1,t2,t3;
	cout << "=====================" << endl;

	Vector<Test> vec1;	//	ֻ�����ڴ棬�����ù��캯��
	vec1.push_back(t1);	//	��pushʱ�ŵ��ù��캯��
	vec1.push_back(t2);
	vec1.push_back(t3);

	cout << "=====================" << endl;
	vec1.pop_back();
	vec1.pop_back();	//	��popʱ������������
	vec1.pop_back();
	cout << "=====================" << endl;
						//	������ʱ������ʣ���Ŷ����ͷ�Vector��ʵ�ռ�


	//	C++�﷨��������
	//using t = int;
	//t* p = new int;
	//p->~t();

	//	ֱ�����﷨����
	//int* p = new int;
	//p->~int();	error

	return 0; 
}
#endif