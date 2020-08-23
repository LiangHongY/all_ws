#pragma once  //防止头文件重复包含
#include<iostream>
#include<string>
using namespace std;

//身份抽象 基 类 --200712
class Identity
{
public:
	//操作菜单  纯虚函数
	virtual void operMeun() = 0;

	string m_Name;//用户名
	string m_Pwd;//密码
};