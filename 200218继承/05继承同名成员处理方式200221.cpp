#include<iostream>
using namespace std;

//当子类与父类出现同名的成员，如何通过子类对象，访问子类或父类中同名的数据？
//访问子类同名成员，直接访问即可
//访问父类同名成员，需要添加作用域

//继承中同名成员处理

class Base
{
public:
	Base()
	{
		m_A = 100;
	}

	void func()
	{
		cout << "Base-func（）调用" << endl;
	}

	void func(int a)
	{
		cout << "Base-func（int a）调用" << endl;
	}

	int m_A;
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	void func()
	{
		cout << "Son-func（）调用" << endl;
	}
	int m_A;
};


void test01()
{
	Son s;
	cout << "Son下 m_A=  " << s.m_A << endl;
	//如果通过子类对象，访问到父类中同名成员，需要添加作用域
	cout << "Base下 m_A=  " << s.Base::m_A << endl;
}

//同名函数处理
void test02()
{
	Son s;
	s.func();//直接调用的是子类同名成员
	//如何调用父类中同名成员函数？
	s.Base::func();

	//如果子类中出现和父类同名的成员函数，子类中同名成员会隐藏父类中所有同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	s.Base::func(100);
}

int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}