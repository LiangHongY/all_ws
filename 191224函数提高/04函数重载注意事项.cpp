#include<iostream>
using namespace std;

//函数重载的注意事项
//1、引用作为重载的条件

void func(int & a)//可读可写。int &a=10,这是不合法的，所以func（10），不走这个
{
	cout<<"func(int &a)调用"<<endl;
}

void func(const int & a)//只是可读。const int &a=10,这是合法的（前面教程里面有解析，大概意思系统自动
	                                      //分配一个内存空间保存10，就合法了），所以func（10），可以走这个。
{
	cout<<"func(const int &a)调用"<<endl;
}
//2、函数重载碰到默认参数
void func2(int a)
{
	cout<<"func2(int a)的调用"<<endl;
}

void func2(int a,int b=10)//碰到默认参数情况
{
	cout<<"func2(int a,int b=10)的调用"<<endl;
}

int main()
{
	int a=10;
	func(a);//调用无const
	func(10);//调用有const

	//func2(10);//当函数重载碰到默认参数，出现二义性，会报错，应该避免这种情况。
	//func2(10);//简单点理解，当函数重载时，尽量不写会产生歧义的默认参数,比如我把里面的第一个func
	                    //添加多一个的参数，但是不添加默认参数时候，这时候就不产生歧义了
	func2(10,2);


	system("pause");
	return 0;
}