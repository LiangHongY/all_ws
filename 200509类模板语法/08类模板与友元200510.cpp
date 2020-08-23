#include<iostream>
using namespace std;
#include<string>

//学习目标：掌握类模板配合友元函数的类内和类外实现

//全局函数类内实现，直接在类内声明友元即可
//全局函数类外实现，需要提前让编译器知道全局函数的存在


//通过全局函数 打印Person信息


//提前让编译器知道Person这个类的存在
template<class T1,class T2>
class Person;


//类外实现
template<class T1, class T2>
void printPerson2(Person<T1, T2>p)//这里不需要加作用域范围，因为这是全局函数
{
	cout << "类外---姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1,class T2>
class Person
{
	//全局函数，类内实现
	friend void printPerson(Person<T1, T2>p)
	{
		cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
	}

	//全局函数 类外实现
	//添加一个空模板参数列表就可以解决无法解析外部命令的问题
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	friend void printPerson2<>(Person<T1, T2>p);

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};



//1、全局函数类内实现
void test01()
{
	Person<string, int>p("Tom", 20);
	printPerson(p);
}
//2、全局函数的类外实现
void test02()
{
	Person<string, int>p("god", 18);
	printPerson2(p);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

//类外实现时候比较麻烦，首先声明一下类，然后写类外实现，后面才到类定义
//总结：建议使用全局函数的类内实现方式，因为其用法简单，而且编译器可以直接识别