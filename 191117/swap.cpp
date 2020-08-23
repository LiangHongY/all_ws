#include"stdafx.h"
#include"swap.h"//""表示的是该函数属于自己定义的

//函数的定义
void swap(int a,int b)
{
	int temp=a;
	a=b;
	b=temp;

	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}