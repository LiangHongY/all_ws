#include"stdafx.h"
#include<iostream>
using namespace std;
//指针就是一个地址

int main()
{

	//1、定义一个指针
	int a=10;
	//指针定义的语法：   数据类型  *  指针变量名；
	int *p;
	//让指针记录变量a的地址
	p=&a;
	cout<<"a的地址 为："<<&a<<endl;
	cout<<"p为："<<p<<endl;

	//2、使用指针
	//可以通过引用的方式来找到指针指向的内存
	//指针前加 * 代表  解引用,找到指针指向内存中的数据，可以对数据修改以及读取；
	*p=1000;//表示拿到a的那块内存，并对它进行赋值修改
	cout<<"a="<<a<<endl;
	cout<<"*p="<<*p<<endl;

	system("pause");
	return 0;
}