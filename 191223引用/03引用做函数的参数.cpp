#include<iostream>

using namespace std;
 
//1、交换函数
void mySwap01(int a,int b)
{
	int temp=a;
	a=b;
	b=temp;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}

//2.地址传递
void mySwap02(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	cout<<"a="<<*a<<endl;
	cout<<"b="<<*b<<endl;
}

//3、引用传递
void mySwap03(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}

int main()
{
	int a=10;
	int b=20;

	//mySwap01(a,b);//值传递，形参不会改变实参
	//mySwap02(&a,&b);//地址传递，形参会修饰实参的
	mySwap03(a,b);//引用传递，形参会修饰实参的
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;

	system("pause");
	return 0;
}
//总结
//引用做函数参数
//作用：函数传递时，可以利用引用的技术让形参修饰实参
//优点：可以简化指针修饰实参
//通过应用参数产生的效果和地址传递时一样的，引用的语法更清楚简单