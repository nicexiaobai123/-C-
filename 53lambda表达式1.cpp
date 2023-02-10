#include <iostream>
#include <functional>
#include <string>
#include <vector>
using namespace std;
#if 0

template<typename T = void>
class TestLambda01 {
public:
	void operator()()const { cout << "hello TestLambda01!" << endl; }
};

template<typename T = int>
class TestLambda02 {
public:
	T operator()(T a, T b)const { return a + b; }
};

template<typename T = int>
class TestLambda03 {
public:
	TestLambda03(int x, int y) :ma(x), mb(y) { }
	void operator()() const {
		int temp = ma;
		ma = mb;
		mb = temp;
	}
private:
	mutable int ma;
	mutable int mb;
};

template<typename T = int>
class TestLambda04 {
public:
	TestLambda04(int& x, int& y) :ma(x), mb(y) { }
	void operator()()const {
		int temp = ma;
		ma = mb;
		mb = temp;
	}
private:
	int& ma;
	int& mb;
};

int main()
{
	// lambda�ͺ�������ĶԱ�
	// lambda���ʽ
	function<void()> func1 = []() {cout << "hello lambda!" << endl; };
	func1();
	function<int(int, int)> func2 = [](int a, int b)->int {return a + b; };
	cout << func2(10, 10) << endl;
	
	// �����ⲿ����,ֵ����
	int a = 10;
	int b = 200;
	function<void()> func3 =
		[a, b]()mutable->void	// ��a�� : �޷��ڷǿɱ� lambda ���޸�ͨ�����Ʋ���
	{
		int temp = a;
		a = b;
		b = temp;
	};
	func3();
	cout << "a=" << a << " b=" << b << endl;

	// �����ⲿ����,���ô���
	function<void()> func4 =
		[&a, &b]()mutable->void
	{
		int temp = a;
		a = b;
		b = temp;
	};
	func4();
	cout << "a=" << a << " b=" << b << endl;

	// ÿ��lambda���ʽ��Ӧ�ĺ�������
	cout << "------------------------------" << endl;
	TestLambda01<>()();		// 1
	cout << TestLambda02<>()(10, 10) << endl; // 2
	int x = 10;
	int y = 200;
	TestLambda03<>(x, y)();	// 3
	cout << "x=" << x << " y=" << y << endl;
	TestLambda04<>(x, y)();	// 4
	cout << "x=" << x << " y=" << y << endl;

	return 0;
}
#endif