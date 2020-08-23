#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

//1、创建学生数据类型  ：  学生包括（姓名，年龄，分数）
//自定义数据类型，一些类型集合组成的一个类型
//语法       struct   类型名称  {成员列表}
struct Student
{
	//成员列表

	//姓名
	string name;

	//年龄
	int age;

	//分数
	int score;

}s3;//2.3种方式，在定义结构体类型时，直接定义

//2、通过学生类型创建具体学生

//2.1 struct  Student   s1
//2.2 struct Student   s2={....}
//2.3在定义结构体时顺便创建结构体变量

int main()
{
	//2.1 struct  Student   s1
	//下列35，46的struct关键字可以省略，仅限c++中；但是，定义时是不能省略的，如上面的定义结构体类型时
	struct Student s1;
	//给s1属性赋值，通过  .   访问结构体变量中的属性
	s1.name="张三";
	s1.age=18;
	s1.score=100;

	cout<<"姓名：  "<<s1.name<<"年龄：  "<<s1.age<<"分数：  "<<s1.score<<endl;



  //2.2 struct Student   s2={....}
	struct Student s2={"李四",19,80};
		cout<<"姓名：  "<<s2.name<<"年龄：  "<<s2.age<<"分数：  "<<s2.score<<endl;

   //2.3在定义结构体时顺便创建结构体变量，然后在下面具体赋值
		s3.name="王五";
		s3.age=20;
		s3.score=60;
		cout<<"姓名：  "<<s3.name<<"年龄：  "<<s3.age<<"分数：  "<<s3.score<<endl;

	system("pause");
	return 0;
}

//总结1：定义结构体时的关键字是struct，不可省略
//总结2：创建结构体变量时，关键字struct可省略
//总结3：结构体变量利用操作符   " . " 访问成员