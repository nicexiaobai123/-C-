#include <iostream>
using namespace std;

//	����ģ������
template<typename T>
bool compare(T a, T b);
//	��ͨ��������
bool compare(int a, int b);

#if 0
int main()
{
	compare<char>('a', 'b');			//	template func
	compare<double>(20.5, 10.14);		//	template func
	compare("abx", "abx");				//	template<> func
	compare(100, 20);					//	normal func
	return 0;
}
#endif
