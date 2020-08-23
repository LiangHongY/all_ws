#include<iostream>

using namespace std;

//常量引用主要用于修饰形参，防止误操作
//在函数形参列表中，可以使用const修饰形参，防止形参改变实参（类似前面指针形参加const的样子防止误操作）

//常量引用
//使用场景：用来修饰形参，防止误操作

//打印数值
void showValue(const int& val)//加const的目的，防止误操作修改实参
{
	//val=1000;//报错
	cout<<"val="<<val<<endl;
}


int main()
{
   // int a=10;
	//加上const之后，编码器将代码修改，int temp =10； const int& ref =temp；（针对下行而言）
	//const int& ref=10;//引用必须是一块合法的内存空间；如果不加const的话，这个内存空间不合法，10只是常量，不知道保存它的内存在哪里
	//ref=20;//加上const之后，变得只读不能修改了，这跟const * const p情况类似

	int a=100;
	showValue(a);
	cout<<"a="<<a<<endl;//如果showValue函数形参处不加const的话，里面做的修改会改变这里的实参a的值

	system("pause");
	return 0;
}