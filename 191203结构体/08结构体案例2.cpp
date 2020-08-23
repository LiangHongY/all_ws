#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

struct Hero
{
	//定义姓名
	string name;
	//年龄
	int age;
	//性别
	string sex;
};

//冒泡排序，实现年龄的升序排序
void bubbleSort(struct Hero heroArray[],int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-1-i;j++)
		{
			//如果j 小标的元素大于j+1下标元素的年龄，交换两个元素
			if(heroArray[j].age>heroArray[j+1].age)
			{
				struct Hero temp=heroArray[j];
				heroArray[j]=heroArray[j+1];
				heroArray[j+1]=temp;
			}
		}
	}
}
//打印数组排序后的信息
void printhero(struct Hero heroArray[ ],int len)
{
	for(int i=0;i<len;i++)
	{
			cout<<"姓名：  "<<heroArray[i].name<<"   年龄：  "<<heroArray[i].age<<"   性别:   "<<heroArray[i].sex<<endl;
	}
}

int main()
{
	//1、设计英雄的结构体

	//2、创建数组存放5名英雄信息
	struct Hero heroArray[5]=
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",21,"男"},
		{"赵子龙",20,"男"},
		{"貂蝉",19,"女"},
	};

	int len=sizeof(heroArray)/sizeof(heroArray[0]);
	for(int i=0;i<len;i++)
	{
		cout<<"姓名：  "<<heroArray[i].name<<"   年龄：  "<<heroArray[i].age<<"   性别:   "<<heroArray[i].sex<<endl;

	}
	cout << endl;

	//3、对数组进行排序，按照年龄进行升序排序
	bubbleSort(heroArray,len);
	//4、将排序后结果打印输出
	printhero(heroArray,len);

	system("pause");
	return 0;
}