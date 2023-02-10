#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#if 0
int main()
{
	const int ARR_LEN = 10;
	int arr[ARR_LEN] = { 10,2,1,4,5,68,8,4,45,13 };
	//	vector���캯��һ�֣���ʼλ��-����λ��
	vector<int> vec1(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//	sortָ��һ���������󣬴Ӵ�С
	std::sort(vec1.begin(), vec1.end(), greater<int>());
	for (int v : vec1) cout << v << " ";
	cout << endl;

	//	sortĬ�ϴ�С��������
	std::sort(vec1.begin(), vec1.end());
	for (int v : vec1) cout << v << " ";
	cout << endl;

	//	���ֲ��� ����ָ�����ڴӴ�С�������в��ҵ�
	if (std::binary_search(vec1.begin(), vec1.end(), 45, greater<int>()))
	{
		cout << "����45�����" << endl;
	}

	//	find�����ص���һ��������
	//	auto it = find(vec1.begin(), vec1.end(), 68);
	vector<int>::iterator it1 = find(vec1.begin(), vec1.end(), 68);
	if (it1 != vec1.end()) cout << "����68�����" << endl;

	//	find_if ����������
	//	��11���뵽vector�����У��ҵ���һ����11Ҫ�����
	auto it2 = find_if(vec1.begin(), vec1.end(), bind2nd(greater<int>(), 11));
	vec1.insert(it2, 11);
	for (int v : vec1) cout << v << " ";
	cout << endl;

	//	lambda���ʽ
	//	for_each���Ա�����������Ԫ��
	for_each(vec1.begin(), vec1.end(),
		[](int& val)->void
		{
			if (val % 2 == 0) cout << val << " ";
		});
	return 0;
}
#endif