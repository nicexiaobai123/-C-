#include <iostream>
#include <memory>
#include <functional>
using namespace std;
#if 0
class MyDeleter
{
public:
	void operator()(void* p)
	{
		cout << "����ɾ��:" << p << endl;
		delete[] p;
	}
};
// ������
int main()
{
	// �º�������ʽ
	unique_ptr<int, MyDeleter> p1(new int[5]);

	// shared_ptr�����ṩ���ͣ�ֻ���ṩɾ����
	shared_ptr<int> p2(new int[5], MyDeleter());
	*p2 = 10;
	shared_ptr<int> p3(p2);
	cout << *p3 << endl;

	cout << "----------------------------" << endl;

	// �Ƽ�ʹ��function + lambda���ʽ
	unique_ptr<FILE, function<void(FILE*)>> p4(fopen("data.txt", "w"),
		[](FILE* fp)->void{
			cout << "�ر��ļ�:" << fp << endl;
			fclose(fp);
		});

	// shared_ptr�����ṩ���ͣ�ֻ���ṩɾ����
	shared_ptr<FILE> p5(fopen("data.txt", "w"), 
		[](FILE* fp)->void {
			cout << "�ر��ļ�:" << fp << endl;
			fclose(fp);
		});
	return 0;
}
#endif