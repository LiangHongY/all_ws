#include"stdafx.h"
#include<iostream>
using namespace std;

int main(){

	//ָ����ռ���ڴ�ռ�
	int a=10;
	//int *p;
	//p=&a;
	int *p=&a;
	//��32λϵͳ�£�ָ�붼��ռ4���ֽڿռ��С������ʲô��������
	//��64λϵͳ�£�����ʲô���͵�ָ�룬����ռ��8���ֽ�
	cout << "sizeof (int *)="<<sizeof( int *)<<endl;
	cout << "sizeof (float *)="<<sizeof(float *)<<endl;
	cout << "sizeof (double *)="<<sizeof(double *)<<endl;
	cout << "sizeof (char *)="<<sizeof(char *)<<endl;

	system("pause");
	return 0;
}