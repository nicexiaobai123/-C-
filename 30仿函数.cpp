#include <iostream>
#include <vector>
using namespace std;

#if 0

//	=============== ����ָ��ʹ�� ================ 
template<typename T>
bool Less(T a, T b) { return a < b; }
template<typename T>
bool Greater(T a, T b) { return a > b; }

//	=============== �º���ʹ�� ================ 
template<typename T>
struct myless {
	bool operator()(T a, T b) { return a < b; }
	// int _count  // �����Ҫ�����Լ�¼�������Ϣ
};
template<typename T>
struct mygreater {
	bool operator()(T a, T b) { return a > b; }
};

//	=============== �⺯��ʹ�� ================ 
template<typename T, typename Compare>
bool compare(T a, T b,Compare comp)
{
	return comp(a, b);
}
// ������
int main()
{
	cout << compare(10, 20, Less<int>) << endl;			//ָ��С�ں�����1
	cout << compare(10, 20, Greater<int>) << endl;		//ָ�����ں�����0
	cout << compare(10, 20, myless<int>()) << endl;		//ָ��С�ں�����1
	cout << compare(10, 20, mygreater<int>()) << endl;	//ָ��С�ں�����0
	return 0;
}
#endif