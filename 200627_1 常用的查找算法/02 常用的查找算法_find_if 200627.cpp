#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//find_if  功能描述：
//按条件查找元素

//函数原型：
//find_if(iterator beg,iterator end,_Pred);
//按值朝朝元素，找到返回指定位置迭代器，找不到返回结束迭代器

//beg 开始迭代器
//end 结束迭代器
//_Pred 函数或者谓词（返回bool类型的仿函数)

//1、查找内置型 数据类型
class greaterFive
{
public:
	bool operator ()(int val)
	{
		return val > 5;
	}
};


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos= find_if(v.begin(), v.end(), greaterFive());
	if (pos != v.end())
	{
		cout << "找到该数据：" << *pos << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}
}

//2、查找自定义 数据类型
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

class greater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 20;
	}
};

void test02()
{
	vector<Person>v;

	//创建数据
	Person p1("a", 10);
	Person p2("b", 60);
	Person p3("c", 30);
	Person p4("g", 4);
	Person p5("e", 12);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//找年龄大于20的人
	vector<Person>::iterator pos= find_if(v.begin(), v.end(), greater20());
	
	if (pos != v.end())
	{
		cout << "找到该成员：" << pos->m_Name << " 年龄：" << pos->m_Age << endl;
	}
	else
	{
		cout << "未找到该成员" << endl;
	}
	//如果是想输出容器内所有满足条件的数据，该怎么做？
	//是要找到一个删一个，另存到一个新容器里面？
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}