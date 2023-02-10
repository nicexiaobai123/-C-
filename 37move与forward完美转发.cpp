#include <iostream>
using namespace std;

#if 0
// �����ռ�������
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
	//	ģ����ĳ�Աģ��
	template<typename Ty>
	void construct(T* p, Ty&& val) {
		new (p) T(forward<Ty>(val));
	}
	////	ֻ���죬ʹ�ö�λnew�����õĿ������죻
	//void construct(T* p, const T& val) {
	//	new (p) T(val);
	//}
	//
	////	move�ƶ�����
	//void construct(T* p, T&& val) {
	//	new (p) T(std::move(val));
	//}
	//	ֻ����~T()����T���͵���������
	void destroy(T* p) {
		p->~T();
	}
};

// Vectorʵ��
template<typename T, typename Alloc = Allocator<T>>
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
		_first = allocator.allocate(size);	//	������ռ�͹������ֿ�����
		for (int i = 0; i < len; i++)
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
		for (T* f = _first; f != _last; f++) {
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
	//	�����	����
	template<typename Ty>
	void push_back(Ty&& val);

	//	����
	void pop_back() {
		if (isEmpty())
			return;
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
		T* ptem = allocator.allocate(size * 2);
		for (int i = 0; i < size; i++) {
			allocator.construct(&ptem[i], _first[i]);
		}

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

// MyStringʵ��
class MyString
{
public:
	MyString(const char* p = nullptr)
	{
		cout << "MyString(char*)" << endl;
		if (p != nullptr)
		{
			_ptr = new char[strlen(p) + 1]{ 0 };
			strcpy(_ptr, p);
		}
		else
		{
			_ptr = new char[1];
			*_ptr = '\0';
		}
	}
	~MyString()
	{
		cout << "~MyString()" << endl;
		delete[] _ptr;
		_ptr = nullptr;
	}
	MyString(const MyString& str)
	{
		cout << "MyString(MyString&)" << endl;
		_ptr = new char[strlen(str._ptr) + 1]{ 0 };
		strcpy(_ptr, str._ptr);
	}
	MyString(MyString&& str)
	{
		cout << "MyString(MyString&&)" << endl;
		_ptr = str._ptr;
		str._ptr = nullptr;
	}
	MyString& operator= (const MyString& str)
	{
		cout << "MyString(operator=&)" << endl;
		if (this == &str) return *this;
		delete[] _ptr;
		_ptr = new char[strlen(str._ptr) + 1]{ 0 };
		strcpy(_ptr, str._ptr);
		return *this;
	}
	MyString& operator= (MyString&& str)
	{
		cout << "MyString(operator=&&)" << endl;
		if (this == &str) return *this;
		delete[] _ptr;
		_ptr = str._ptr;
		str._ptr = nullptr;
		return *this;
	}
	char* c_str()const { return _ptr; }
private:
	char* _ptr;
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
};

// void Vector<T, Alloc>::push_back(T&& val)
// void Vector<T, Alloc>::push_back(const T& val)
// ---> template<typename Ty> 
//  ʹ����ģ��ĳ�Աģ��ʱ�����������ɸ����ṩ�Ĳ�������ģ��ʵ���ƶϣ�������ģ��һ��
// 
//	�����۵� &&+&&=&&; &&+&=&
//	��Աģ���������� + �����۵�
template<typename T, typename Alloc>
template<typename Ty>
void Vector<T, Alloc>::push_back(Ty&& val)
{
	if (isFull()) {
		expand();
	}
	//	forward����ݲ����Ķ��� ʶ������ֵ������ֵ
	allocator.construct(_last, std::forward<Ty>(val));
	++_last;
}
//	=======================
int main()
{
	MyString str1("11111");
	Vector<MyString> vec1;
	vec1.push_back(str1);				//	push��ֵ
	vec1.push_back(MyString("22222"));	//	push��ֵ
	return 0;
}
#endif