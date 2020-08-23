#include"stdafx.h"
#include<iostream>
using namespace std;
//空指针和野指针都不是我们申请的空间，因此不要访问
int main()
{

	//野指针：指向非法内存空间的指针
	int *p=(int *)0x1100;//指针变量指向内存空间编号为0x1100
	//cout<<*p<<endl;访问野指针报错

	system("pause");
	return 0;
}