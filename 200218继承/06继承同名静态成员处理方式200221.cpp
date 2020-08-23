#include<iostream>
using namespace std;

//继承中同名的静态成员在子类对象上如何进行访问？
//访问子类同名成员，直接访问即可
//访问父类同名成员，需要添加作用域

//继承中的同名静态成员处理方式

class Base
{
public:
	static int m_A;//类内定义命名，类外初始化

	static void func()
	{
		cout << "Base-func static成员函数调用" << endl;
	}
	static void func(int a)
	{
		cout << "Base-func(int a) static成员函数调用" << endl;
	}
};
int Base::m_A = 100;//初始化

class Son :public Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son-func static成员函数调用" << endl;
	}

};
int Son::m_A = 200;

//同名静态成员属性
void test01()
{
	//1、通过对象访问
	Son s;
	cout << "Son 下的m_A=" << s.m_A << endl;
	cout << "Base 下的m_A=" << s.Base::m_A << endl;
	//通过类名访问
	cout << "通过类名访问：" << endl;
	cout << "Son下m_A= " << Son::m_A << endl;

	//第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
	cout << "Base下m_A=" << Son::Base::m_A << endl;
}

//同名静态成员函数
void test02()
{
	//通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	s.func();
	s.Base::func();

	//通过类名方式访问
	cout << "通过类名访问：" << endl;
	Son::func();
	Son::Base::func();
	  
	//子类中出现和父类同名静态成员函数，也会隐藏父类中所有同名成员函数
	//如果想访问父类中被隐藏同名成员函数，需要添加作用域
	Son::Base::func(100);
	
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//同名静态成员处理方式和非静态处理方式一样，只不过有两种访问方式（通过对象和通过类名）