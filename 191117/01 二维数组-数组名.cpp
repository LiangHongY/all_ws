#include"stdafx.h"
#include<iostream>
using namespace std;
int main(){
	int arr[2][3]=
	{
		{1,2,3},
		{4,5,6}
	};
	cout<<"��ά����ռ���ڴ�ռ�Ϊ�� "<<sizeof(arr)<<endl;
	cout<<"��ά�����һ��ռ���ڴ�ռ䣺 "<<sizeof(arr[0])<<endl;
	cout<<"��ά�����һ�е�һ��ռ���ڴ�ռ䣺 "<<sizeof(arr[0][0])<<endl;
	cout<<"��ά����������ǣ� "<<sizeof(arr)/sizeof(arr[0])<<endl;

	cout<<"��ά�����׵�ַΪ�� "<<(int )arr<<endl;
	cout<<"��ά����ĵ�һ�е��׵�ַΪ�� "<<(int)arr[0]<<endl;
	cout<<"��ά����ڶ��е��׵�ַΪ�� "<<(int)arr[1]<<endl;
	cout<<"��ά����ĵ�һ��Ԫ�ص��׵�ַ�� "<<(int)&arr[0][0]<<endl;
	cout<<"��ά����ĵڶ���Ԫ�صĵ�ַ�� "<<(int)&arr[0][1]<<endl;
	system("pause");
	return 0;
	}