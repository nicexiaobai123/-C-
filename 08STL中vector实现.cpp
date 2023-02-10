#include <iostream>
using namespace std;

template<typename T>
class Vector {
public:
	//	����
	Vector(int size = 10) {
		_first = new T[size];
		_last = _first;
		_end = _first + size;
	}
	//	����
	~Vector() {
		delete[] _first;
		_first = _last = _end = nullptr;
	}
	//	��������
	Vector(const Vector<T>& rhs) {
		int size = rhs._end - rhs._first;
		int len = rhs._last - rhs._first;
		_first = new T[size];
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs[i];
		}
		_last = _first + len;
		_last = _first + size;
	}
	//	������ֵ
	Vector<T>& operator=(const Vector<T>& rhs) {
		if (this == &rhs) {
			return *this;
		}

		delete[] _first;

		int size = rhs._end - rhs._first;
		int len = rhs._last - rhs._first;
		_first = new T[size];
		for (int i = 0; i < len; i++)
		{
			_first[i] = rhs[i];
		}
		_last = _first + len;
		_last = _first + size;
	}
	//	�����
	void push_back(const T& val) {
		if (isFull()) {
			expand();
		}
		*_last++ = val;
	}
	//	����
	void pop_back() {
		if (isEmpty())
			return;
		_last--;
	}
	//	�����
	T& back() const{
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
		T* ptem = new T[size * 2];
		for (int i = 0; i < size; i++) {
			ptem[i] = _first[i];
		}
		delete[] _first;
		_first = ptem;
		_last = _first + size;
		_end = _first + 2 * size;
	}
private:
	T* _first;	//	��������ʼԪ��λ��
	T* _last;	//	��������ЧԪ�صĺ��
	T* _end;	//	����ռ�ĺ��
};

#if 0
int main()
{
	Vector<int> vec1;
	for (size_t i = 0; i < 15; i++)
	{
		vec1.push_back(rand() % 100);
	}

	vec1.pop_back();
	while (!vec1.isEmpty())
	{
		cout << vec1.back() << " ";
		vec1.pop_back();
	}
	cout << endl;

	//	���쳣д����û..
	try
	{
		vec1.back(); 
	}
	catch (...)
	{
		cout << "�쳣" << endl;
	}
	system("pause");
	return 0;
}
#endif