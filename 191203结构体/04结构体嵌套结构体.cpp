#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;
//结构体嵌套结构体
//作用：结构体中的成员可以另一个结构体
//定义学生结构体,先定义学生才能定义老师的数据结构体，否则，编译时候会报错
struct student
{
	string name;
	int age;
	int score;
};
//定义老师结构体
struct teacher
{
	int id;
	string name;
	int age;
	struct student stu;//辅导的学生
};
int main()
{
	//结构体嵌套结构体
	//创建老师
	teacher t;
	t.id=1000;
	t.name="老王";
	t.age=50;
	t.stu.name="小王";
	t.stu.age=20;
	t.stu.score=60;

	cout<<"老师的姓名   "<<t.name<<"  老师的编号：   "<<t.id<<"   老师的年龄：  "<<t.age
		<<"  老师带的学生姓名： "<<t.stu.name<<"  老师带的学生年龄：  "<<t.stu.age
		<<"  老师带的学生分数：  "<<t.stu.score<<endl;

	system("pause");
	return 0;
}