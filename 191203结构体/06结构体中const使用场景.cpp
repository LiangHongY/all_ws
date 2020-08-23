#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

//const的使用场景

struct student
{
	string name;
	int age;
	int score;
};
//将函数中的形参改为指针，可以减少占用的内存空间，而且不会复制一个新的副本出来（值传递会复制新的副本会导致大大占用内存）
void printStudents(const student *s)//如果没加const，使用地址传递时，里面进行写操作时，会导致实参变化，const就是为了防止误操作而使用的
{
	//s->age=150;//加入const之后，一旦有修改的操作就会报错，可以防止我们误操作
	cout<<"学生的姓名：   "<<s->name<<"   学生的年龄：   "<<s->age<<"   学生的成绩：   "<<s->score<<endl;
}

int main()
{
  
	//创建结构体变量
	struct student s={"张三",15,70};

	//通过函数打印结构体变量信息
	printStudents(&s);

	cout<<"main函数中的年龄：   "<<s.age<<endl;

	system("pause");
	return 0;
}