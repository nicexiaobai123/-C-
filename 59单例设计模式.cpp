#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
#if 0

// ����ģʽ:һ���಻�ܴ������ٴζ�����Զֻ�ܵõ�������һ�������ʵ��
// ��������ģʽ����������ʱ��ʵ�����˸ö��󣬲�û���Ƴٵ���һ��ʹ�øö���ʱ�ٽ���ʵ����
// ��������ģʽ�������ʵ�������ӳٵ���һ��ʹ������ʱ��

// ------------------  ��������ģʽ ��������ʱ���̰߳�ȫ�� ---------------------------
// ����ģʽ����3��
class Singleton01
{
public:
	// #3 ��ȡΨһʵ������Ľӿ�
	static Singleton01* getInstance() {
		return &single;
	}
private:
	// #1 ���캯��˽�л�
	Singleton01() {
		// �ܶ��ʼ������...
		cout << "Singleton01 ��ʼ�����캯��..." << endl;
	}
	~Singleton01() { cout << "~Singleton01 " << endl; }
	// #2 ����Ψһ��ʵ������
	static Singleton01 single;
	// ɾ����������͸��ƣ���ֹ�����µĶ���
	Singleton01(const Singleton01&) = delete;
	Singleton01& operator=(const Singleton01&) = delete;
};
Singleton01 Singleton01::single;

// ------------------ ��������ģʽ  ���̰߳�ȫ�ģ���Ҫ���� ---------------------------
std::mutex mtx;
class Singleton02
{
public:
	static Singleton02* getInstance() {
		// ��ʵ���������ʱ���������ֹ���߳�ʱ�������Ψһ����
		if (single == nullptr)
		{
			// ˫��У����
			lock_guard<std::mutex> guard(mtx);
			if (single == nullptr) {
				single = new Singleton02;
			}
		}
		return single;
	}
private:
	// ��ʵ���Ƕ���һ����̬����ֻ���������ֻ���ͷ���Դ
	// ����һ��Ƕ���࣬�ڸ�������������У��Զ��ͷ���������Դ
	class Release {
	public:
		~Release() { delete single; }
	};
	Singleton02() { cout << "Singleton02 ��ʼ�����캯��..." << endl; }
	~Singleton02() { cout << "~Singleton02 " << endl; }

	// ͨ���þ�̬�����ڳ������ʱ�Զ��������ص㣬���ͷ������Ķ�����Դ
	static Release release;
	static Singleton02* single;
	Singleton02(const Singleton02&) = delete;
	Singleton02& operator=(const Singleton02&) = delete;
};
Singleton02* Singleton02::single = nullptr;
Singleton02::Release Singleton02::release;

// --------------------- ��������ģʽ ����Ҫ�����̰߳�ȫ -------------------------------
class Singleton03
{
public:
	static Singleton03* getInstance() {
		// ������̬�ֲ������ĳ�ʼ�����ڻ��ָ�����Ѿ��Զ�����̻߳���ָ����
		static Singleton03 single;
		return &single;
	}
private:
	Singleton03() { cout << "Singleton03 ��ʼ�����캯��..." << endl; }
	~Singleton03() { cout << "~Singleton03 " << endl; }

	Singleton03(const Singleton03&) = delete;
	Singleton03& operator=(const Singleton03&) = delete;
};

int main()
{
	Singleton01* sig1 = Singleton01::getInstance();
	Singleton01* sig2 = Singleton01::getInstance();
	cout << sig1 << " -- " << sig2 << endl;

	cout << "--------------------------" << endl;
	Singleton02* sig3 = Singleton02::getInstance();
	Singleton02* sig4 = Singleton02::getInstance();
	cout << sig3 << " -- " << sig4 << endl;

	cout << "--------------------------" << endl;
	Singleton03* sig5 = Singleton03::getInstance();
	Singleton03* sig6 = Singleton03::getInstance();
	cout << sig5 << " -- " << sig6 << endl;
	return 0;
}
#endif