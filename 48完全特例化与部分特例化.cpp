#include <iostream>
#include <vector>
using namespace std;
#if 0
// ��ģ��
template<typename T>
class Vector
{
public:
	Vector() { cout << "call Vector template init" << endl; }
};
// ��ȫ�������汾
template<>
class Vector<char*>
{
public:
	Vector() { cout << "call Vector template Vector<char*>" << endl; }
};
// ����ָ��Ĳ���������
template<typename Ty>
class Vector<Ty*>
{
public:
	Vector() { cout << "call Vector template Vector<Ty*>" << endl; }
};
// ���ں���ָ���������
template<typename R,typename A1,typename A2>
class Vector<R(*)(A1, A2)>
{
public:
	Vector() { cout << "call Vector template Vector<R(*)(A1, A2)>" << endl; }
};
// ���ں������͵�������
template <typename R, typename A1, typename A2>
class Vector<R(A1, A2)>
{
public:
	Vector() { cout << "call Vector template Vector<R(A1, A2)>" << endl; }
};
// ������
int sum(int a, int b) { return a + b; }
int main()
{
	Vector<int> ve1;
	Vector<int*> ve2;
	Vector<char*> ve3;
	Vector<int(*)(int, int)> ve4;	// ����ָ������
	Vector<int(int, int)> ve5;		// ��������

	// ����ָ������ �� �������͵�����
	using PFUNC1 = int(*)(int, int);
	PFUNC1 func1 = sum;
	cout << "sum = " << func1(10, 20) << endl;

	using PFUNC2 = int(int, int);
	PFUNC2* func2 = sum;			// �������Ǻ���ָ������
	cout << "sum = " << func2(20, 20) << endl;
	// Ҳ����(*func2)(20, 20)

	return 0;
}
#endif