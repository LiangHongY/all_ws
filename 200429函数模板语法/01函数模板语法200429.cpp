#include<iostream>
using namespace std;

//C++另一种编程思想称为泛式编程，主要利用的技术就是模板
//C++提供两种模板机制：函数模板和类模板

//函数模板的作用：建立一个通用函数，其函数返回值类型和形参类型可以不具体定制，
//用一个虚拟的类型来代表

//函数模板

//两个整型交换函数

void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板(语法)
template<typename T>//声明一个模板，告诉编译器后面代码紧跟着的T不要报错，T是一个通用数据类型
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;

	//swapInt(a, b);
	//利用函数模板交换
	//两种方式使用函数模板

	////1、自动类型推导
	//mySwap(a, b);

	//2、显示指定类型
	mySwap<int>(a, b);//在<>中指定T代表的类型

	cout << "a= " << a << endl;
	cout << "b= " << b<<endl;

	double c = 1.1;
	double d = 2.2;
	//swapDouble(c, d);
	mySwap<double>(c, d);
	cout << "c= " << c << endl;
	cout << "d= " << d << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//总结：
//函数模板的使用有两种方式：自动类型推导、显示指定类型
//模板的目的是为了提高复用性，将类型参数化

//模板的特点：
//模板不可以直接使用，它只是一个框架
//模板的通用并不是万能的