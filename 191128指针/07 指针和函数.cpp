#include"stdafx.h"
#include<iostream>
using namespace std;

//实现两个数字进行交换
void swap01(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void swap02(int * p1,int * p2)
{
	int temp=* p1;
	* p1=* p2;
	* p2=temp; 
}
int main()
{
	//指针和函数

	//1、值传递
	int a=10;
	int b=20;
	swap01(a,b);//值传递不会改变实参
	cout<<"swap 01 a= "<<a<<endl;
	cout<<"swap 01 b="<<b<<endl;

	//2、地址传递
	//如果是地址传递，可以修饰实参

	swap02(&a,&b);//地址传递会改变实参
	cout <<"swap02 a= "<<a<<endl;
	cout<<"swap02 b= " <<b<<endl;

	//总结：如果不想修改实参，就用值传递；如果想要改变实参，就用地址传递
	system("pause");
	return 0;
}