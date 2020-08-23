#include"stdafx.h"
#include <iostream>

using namespace std;

//冒泡排序函数    参数1   数组的首地址    参数2   数组长度
void bubbleSort(int * arr,int len)//用*加数组名可以表示数组的首地址
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-i-1;j++)
		{
			//如何j>j+1的值，交换数值
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
//打印数组
void printArray(int * arr,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<endl;
	}

}


int main()
{
	//1、先创建数组
	int arr[10]={1,2,3,4,5,6,7,8,9,10};

	//数组长度
	int len = sizeof(arr)/sizeof(arr[0]);

	//2、创建函数，实现冒泡排序
	bubbleSort(arr,len);

	//3、打印排序后的数组

	printArray( arr,len);

	system("pause");
	return 0;
}