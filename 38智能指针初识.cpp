#include <iostream>
using namespace std;
#if 0
template<typename T>
class CSmartPtr
{
public:
	// ʹ��explicit��������ָ��ʹ����ʽת������������ʹ�ã�CSmartPtr<int> p = new int
	explicit CSmartPtr(T* ptr = nullptr)
		:mptr(ptr) {}
	~CSmartPtr() { delete mptr; }
	T& operator * () { return *mptr; }
	const T& operator * () const { return *mptr; }
	T* operator -> () { return mptr; }
	const T* operator -> () const { return mptr; }
private:
	T* mptr;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//	��������
	CSmartPtr<int> p(new int);
	const CSmartPtr<int> p1(new int);
	*p = 10;
	*p1;

	//	�Զ�������
	struct Test {
		void test() { cout << "Test::test()" << endl; }
	};
	CSmartPtr<Test> p3(new Test);
	(*p3).test();

	//	ָ�����������ؽ������������ָ������������غ��������صĽ�����Զ��ټ���һ��->
	//	( p3.operator->() ) ->
	p3->test();

	return 0;
}
#endif