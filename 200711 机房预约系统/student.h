#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include<fstream>
#include"globalFile.h"
#include"computerRoom.h"
#include"orderFile.h"

//学生类  
class Student :public Identity           
{
public:
	//默认构造
	Student();

	//有参构造（学号、姓名、密码）
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void operMeun();//一开始写的是operMenu,未能够重载父类的所有虚构造，
	                         //导致一系列错误  --200714

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyorder();

	//查看所有预约
	void showAllorder();

	//取消预约
	void cancelOrder();

	int m_Id;//学号

	//机房容器  --200715
	vector<ComputerRoom> vCom;
};
