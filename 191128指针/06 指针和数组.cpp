#include"stdafx.h"
#include<iostream>
using namespace std;

int main()
{

	//ָ�������
	//����ָ�뷶Χ�����е�Ԫ��

	int arr[10]={1,2,3,4,5,6,7,8,9,10};

	cout<<"��һ��Ԫ��Ϊ��"<<arr[0]<<endl;

	int * p=arr;//arr ����������׵�ַ

	cout<<"����ָ����ʵ�һ��Ԫ�أ�"<<* p<<endl;

	p++;//��ָ������ƫ��4���ֽڣ���Ϊ����������ָ�룬ռ���ĸ��ֽڵģ�

	cout<<"����ָ����ʵڶ���Ԫ�أ�"<<* p<<endl;

	//cout<<"����ָ��������飺"<<* p<<endl;//�㲻����仰������ڣ��ʸ�Ϊ��һ��200513
	cout << "����ָ��������飺" << endl;

	int * p2=arr;

	for(int i=0;i<10;i++)
	{
		cout<<*p2<<endl;
		p2++;
	}
	
	system("pause");
	return 0;
}