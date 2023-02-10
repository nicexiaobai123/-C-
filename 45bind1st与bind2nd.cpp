#include <iostream>
#include <ctime>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
#if 0
//	==== bind1st��bind2nd��C++17���ɾ���� ====

template<typename Container>
void ShowCont(Container cnt)
{
 	 typename Container::iterator it = cnt.begin();
	 for (; it != cnt.end(); ++it)
	 {
		 cout << *it << " ";
	 }
	 cout << endl;
}
int main()
{
	vector<int> vec1;
	srand(time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		vec1.push_back(rand() % 100 + 1);
	}
	ShowCont(vec1);

	// Ĭ�ϴ�С����
	std::sort(vec1.begin(), vec1.end());
	ShowCont(vec1);

	// �ṩ�������󣬴Ӵ�С
	std::sort(vec1.begin(), vec1.end(),greater<int>());
	ShowCont(vec1);

	// ���� + ��Ԫ��������(��Ϊstlֻ�ṩ�˶�Ԫ��������) = һԪ��������
	// ��70���뵽�����У��ҵ���һ��С��70������
	// less  a < b
	// greater a > b
	// �������ǰ󶨶�Ԫ���������һ���β�
	auto it1 = find_if(vec1.begin(), vec1.end(),
		//bind2nd(less<int>(), 70)
		bind1st(greater<int>(),70)
	);
	if (it1 != vec1.end()) {
		vec1.insert(it1, 70);
	}
	ShowCont(vec1);

	return 0;
}
#endif
