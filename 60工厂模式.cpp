#include <iostream>
#include <string>
#include <memory>
using namespace std;
#if 0

//------------------- �򵥹��� ------------------------
// ������Ŀ��ʱ���кܶ��࣬�������Լ�ס
// ���������Ҫ�޸�����������Ŀ��new�����ĵط���Ҫ�޸ģ������������Ƶ�˼��
// �򵥹��� --- ���������� ��װ����SimpleFactory���createProduct�������У�ͨ��ö�ٴ�������
//  ��Ʒ����һ
class Car
{
public:
	Car(const string& name) :_name(name) {}
	virtual void show() = 0;
protected:
	string _name;
};
class Bwm :public Car
{
public:
	Bwm(const string& name) :Car(name) {}
	void show() { cout << "��ȡ��һ����������:" << _name << endl; }
};
class Audi :public Car
{
public:
	Audi(const string& name) :Car(name) {}
	void show() { cout << "��ȡ��һ���µ�����:" << _name << endl; }
};
// �򵥹���
enum CarType { BWM, AUDI };
class SimpleFactory
{
public:
	Car* createProduct(CarType ct, const string& name)
	{
		switch (ct)
		{
		case BWM:
			return new Bwm(name);
		case AUDI:
			return new Audi(name);
		default:
			cerr << "�����������ȷ:" << ct << endl;
			break;
		}
		return nullptr;
	}
};
//------------------- �������� ------------------------
// ��������
class Factory
{
public:
	virtual Car* createProduct(const string& name) = 0;
};
// ������
class BwmFactory : public Factory
{
public:
	Car* createProduct(const string& name) { return new Bwm(name); }
};
// �µϹ���
class AudiFactory : public Factory
{
public:
	Car* createProduct(const string& name) { return new Audi(name); }
};
//------------------- ���󹤳� ------------------------
//  ��һ���й�����ϵ�Ĳ�Ʒ���ṩ��Ʒ�����ͳһ����
//  ��Ʒ���Ͷ�
class Light {
public:
	virtual void show() = 0;
};
class BwmLight :public Light {
public:
	void show() { cout << "BWM Light!" << endl; }
};
class AudiLight :public Light {
public:
	void show() { cout << "Audi Light!" << endl; }
};
// ����
class AbstractFactory {
public:
	virtual Car* createCar(const string& name) = 0;
	virtual Light* createCarLight() = 0;
};
class BwmFactory2 : public AbstractFactory
{
public:
	Car* createCar(const string& name) { return new Bwm(name); }
	Light* createCarLight() { return new BwmLight; }
};
class AudiFactory2 : public AbstractFactory
{
public:
	Car* createCar(const string& name) { return new Audi(name); }
	Light* createCarLight() { return new AudiLight; }
};

// ������
int main()
{
	// �򵥹�����ʾ
	unique_ptr<SimpleFactory> factory(new SimpleFactory);
	unique_ptr<Car> p1(factory->createProduct(BWM, "X1"));
	unique_ptr<Car> p2(factory->createProduct(AUDI, "A6"));
	p1->show();
	p2->show();

	// ����������ʾ
	cout << "----------------------------" << endl;
	unique_ptr<Factory> bwnFty(new BwmFactory);
	unique_ptr<Factory> audiFty(new AudiFactory);
	unique_ptr<Car> p3(bwnFty->createProduct("X2"));
	unique_ptr<Car> p4(audiFty->createProduct("A8"));
	p3->show();
	p4->show();

	// ���󹤳���ʾ
	cout << "----------------------------" << endl;
	unique_ptr<AbstractFactory> bwnFty2(new BwmFactory2);
	unique_ptr<AbstractFactory> audiFty2(new AudiFactory2);
	unique_ptr<Car> p5(bwnFty2->createCar("X3"));
	unique_ptr<Car> p6(audiFty2->createCar("A9"));
	unique_ptr<Light> p7(bwnFty2->createCarLight());
	unique_ptr<Light> p8(audiFty2->createCarLight());
	p5->show();
	p6->show();
	p7->show();
	p8->show();

	return 0;
}
#endif