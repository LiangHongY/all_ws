#include<iostream>
using namespace std;
#include<list>
#include<string>

//案例描述
//将person自定义数据类型进行排序，Person中属性有姓名，年龄，身高；
//排序规则:按照年龄进行升序，如果年龄相同就按照身高进行排序

class Person {
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age= age;
		this->m_Height = height;
	}

public:
	string m_Name;
	int m_Age;
	int m_Height;
};


void printList(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << " 身高：" << (*it).m_Height << endl;
	}
	cout << endl;
}

//排序规则，告诉L.sort()函数
bool comparePerson(Person &p1,Person &p2)
{


	////个人写法
	//if (p1.m_Age == p2.m_Age)
	//{
	//	if (p1.m_Height > p2.m_Height)
	//	{
	//		return false;
	//	}
	//}
	//else
	//{
	//	if (p1.m_Age > p2.m_Age)
	//	{
	//		return false;
	//	}
	//}

	//教程写法
	//按照年龄 升序
	if (p1.m_Age == p2.m_Age)
	{
		//年龄相同  按照身高降序
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}

}


void test01()
{
	list<Person>L;

	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 165);
	Person p6("关羽", 35, 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	printList(L);

	//for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	//{
	//	cout << "姓名：" << (*it).m_Name <<" 年龄："<<(*it).m_Age<<" 身高："<<(*it).m_Height<< endl;
	//} 

	//排序
	cout << "----------------------------------" << endl;
	cout << "排序后： " << endl;

	L.sort(comparePerson);//年龄升序方式
	printList(L);

}


int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：
//对于自定义数据类型，如Person，容器的排序函数需要给定排序规则
