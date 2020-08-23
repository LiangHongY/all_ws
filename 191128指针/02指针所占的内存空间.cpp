#include"stdafx.h"
#include<iostream>
using namespace std;

int main(){

	//指针所占的内存空间
	int a=10;
	//int *p;
	//p=&a;
	int *p=&a;
	//在32位系统下，指针都是占4个字节空间大小，不管什么数据类型
	//在64位系统下，不管什么类型的指针，都是占用8个字节
	cout << "sizeof (int *)="<<sizeof( int *)<<endl;
	cout << "sizeof (float *)="<<sizeof(float *)<<endl;
	cout << "sizeof (double *)="<<sizeof(double *)<<endl;
	cout << "sizeof (char *)="<<sizeof(char *)<<endl;

	system("pause");
	return 0;
}