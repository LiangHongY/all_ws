//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}
//前言：C++面向对象有三大特性：封装、继承、多态
//C++认为万事万物皆为对象，对象有其属性和行为

//第一重点：封装
//封装的意义：
//将属性和行为作为一个整体，表现生活中的事物
//将属性和行为加以权限控制

//封装意义一：
//在设计类的时候，属性和行为写在一起，表现事物
//语法：  class  类名  {  访问权限：属性/行为}




#include<iostream>
using namespace std;

//圆周率
const double PI=3.14;

//设计一个圆类，求圆周长
//求圆公式：2*PI*半径

class Circle
{
	//访问权限
	//公共权限
public:

	//属性
	int m_r;
	//行为
	//获取圆的周长
	double calculateZC()
	{
		return 2*PI*m_r;
	}
};
//跟结构体有点像，不过结构体里面没有函数和权限定义

int main()
{
	//通过圆类，创建具体的圆（对象）
	//实例化，通过一个类创建一个具体对象的过程
	Circle c1;
	//给圆对象的属性进行赋值
	c1.m_r=10;

	//计算周长
	cout<<"圆c1的周长："<<c1.calculateZC()<<endl;
	system("pause");
	return 0;
}