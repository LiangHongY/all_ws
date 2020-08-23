#include"stdafx.h"
#include<iostream>
using namespace std;

//函数的声明（可以存在多次）
//比较函数，实现两个整型数字进行比较，返回较大值
//提前告诉编译器函数的存在，可以利用函数声明；如果把定义函数写在main函数的后面，也不进行函数声明操作，会导致编译器报错，说找不到该函数
//（由于编译器是由上往下编译进行的）,所以要把借助函数声明，到时候把函数定义写哪里都可以，妈妈再也不担心孩子编译器报错啦
int max(int a,int b);

//同一个函数声明可以有多次，但是每个函数只用一个定义

//定义（只能有一个）
int max(int a,int b)
{
	return a>b?a:b;
}
int main(){
	int a=10;
	int b=20;
	cout<<max(a,b)<<endl;
	system("pause");
	return 0;
}