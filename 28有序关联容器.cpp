#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
#if 0
class Student
{
public:
	// Ҫ��map(unorderedͬ�����)�ܹ��洢�����ṩĬ�Ϲ��캯��
	Student(int id = 0, const string& name = "")
		:_id(id), _name(name)
	{	}
	// �ṩ operator < �������������ڲ�֪���������
	bool operator < (const Student& stu) const 
	{
		return _id < stu._id;
	}
private:
	int _id;
	string _name;
	friend ostream& operator << (ostream& out, const Student& stu);
};
ostream& operator << (ostream& out, const Student& stu)
{
	return out << stu._id << ":" << stu._name;
}

int main()
{
	//	ʹ��set�洢����
	set<Student> set1;
	set1.insert(Student(1020, "����"));
	set1.insert(Student(1010, "����"));
	set1.insert(Student(1040, "����"));
	for (auto v : set1)
	{
		cout << v << endl;
	}

	//	ʹ��map�洢����
	map<int, Student> map1;
	map1.insert({1020,Student(1020,"1111") });
	map1[1030] = Student(1030, "2222");
	return 0;
}
#endif