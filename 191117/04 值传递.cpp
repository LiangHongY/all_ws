#include"stdafx.h"
#include<iostream>
#include<string>
using namespace std;
//ֵ����
//���庯����ʵ���������ֽ��н�������
//�����������Ҫ����ֵ��������ʱ�����дviod

void swap(int num1,int num2)//���ڿ����ͣ��޷���ֵ���ͣ�����дreturn
{
	cout<<"����ǰ�� "<<endl;
	cout<<"num1="<<num1<<endl;
	cout<<"num2="<<num2<<endl;

	int temp=num1;
	num1=num2;
	num2=temp;

	cout<<"������ "<<endl;
	cout<<"num1= "<<num1<<endl;
	cout<<"num2= "<<num2<<endl;
}
int main(){
	int a=10;
	int b=20;
	//��������ֵ���ݵ�ʱ�򣬺������βη����ı䣬������Ӱ��ʵ��
	swap(a,b);
	//system("pause");
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	system("pause");
	return 0;//�βθı䣬�ǲ���ı�ʵ�ε�
}