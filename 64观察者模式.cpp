#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;
#if 1
// Ҳ���Խй۲���-������ģ��
// �����߳�����
class Listener {
public:
	virtual void handle(int msgId) = 0;
};
class Listener01 : public Listener {
public:
	void handle(int msgId) {
		if (msgId == 1) cout << "Listener01 recv 1 msg!" << endl;
		else if (msgId == 2) cout << "Listener01 recv 2 msg!" << endl;
		else cout << "Listener01 recv unknow msg!" << endl;
	}
};
class Listener02 : public Listener {
public:
	void handle(int msgId) {
		if (msgId == 2) cout << "Listener02 recv 2 msg!" << endl;
		else if (msgId == 3) cout << "Listener02 recv 3 msg!" << endl;
		else cout << "Listener02 recv unknow msg!" << endl;
	}
};
// �۲�����
class Observer {
public:
	void registerListener(weak_ptr<Listener> lter, int msgId) {
		// map�������������û�ж�Ӧkey�ᴴ��һ���µ�pair���ҷ���second������
		lterMap[msgId].push_back(lter);
	}
	void dispatchMessage(int msgId) {
		// ����Ϣ����Ȥ��"������"������Ϣ
		auto it = lterMap.find(msgId);
		if (it != lterMap.end()) {
			for_each(it->second.begin(), it->second.end(),
				[&msgId,this](weak_ptr<Listener> pLter)->void {
					shared_ptr<Listener>p = pLter.lock();
					// �������ڶ��̻߳�������һ���������ˣ�����mapɾ��
					if (p == nullptr) lterMap.erase(msgId);	
					else p->handle(msgId);
				} 
			);
		}
	}
private:
	// ��ϢidҪ������Щ"������"
	unordered_map<int, list<weak_ptr<Listener>>> lterMap;
};

// ������
int main()
{
	cout << sizeof(int) << endl;
	shared_ptr<Listener>p1(new Listener01);
	shared_ptr<Listener>p2(new Listener02);
	Observer obser;
	obser.registerListener(p1, 0);	// ע������߲��������Ϣ
	obser.registerListener(p1, 1);
	obser.registerListener(p1, 2);
	obser.registerListener(p2, 2);
	obser.registerListener(p2, 3);
	// ע����0��1��2��3����Ϣ���������ܲ���
	int msgId;
	while (true) 
	{
		cout << "��������ϢID:";
		cin >> msgId;
		if (msgId == -1)break;
		obser.dispatchMessage(msgId);
	}

	return 0;
}
#endif