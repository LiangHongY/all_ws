#include"stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int add(int num1,int num2)   //num1��num2��Ϊ�β�
{
	int sum=num1+num2;
	return sum;
}

int main(){
	int a=10;
	int b=20;
	int c=add(a,b);//a,b��Ϊʵ�Σ���������ʱ��ʵ�λᴫ�ݸ��β�
	cout<<"c= "<<c<<endl;
	system("pause");
	return 0;
}