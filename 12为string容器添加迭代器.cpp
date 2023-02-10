#include <iostream>
using namespace std;

class String {
public:
	//	���캯��
	String(const char* p = nullptr)
	{
		if (p != nullptr)
		{
			int len = strlen(p) + 1;
			_pstr = new char[len] {0};
			strcpy(_pstr, p);
		}
		else
		{
			_pstr = new char[1];
			_pstr[0] = '\0';
		}
	}
	//	��������
	~String()
	{
		delete[] _pstr;
		_pstr = nullptr;
	}
	//	��������
	String(const String& rhs)
	{
		_pstr = new char[rhs.length() + 1]{ 0 };
		strcpy(_pstr, rhs.c_str());
	}
	//	������ֵ
	String& operator = (const String& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		delete[] _pstr;
		_pstr = new char[rhs.length() + 1]{ 0 };
		strcpy(_pstr, rhs.c_str());
		return *this;
	}
	//	[]���������
	char& operator[](int i)
	{
		if (i<0 || i>strlen(_pstr)) {
			throw "OutOfRangeException";
		}
		return _pstr[i];
	}
	//	���������ṩһ��,��ֹ�޸ĵ�
	const char& operator[](int i) const
	{
		if (i<0 || i>strlen(_pstr)) {
			throw "OutOfRangeException";
		}
		return _pstr[i];
	}
	//	С�����������
	bool operator < (const String& rhs) const
	{
		return strcmp(_pstr, rhs.c_str()) < 0;
	}
	const char* c_str() const
	{
		return _pstr;
	}
	size_t length() const
	{
		return strlen(_pstr);
	}
	//	���ڵ�����
public:
	class iterator {
	public:
		//����
		iterator(char* ptr = nullptr) :p(ptr) {}
		//����++
		iterator operator ++ (int) {
			return iterator(p++);
		}
		//ǰ��++
		iterator& operator ++ () {
			++p;
			return *this;
		}
		//*���������
		char& operator * () {
			return *p;
		}
		//const��*���������
		const char& operator * () const{
			return *p;
		}
		//!=���������
		bool operator != (const iterator& it) const {
			return p != it.p;
		}
	private:
		char* p;
	};
	//	���ṩbegin���������ص�������ָ��������ʼ
	iterator begin() const {
		return iterator(_pstr);
	}
	//	���ṩend���������ص�������ָ���������ĺ��
	iterator end() const {
		return iterator(_pstr + strlen(_pstr));
	}
private:
	char* _pstr;
	friend String operator + (const String& str1, const String& str2);
	friend ostream& operator << (ostream& out, const String& src);
};

//	ȫ������
String operator + (const String& str1, const String& str2)
{
	//char* ptem = new char[str1.length() + str2.length() + 1]{ 0 };
	String ptem;
	delete[] ptem.c_str();
	ptem._pstr = new char[str1.length() + str2.length() + 1];
	strcpy(ptem._pstr, str1.c_str());
	strcat(ptem._pstr, str2.c_str());
	//String str = String(ptem);
	//delete[] ptem;
	return ptem;
}
ostream& operator << (ostream& out, const String& src)
{
	return out << src.c_str();
}

#if 0
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	String str1 = "Hello World";
	String::iterator it;
	for (it = str1.begin(); it != str1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//	C++11��foreach�ײ���ͨ��������ʵ��
	//	�˻��ڷ�Χ�ġ�for�������Ҫ�ʺϵ� "begin" ����
	cout << "=======================" << endl;
	for (char c : str1) {
		cout << c << " ";
	}
	cout << endl;

	return 0;
}
#endif