#include"stdafx.h"
#include<iostream>
using namespace std;

int main(){
	
	//空指针:表示指向内存空间编号为0的指针，属于系统占用，不能够设置访问
	//1、空指针用于给指针变量进行初始化
	int  *p=NULL;
	//2、空指针是不可以进行访问的
	//0~255之间的内存编号是系统占用的，因此用户是不能访问
	//*p=100;这是错误使用的，语法没报错，但运行时，程序会奔溃
	system("pause");
	return 0;
}