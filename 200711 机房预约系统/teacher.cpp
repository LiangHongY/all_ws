#include"teacher.h"

//--201012
//默认构造     
Teacher::Teacher()
{

}

//有参构造（职工编号、姓名、密码）
Teacher::Teacher(int empId, string name, string pwd)
{
	//  -200716
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//菜单界面
void Teacher::operMeun()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      1、查看所有预约     |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      2、审核预约         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      0、注销登录         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "请选择您的操作：" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	//--200716
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "、";

		cout << "预约日期：周" << of.m_orderDate[i]["date"];
		cout << "时段：" << (of.m_orderDate[i]["intercal"] == "1" ? "上午" : "下午");
		cout << "学号：" << of.m_orderDate[i]["stuId"];
		cout << "姓名：" << of.m_orderDate[i]["stuName"];
		cout << "机房：" << of.m_orderDate[i]["roomId"];
		string status = "状态";//0  取消预约，1  审核中 ，2  已预约，-1  预约失败 

		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "已经成功预约";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "预约已经取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;

	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "等待审核的预约记录如下：" << endl;

	vector<int>v;
	int index = 0;

	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";

			cout << "预约日期：周" << of.m_orderDate[i]["date"];
			cout << "时段：" << (of.m_orderDate[i]["intercal"] == "1" ? "上午" : "下午");
			cout << "学生编号:" << of.m_orderDate[i]["stuId"];
			cout << "学生姓名" << of.m_orderDate[i]["stuName"];
			cout << "机房：" << of.m_orderDate[i]["roomId"];
			string status = "状态";//0取消预约；1审核中；2已经预约；-1预约失败
			if (of.m_orderDate[i]["status"] == "1")
			{
				status += "状态：审核中";
			}
			cout << status << endl;
		}
	}

	cout << "请输入审核的预约记录，0表示返回" << endl;
	int select = 0;   //用户选择
	int ret = 0;  //接受预约结果记录
	while (true)
	{
		cin >> select;
		if (select == 0)
		{
			break;
		}
		else
		{
			cout << "请输入审核结果" << endl;
			cout << "1、通过" << endl;
			cout << "2、不通过" << endl;
			cin >> ret;

			if (ret == 1)
			{
				//通过
				of.m_orderDate[v[select - 1]]["status"] = "2";
			}
			else
			{
				//不通过
				of.m_orderDate[v[select - 1]]["status"] = "-1";
			}
			of.updateOrder();//更新记录
			cout << "审核完毕！" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
	
}