#include"stdafx.h"
#include<iostream>
using namespace std;
//�޲��޷�
void test01()
{
	cout<<"this is test01 "<<endl;
}
//�в��޷�
void test02(int a)
{
	cout<<"this is test02 a="<<a<<endl;
}
//�޲��з�
int test03()
{
	cout<<"this is test03"<<endl;
	return 1000;
}
//�в��з�
int test04(int a){
	cout<<"this is test04 a="<<a<<endl;
	return a;
}
int main()
{
	test01();
	test02(100);
	int num1=test03();
	cout<<"num1= "<<num1<<endl ;
	int num2=test04(10000);
	cout<<"num2="<<num2<<endl;
	system("pause");
	return 0;
}