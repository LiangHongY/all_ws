#include"stdafx.h"
#include<iostream>
using namespace std;

//ʵ���������ֽ��н���
void swap01(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void swap02(int * p1,int * p2)
{
	int temp=* p1;
	* p1=* p2;
	* p2=temp; 
}
int main()
{
	//ָ��ͺ���

	//1��ֵ����
	int a=10;
	int b=20;
	swap01(a,b);//ֵ���ݲ���ı�ʵ��
	cout<<"swap 01 a= "<<a<<endl;
	cout<<"swap 01 b="<<b<<endl;

	//2����ַ����
	//����ǵ�ַ���ݣ���������ʵ��

	swap02(&a,&b);//��ַ���ݻ�ı�ʵ��
	cout <<"swap02 a= "<<a<<endl;
	cout<<"swap02 b= " <<b<<endl;

	//�ܽ᣺��������޸�ʵ�Σ�����ֵ���ݣ������Ҫ�ı�ʵ�Σ����õ�ַ����
	system("pause");
	return 0;
}