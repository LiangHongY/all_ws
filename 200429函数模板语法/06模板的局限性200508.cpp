#include<iostream>
using namespace std;
#include<string>

//ģ��ľ�����
//ģ�岢�������ܵģ���Щ�ض��������ͣ���Ҫ�þ��廯��ʽ������ʵ��

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//�Ա����������Ƿ����
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//���þ����Person�İ汾ʵ�ִ��룬���廯���ȵ���(�������溯�����أ�����Ҫ���廯��
template<> bool myCompare(Person& a, Person& b)//����һ������ض����͵�ģ�庯�������﷨��ʽ
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);

	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);//ֱ�����ã�ûд35���廯ʱ��ϵͳѡ�����22����ģ���
	                        //���ᱨ�﷨���󣬵��ǣ����г�����Ϊ�������������

	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
	
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
//�ܽ�
//���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
//ѧϰģ�岢����Ϊ��дģ�壬������stl�ܹ�����ϵͳ�ṩ��ģ��