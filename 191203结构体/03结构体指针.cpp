#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

//结构体指针
//作用：通过指针访问结构体成员
//利用操作符    ->   可以通过结构体指针访问结构体属性

//定义学生结构体
struct student
{
	string name;
	int age;
	int score;
};

int main()
{
	//1.创建学生结构体变量
	struct student s={"张三",18,100};

	//2.通过指针指向结构体变量
	struct student * p = &s;//struct可以省略，但是指针前面的student不写  结构体名会报错的

	//3.通过指针访问结构体变量中的数据
	//通过结构体指针，访问结构体中的属性，需要利用 "  ->  "
	cout<<"姓名：  "<<p->name<<"  年龄：  "<<p->age<<"  分数：  "<<p->score<<endl;

	//总结：结构体指针可以通过  -> 操作符来访问结构体中的成员
	system("pause");
	return 0;
}