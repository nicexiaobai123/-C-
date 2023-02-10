#include <iostream>
using namespace std;

class CComplex {
public:
	CComplex(int r = 0, int i = 0)
		:mreal(r), mimage(i) {}

	//	ָ����������ô��CComplex�ļӷ�����
	CComplex operator+(const CComplex& src) {
		return CComplex(mreal + src.mreal, mimage + src.mimage);
	}

	//	ǰ�� �������ã�����Ϊ��ֵ
	CComplex& operator++() {
		++mreal;
		++mimage;
		return *this;
	}

	//	���� ������ʱ������������Ϊ��ֵ
	CComplex operator++(int) {
		return CComplex(mreal++, mimage++);
	}
	void show() {
		cout << "mreal: " << mreal << " mimage:" << mimage << endl;
	}

private:
	int mreal;
	int mimage;
	friend CComplex operator+(const CComplex& rhs, const CComplex& lhs);
	friend ostream& operator << (ostream& out, const CComplex& src);
	friend istream& operator >> (istream& in, CComplex& src);
};

//	ȫ�����������
CComplex operator + (const CComplex& rhs, const CComplex& lhs) {
	return CComplex(rhs.mreal + lhs.mreal, rhs.mimage + lhs.mimage);
}
ostream& operator << (ostream& out, const CComplex& src) {
	return out << "mreal:" << src.mreal << " mimage:" << src.mimage;
}
istream& operator >> (istream& in, CComplex& src) {
	return in >> src.mimage >> src.mreal;
}

#if 0
int main()
{
	CComplex com1(20, 20), com2(10, 10);
	CComplex com3 = com1 + com2;

	//	��ʽ����ת������Ϊ�����ǵ��� com1.operator+(const CComplex& src)
	//	��ʱ�������ͻῴ20�Ƿ����ת����CComplex���Ϳ�CComplex���캯�������乹�캯���Ͳ�����ʱ����
	CComplex com4 = com1 + 20;		
	com3.show();
	com4.show();

	//	��Ա����û�����������������ȫ���������Һ��ʵ���������غ���
	CComplex com5 = 15 + com1;
	com5.show();

	//	ǰ��++�ͺ���++
	cout << " ================================== " << endl;
	com5 = com1++;
	com1.show();
	com5.show();
	com5 = ++com1;
	com1.show();
	com5.show();

	//	����������������
	cout << " ================================== " << endl;
	CComplex com6;
	cin >> com6;
	cout << com6 << endl;

	return 0;
}
#endif