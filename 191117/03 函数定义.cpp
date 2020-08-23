#include"stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int add(int num1,int num2)   //num1，num2称为形参
{
	int sum=num1+num2;
	return sum;
}

int main(){
	int a=10;
	int b=20;
	int c=add(a,b);//a,b称为实参，函数调用时候，实参会传递给形参
	cout<<"c= "<<c<<endl;
	system("pause");
	return 0;
}