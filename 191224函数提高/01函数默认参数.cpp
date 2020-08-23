//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

//函数默认参数

//如果我们传入数据，使用自己数据，如果没有，那么使用默认值
//语法：  返回值类型   函数名   （形参=默认值）{ }
int func(int a,int b=20,int c=30)//b,c是默认值
{
	return a+b+c;
}

//注意事项
//1、如果某个位置有了默认参数，那么从这个位置往后，从左到右都必须有默认值
//int func2(int a,int b=20,int c)//后面的c没有默认参数就是报错
//{
//	return a+b+c;
//}

//2、如果函数声明有默认参数，函数实现就不能有默认参数
//声明和实现只能有一个默认参数
int func2(int a=10,int b=10);

//int func2(int a=10,int b=10)//重定义了，虽然没显示红线，但是运行时会报重定义错误
	int func2(int a,int b)
{
	return a+b;
}


int main()
{
	//cout<<func(10,30)<<endl;//在形参处没有默认值情况下，实参的数量=形参数量；有默认情况下，实参>=形参数量。
	cout<<func2()<<endl;
	system("pause");
	return 0;
}