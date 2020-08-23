#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"identity.h"
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<functional>
#include<numeric>
#include<algorithm>
#include"computerRoom.h"


//管理员设计  --200712
class Manager :public Identity
{
public:

	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//选择菜单界面
	virtual void operMeun();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器   --200714
	void initVector();

	//检查重复  参数:(传入id,传入类型) 返回值:(true 代表有重复，false代表没有重复)
    //--200714
	bool checkRepeat(int id, int type);

	//学生容器   --200714
	vector<Student> vStu;

	//教师容器   --200714
	vector<Teacher> vTea;

	//机房容器   --200715
	vector<ComputerRoom> vCom;

};