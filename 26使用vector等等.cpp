#include <iostream>
#include <vector>
using namespace std;

#if 0
int main()
{
	vector<int> ve1;
	ve1.reserve(10);	//	ֻ�������ײ㿪��ָ����С���ڴ�ռ䣬����������µ�Ԫ��
	//ve1.resize(10);	//	�����������ײ㿪��ָ����С���ڴ�ռ䣬��������µ�Ԫ��

	for (int i = 0; i < 10; i++)
	{
		ve1.push_back(rand() % 100 + 1);
	}

	//	������ӡ
	for (int i = 0; i<ve1.size(); i++)
	{
		//	����������
		cout << ve1[i] << " ";
	}
	cout << endl;

	//	ɾ��˫��
	vector<int>::iterator t = ve1.begin();
	while (t != ve1.end())
	{
		if (*t % 2 == 0)
		{
			t = ve1.erase(t);
		}
		else
		{
			t++;
		}
	}

	//	������ӡ
	for (auto x : ve1)
	{
		//	����������
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
#endif
