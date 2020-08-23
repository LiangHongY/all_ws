#include<iostream>
using namespace std;
//占位参数
//语法：   返回值类型   函数名  （数据类型）{}

//目前阶段的占位参数，我们是使用不到的，后面课程中会用到
//占位参数，还可以有默认参数
void func(int a,int)//第二个int 就是占位参数
{
	cout<<"this is func"<<endl;
}

int main()
{
	func(10,10);//占位参数没有默认值时候，一定需要填写相应的类型数值给它，才能正常调用带有占位参数的函数

	system("pause");
	return 0;
}