#include <iostream>
#include <vector>
using namespace std;

#if 0
int main()
{
	vector<int> vec1;
	for (int i = 0; i < 10; i++) {
		vec1.push_back(rand() % 50 + 1);
	}
	for (int x : vec1) {
		cout << x << " ";
	}
	cout << endl;

	//	ɾ���������������е�ż����ɾ��
	cout << "=======================" << endl;
	vector<int>::iterator it1 = vec1.begin();
	while (it1 != vec1.end()) {
		if (*it1 % 2 == 0) {
			//	��һ�ε���eraseʱ��������it��ʧЧ��
			//	��Ҫ����it
			it1 = vec1.erase(it1);
		}
		else {
			it1++;
		}
	}
	for (int x : vec1) {
		cout << x << " ";
	}
	cout << endl;

	//	���룬����������������ǰ�����һ��+1������
	cout << "=======================" << endl;
	auto it2 = vec1.begin();
	for (; it2 != vec1.end(); ++it2) {
		if (*it2 % 2 != 0) {
			//	�ڵ���insert֮�󣬵�������ʧЧ��
			//	��Ҫ���£�ͬʱȷ�������߼���ȷ
			it2 = vec1.insert(it2, *it2 + 1);
			it2++;
		}
	}
	for (int x : vec1) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
#endif