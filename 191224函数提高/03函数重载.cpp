#include<iostream>
using namespace std;

//函数重载
//可以让函数名相同，提高复用性

//函数重载的满足条件
//1、同一作用域下
//2、函数名称相同
//3、函数参数类型不同，或者个数不同，或者顺序不同

//以下都是同名，在全局作用域内
void func()
{
	cout<<"func 的调用"<<endl;
}

void func(int a)//类型不同（比前，以下均同）
{
	cout<<"func (int a)的调用"<<endl;
}

void func(double a)//类型不同
{
	cout<<"func (double a)的调用"<<endl;
}

void func(int a,double b)//个数不同
{
	cout<<"func (int a,double b)的调用"<<endl;
}

void func(double a,int b)//顺序不同
{
	cout<<"func (double a,int b)的调用"<<endl;
}

//注意事项
//函数的返回值不可以作为函数重载的条件
//int func(double a,int b)//返回值虽然属于int，与上面的void有区别，但是不能作为函数重载的条件
//{
//	cout<<"func (double a,int b)的调用"<<endl;
//}



int main()
{
	func();
	func(10);
	func(3.14);
	func(10,3.14);
	func(3.14,10);

	system("pause");
	return 0;
}