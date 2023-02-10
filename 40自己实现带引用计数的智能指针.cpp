#include <iostream>
#include <memory>
using namespace std;
#if 0
//	�Լ�ʵ�ֵ�ǿ����ָ�룬��ÿ��������Դƥ��һ�����ü���
//	�Լ�ʵ�ֵ����ü���++��--���������̰߳�ȫ�ģ����߳��²���ʹ��
//	���е�shared_ptr��weak_ptr���ü������ӡ��������̰߳�ȫ��

//	������
template<typename T>
class CRefCount
{
public:
	CRefCount(T* ptr = nullptr)
		:mptr(ptr), mcount(1)
	{	}
	void addRef() { mcount++; }			//	������Դ���ü���
	int delRef() { return --mcount; }	//	������Դ���ü���
private:
	T* mptr;		//	ָ���ⲿ��Դ��ָ��
	int mcount;		//	���ü���
};

//	ǿ����ָ��
template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T* ptr = nullptr)
		:mptr(ptr) {
		mRefCnt = new CRefCount<T>(ptr);
	}
	~CSmartPtr() 
	{ 
		if (mRefCnt->delRef() == 0)
		{
			delete mptr;
			delete mRefCnt;
		}
	}
	T& operator * () { return *mptr; }
	T* operator -> () { return mptr; }

	//	��������
	CSmartPtr(const CSmartPtr<T>& src)
		:mptr(src.mptr), mRefCnt(src.mRefCnt)
	{
		if (mptr != nullptr)
			mRefCnt->addRef();
	}
	//	������ֵ
	CSmartPtr<T>& operator = (const CSmartPtr<T>& src)
	{
		if (this == &src)
			return *this;
		if (mRefCnt->delRef() == 0)
		{
			delete mptr;
			delete mRefCnt;
		}
		mptr = src.mptr;
		mRefCnt = src.mRefCnt;
		if (mptr != nullptr)
			mRefCnt->addRef();
		return *this;
	}
private:
	T* mptr;
	CRefCount<T>* mRefCnt;
};

//	������
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CSmartPtr<int> p1(new int);
	*p1 = 40;

	CSmartPtr<int> p2(p1);
	CSmartPtr<int> p3;
	p3 = p2;

	cout << *p3 << endl;
	return 0;
}
#endif