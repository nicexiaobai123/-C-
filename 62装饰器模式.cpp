#include <iostream>
#include <string>
#include <memory>
using namespace std;
#if 0
// װ����ģʽ��Decorator
/* 
	ͨ������ʵ�ֹ������ӵ����⣺Ϊ����ǿ������Ĺ��ܣ�ͨ��ʵ������ķ�ʽ��д�ӿڣ�
	�ǿ�����ɹ��ܵ���չ�ģ����Ǵ�������̫���������ӽ�����
*/
// ������
class Car {
public:
	virtual void showInfo() = 0;
};
// ʵ����
class Bwm :public Car {
public:
	void showInfo() { cout << "����һ������������������: ��������"; }
};
class Audi :public Car {
public:
	void showInfo() { cout << "����һ���µ�������������: ��������"; }
};
class Bnze :public Car {
public:
	void showInfo() { cout << "����һ������������������: ��������"; }
};
// װ�����������¹���
// ���û����Ҫ�����Ĺ������������Բ���дһ����������ټ̳�
class ConcreateDecorator01 : public Car {
public:
	ConcreateDecorator01(Car* p) :pCar(p) { }
	// װ�Σ�����¹��� ����Ѳ��
	void showInfo() {
		pCar->showInfo();
		cout << "������Ѳ������";
	}
private:
	Car* pCar;
};
class ConcreateDecorator02 : public Car {
public:
	ConcreateDecorator02(Car* p) :pCar(p) { }
	// װ�Σ�����¹��� �Զ�ɲ��
	void showInfo() {
		pCar->showInfo();
		cout << "���Զ�ɲ������";
	}
private:
	Car* pCar;
};
// ������
int main()
{
	// ͨ��װ����װ��
	unique_ptr<Car> p1(new Audi);
	unique_ptr<Car> p2(new ConcreateDecorator01(p1.get()));	// һ��װ��
	unique_ptr<Car> p3(new ConcreateDecorator02(p2.get())); // ����װ��

	p2->showInfo();
	cout << endl;

	p3->showInfo();
	cout << endl;
	return 0;
}
#endif