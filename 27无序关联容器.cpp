#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//	set
void usingset()
{
	unordered_set<int> myset1;
	for (int i = 0; i < 100; i++)
	{
		//	���ؼ��� ��������ظ�Ԫ��
		myset1.insert(rand() % 20 + 1);
	}
	cout << myset1.size() << endl;		//	20
	cout << myset1.count(15) << endl;	//	1	

	cout << "-----------------------" << endl;
	unordered_multiset<int> myset2;
	for (int i = 0; i < 100; i++)
	{
		//	���ؼ��� �ܳ����ظ�Ԫ��
		myset2.insert(rand() % 20 + 1);
	}
	cout << myset2.size() << endl;		//	100
	cout << myset2.count(15) << endl;	//	4

	//	����
	cout << "-----------------------" << endl;
	for (int v : myset1)
	{
		cout << v << " ";
	}
	cout << endl;

	//	ɾ��
	cout << "-----------------------" << endl;
	auto it = myset1.begin();
	while (it !=  myset1.end())
	{
		if (*it % 2 == 0) 
		{
			it = myset1.erase(it);
		}
		else
		{
			++it;
		}
	}
}
//	map
void usingmap()
{
	unordered_map<int, string> mymap1;
	/* map��operator[]
	* 1����ѯ
	* 2�����key�����ڣ��������һ������[key,string()]
	* V& operator[](const K& key)
	* {
	*	   insert( { K,V() } );
	* }
	*/
	mymap1[1020] = "����";			//	�Ȳ���{1020,string()}���������ã����޸�
	mymap1[1030];					//	����һ��{1030,string()}
	mymap1[1020] = "�����޸�";		//	����ֵ�����ã��޸�
	cout << mymap1.size() << endl;	//	2
	cout << mymap1[1020] << endl;	//	�����޸�
}
//	�������ݲ��ظ�
void solution()
{
	const int ARR_LEN = 100;
	int arr[ARR_LEN] = { 0 };
	for (int i = 0; i < ARR_LEN; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	//	���� operator[]
	//	���û�д���Ĭ�ϵ�Ϊ0��Ȼ��++��Ϊ1��
	//	������ԭ�л�����++
	unordered_map<int, int> map1;
	for (int v : arr)
	{
		map1[v]++;	
	}
	//���ظ�
	for (const pair<int,int>& p : map1)
	{
		if (p.second > 1)
		{
			cout << "key:" << p.first << " value:" << p.second << endl;
		}
	}
}
#if 0
int main()
{
	//usingset();
	//usingmap();
	solution();
	return 0;
}
#endif