#include"stdafx.h"
#include<iostream>
using namespace std;
int main(){
	int arr[2][3]=
	{
		{1,2,3},
		{4,5,6}
	};
	cout<<"二维数组占用内存空间为： "<<sizeof(arr)<<endl;
	cout<<"二维数组第一行占用内存空间： "<<sizeof(arr[0])<<endl;
	cout<<"二维数组第一行第一列占用内存空间： "<<sizeof(arr[0][0])<<endl;
	cout<<"二维数组的行数是： "<<sizeof(arr)/sizeof(arr[0])<<endl;

	cout<<"二维数组首地址为： "<<(int )arr<<endl;
	cout<<"二维数组的第一行的首地址为： "<<(int)arr[0]<<endl;
	cout<<"二维数组第二行的首地址为： "<<(int)arr[1]<<endl;
	cout<<"二维数组的第一个元素的首地址： "<<(int)&arr[0][0]<<endl;
	cout<<"二维数组的第二个元素的地址： "<<(int)&arr[0][1]<<endl;
	system("pause");
	return 0;
	}