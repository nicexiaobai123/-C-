#include <iostream>
#include <vector>
using namespace std;


#if 0
int main()
{
	//volatile const int a = 20;	//	volatile����ʱ�Ͳ����ڱ���ʱ�ó�����ֵ�����滻
	const int a = 20;
	int b1 = 10;
	const int b2 = b1;	//	������

	int arr[a];			//	��Ϊ���������С����
	//int arr1[b2];

	int* p = (int*)&a;
	*p = 10;
	printf("%d  %d  %d\n", a, *p, *(&a));

	return 0;
}
#endif