#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件

using namespace std;//使用标准命名空间
#include<string>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>


#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//职工的分类为：普通员工、经理、老板
	//将三种职工抽象到一个类（worker）中，利用多态管理不同职工种类
	//职工的属性：职工编号、职工姓名、职工所在部门编号
	//职工的行为：岗位职责信息描述，获取岗位名称

	//记录职工人数
	int m_EmpNun;

	//职工数组指针
	Worker ** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();//功能异常

	//文件交互--读文件
	//第一次使用，文件未创建
	//文件存在，但数据被用户清空
	//文件存在，并且保存职工的所有数据

	//判断文件是否为空 标志
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
	int IsExist(int Id);

	//修改职工200327
	void Mod_Emp();

	//查找职工200327
	void Find_Emp();

	//按照职工编号排序
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkerManager();
};