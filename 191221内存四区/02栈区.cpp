#include<iostream>

using namespace std;

//栈区是由编译器自动分配、释放，存放函数的参数值、局部变量等。
//注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
//对栈区进行内存操作，比如返回等，属于非法操作的，虽然不会报错，但是一般会得不到正确结果的

//栈区是程序运行后产生的
//栈区数据注意事项----不要返回局部变量的地址
//栈区的数据是由编译器管理开辟和释放

int* func(int b)//形参数据也会放在栈区
{
	b=100;
	int a=10;//局部变量     存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;//返回局部变量的地址
}

int main()
{
	//接受func函数的返回值
	int *p=func(1);

	cout<<*p<<endl;//第一次可以打印正确的数据，是因为编译器做了保留
	cout<<*p<<endl;//第二次这个数据不再做保留

	system("pause");
	return 0;
}