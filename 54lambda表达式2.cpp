#include <iostream>
#include <functional>
#include <memory>
#include <map>
#include <set>
#include <queue>
using namespace std;
#if 0
class Data
{
public:
	Data(int a = 10, int b = 10) :ma(a), mb(b) {  }
	// bool operator<(const Data& a) { return this->ma < a.ma; }
	int ma;
	int mb;
};
int main()
{
	// �����ַ���ʹ������������������
	// 1��������Щoperator<���غ���  2���Լ��ṩ�����ıȽϺ������󣬲�ʹ��Ĭ�ϵ�less
	using FUNC = function<bool(const Data&, const Data&)>;
	set<Data, FUNC> mySet( 
		[](const Data& a, const Data& b)->bool
		{
			return a.ma < b.ma;
		}
	);
	mySet.insert(Data(10, 20));
	mySet.insert(Data(11, 20));

	// ʹ�����ȼ�����
	priority_queue<Data, vector<Data>, FUNC> maxQue(
		[](const Data& a, const Data& b)->bool
		{
			return a.ma > b.ma;
		}
	);
	maxQue.push(Data(10, 10));
	maxQue.push(Data(20, 10));

	// map����洢��������
	map<int, function<int(int, int)>> calcFunc;
	calcFunc[1] = [](int a, int b)->int { return a + b; };
	calcFunc[2] = [](int a, int b)->int { return a - b; };
	calcFunc[3] = [](int a, int b)->int { return a * b; };

	// ����ָ���Զ���ɾ����
	unique_ptr<FILE, function<void(FILE*)>> ptr(fopen("test.txt", "w"),
		[](FILE* fp)
		{
			fclose(fp);
		});
	return 0;
}
#endif