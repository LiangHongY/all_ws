#include"stdafx.h"
#include<iostream>
using namespace std;

int main()
{

	//指针和数组
	//利用指针范围数组中的元素

	int arr[10]={1,2,3,4,5,6,7,8,9,10};

	cout<<"第一个元素为："<<arr[0]<<endl;

	int * p=arr;//arr 就是数组的首地址

	cout<<"利用指针访问第一个元素："<<* p<<endl;

	p++;//让指针往后偏移4个字节，因为，这是整型指针，占用四个字节的；

	cout<<"利用指针访问第二个元素："<<* p<<endl;

	//cout<<"利用指针遍历数组："<<* p<<endl;//搞不懂这句话意义何在，故改为下一行200513
	cout << "利用指针遍历数组：" << endl;

	int * p2=arr;

	for(int i=0;i<10;i++)
	{
		cout<<*p2<<endl;
		p2++;
	}
	
	system("pause");
	return 0;
}