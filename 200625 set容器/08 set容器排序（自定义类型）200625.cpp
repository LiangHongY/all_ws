#include<iostream>
#include<set>
using namespace std;
#include<string>


//set�������򣬴���Զ�����������

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	string m_Age;
};

class comparePerson
{
public:
	bool operator()(const Person& p1,const Person& p2)
	{
		//�������併��
		
		return p1.m_Age > p2.m_Age;
	}
};//����ķº������Ǳ���ģ���07�ڴ���һ��


void test01()
{
	//�Զ����������Ͷ���ָ���������
	set<Person, comparePerson>s1;

	Person p1("����", 24);
	Person p2("����", 28);
	Person p3("�ŷ�", 25);
	Person p4("����", 20);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<Person, comparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "������ " << (*it).m_Name << " ���䣺" << (*it).m_Name << endl;
	}
	cout << endl;
}


int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺�����Զ����������ͣ�set��������������ſ��Բ�������
//�Զ���������򱨴�δ���200625