#include<iostream>
using namespace std;

//由于这节是在缺少上一节静态成员变量讲解的情况下的，所以这里备注一下
//什么叫静态成员变量
//特征有：
//所有对象共享一份数据
//在编译阶段分配内存
//类内声明，类外初始化

//静态成员函数：
//所有对象共享一个函数
//静态成员函数只能访问静态成员变量

class Person
{
public:
	//静态成员函数
	static void func()
	{
		m_A = 100;//静态成员函数可以访问静态成员变量

		//m_B = 10;//这里报错原因是，m_B是非静态成员变量所以静态成员函数是不能访问的
		//非静态成员变量，不是共享的，如果创建不同的具体类对象时候
		//,无法区分到底是哪个对象的m_B属性

		cout << "static void func 调用" << endl;
	}
	//静态成员变量
	static int m_A;//静态成员函数类内声明

	int m_B;//非静态成员变量，静态成员函数是不能访问的

	//私有的静态成员函数
private:
	static void func2()
	{
		cout << "static void func2调用" << endl;
	}

};
int Person::m_A = 0;//静态成员函数类外初始化

void test01()
{
	//1.通过对象访问
	Person p;
	p.func();

	//2.通过类名访问
	Person::func();

	//Person::func2();//类外访问不了私有的静态成员函数
}

int main()
{
	test01();

	system("pause");
	return 0;
}