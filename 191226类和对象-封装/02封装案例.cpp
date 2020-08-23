#include<iostream>
#include<string>
using namespace std;
//设计一个学生类，属性有姓名和学号
//可以给姓名和学号赋值，可以显示学生的姓名和学号

//设计学生类
class Student
{
public://公共权限
	//一些专业术语：
	//类中的属性和行为  统一称为   成员
	//属性    成员属性   成员变量   （三者 一样意思）
	//行为    成员函数   成员方法    （同上）

	//属性
	string m_Name;
	int m_Id;
	//行为
	//显示姓名和学号
	void showPrint()
	{
		cout<<"学生的姓名："<<m_Name<<"   学生的ID："<<m_Id<<endl;
	}

	//给姓名赋值（采用行为给属性赋值）
	void setName(string name)
	{
		m_Name=name;
	}
	//给id赋值
	void setId(int id)
	{
		m_Id=id;
	}
};

int main()
{
	//创建一个具体的学生（实例化对象）
	Student s1;
	//s1.m_Name="张三";
	s1.setName("张三");
	//s1.m_Id=01;
	s1.setId(2);
	//显示学生的信息
	s1.showPrint();//这里不需要再写cout来表示输出，而是直接调用就OK了

	system("pause");
	return 0;
}