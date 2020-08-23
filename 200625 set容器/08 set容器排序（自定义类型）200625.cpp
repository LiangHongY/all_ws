#include<iostream>
#include<set>
using namespace std;
#include<string>


//set容器排序，存放自定义类型数据

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
		//按照年龄降序
		
		return p1.m_Age > p2.m_Age;
	}
};//这里的仿函数又是报错的，和07节错误一样


void test01()
{
	//自定义数据类型都会指定排序规则
	set<Person, comparePerson>s1;

	Person p1("刘备", 24);
	Person p2("关羽", 28);
	Person p3("张飞", 25);
	Person p4("赵云", 20);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	for (set<Person, comparePerson>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << " 年龄：" << (*it).m_Name << endl;
	}
	cout << endl;
}


int main()
{
	test01();

	system("pause");
	return 0;
}
//总结：对于自定义数据类型，set必须给定排序规则才可以插入数据
//自定义排序规则报错，未解决200625