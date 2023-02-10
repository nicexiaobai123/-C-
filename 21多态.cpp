#include <iostream>
#include <vector>
using namespace std;

#if 0

//	����
class Animal {
public:
	Animal(const string& str):name(str) {}
	virtual void bark() {}
protected:
	string name;
};
//	��
class Dog :public Animal {
public:
	Dog(const string& str) :Animal(str) { }
	virtual void bark() {
		cout << name << ": wangwang" << endl;
	}
};
//	��
class Pig :public Animal {
public:
	Pig(const string& str) :Animal(str) { }
	virtual void bark() {
		cout << name << ": hengheng" << endl;
	}
};
//	è
class Cat :public Animal {
public:
	Cat(const string& str) :Animal(str) { }
	virtual void bark() {
		cout << name << ": miaomiao" << endl;
	}
};
//	�ṩbark�ӿ�
//	������ԭ��"����ԭ��" --> ���޸Ĺرգ�����չ����
//	����������Ȼ����ֱ��ʹ�����bark�ӿڣ������޸�
//	ɾ��һ�����bark����ɾ�����޸ģ���Ȼ������
void bark(Animal& p) {
	p.bark();
}
int main()
{
	Pig pig("����");
	Cat cat("С��");
	Dog dbg("����");
	bark(pig);
	bark(cat);
	bark(dbg);
	return 0;
}
#endif