#include<iostream>
using namespace std;

//拷贝函数调用时机有三种情况

//1、使用一个已经创建完毕的对象来初始化一个新对象

//2、值传递的方式各函数参数传值

//3、值方式返回局部对象

class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}
	Person(int age)
	{
		cout << "Person有参构造函数调用" << endl;
		m_Age = age;
	}

	Person(const Person & p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int m_Age=0;
};

//1、使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);
	cout << "p2的年龄为多少   "<<p2.m_Age << endl;
}

//2、值传递的方式各函数参数传值
void doWork(Person p)
{

}
void test02()
{
	Person p;
	doWork(p);
}

//3、值方式返回局部对象
Person doWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;//输出的是指针内存地址200518
	return p1;
}
void test03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;//输出的指针内存地址2200518
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}

//完全不能理解这些是啥意思20200202