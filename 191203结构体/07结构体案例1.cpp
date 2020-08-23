#include"stdafx.h"
#include<iostream>
#include<string>
#include<ctime>

using namespace std;

//学生的结构体定义
struct Student
{
	string sName;
	int age;
	int score;
};

//老师的结构体定义
struct Teacher
{
	string tName;//老师姓名
	struct Student sArray[5];//老师带的学生数
};
//给老师和学生赋值的函数
void allocateSpace(struct Teacher tArray[],int len)
{
	string nameSeed ="ABCDE";
	//给老师开始赋值
	for(int i=0;i<len;i++)
	{
		tArray[i].tName="Teacher_";
		tArray[i].tName+=nameSeed[i];

		//通过循环给每个老师所带的学生赋值
		for(int j=0;j<5;j++)
		{
			tArray[i].sArray[j].sName="Student_";
			tArray[i].sArray[j].sName+=nameSeed[j];
			int random=rand()%61+40;//40~100分
			tArray[i].sArray[j].score=random;
		}
	}
}

//打印所有信息
void printInfo(struct Teacher tArray[ ],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<"老师姓名：  "<<tArray[i].tName <<endl;
		for(int j=0;j<5;j++)
		{
			cout<<"\t学生姓名： "<<tArray[i].sArray[j].sName<<"考试分数： "<<tArray[i].sArray[j].score<<endl;
		}
	}
}


int main()
{
	//随机数种子
	srand((unsigned int)time (NULL));

	//1、创建3名老师数组
	struct Teacher tArray[3];

	//2、通过函数给3名老师的信息赋值，并给老师带的学生信息赋值
	int len=sizeof(tArray)/ sizeof(tArray[0]);
	allocateSpace(tArray,len);
	//3、打印所有老师及所带学生信息
	printInfo(tArray,len);

	system("pause");
	return 0;
}