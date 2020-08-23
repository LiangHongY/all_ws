#include"student.h"

//默认构造
Student::Student()
{
}

//有参构造（学号、姓名、密码）
Student::Student(int id, string name, string pwd)
{
	//初始化属性  --200715
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//读取机房信息  初始化  --200715
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}

//菜单界面
void Student::operMeun()
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      1、申请预约         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      2、查看我的预约     |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      3、查看所有预约     |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      4、取消预约         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      0、注销登录         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "请选择您的操作：" << endl;
}

//申请预约
void Student::applyOrder()
{
	//--200715
	cout << "机房开放时间为周一到周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int date = 0;  //日期
	int interval = 0;  //时间段
	int room = 0;  //机房编号

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;

	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;

		if (interval >=1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << "1号机房容量：" << vCom[0].m_MaxNum << endl;
	cout << "2号机房容量：" << vCom[1].m_MaxNum << endl;
	cout << "3号机房容量：" << vCom[2].m_MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入错误，请重新输入" << endl;
	}

	cout << "预约成功！审核中" << endl;

	ofstream ofs(ORDER_FILe, ios::app);  //接着写方式写进去

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

}

//查看我的预约
void Student::showMyorder()
{//-200716
	OrderFile of;
	//int k = 0;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		//k = 1;
		//这里很关键，如果不进行类型转换，没办法进行对比
		//string 转  int  过程：
		//string  利用 .c_str()  转  const  char *
		//利用  atoi  (const char*)   转  int
		//首先利用c_str(),把读进来的转为字符串类型，利用atoi，把该字符串类型转为int类型
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_Id)//找到自身预约
		{
			cout << "预约日期：周 " << of.m_orderDate[i]["date"];
			cout << " 时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房：" << of.m_orderDate[i]["roomId"];
			string status = "状态";// 0 取消预约  1审核中 2 已预约  -1预约失败

			if (of.m_orderDate[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderDate[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderDate[i]["status"] == "-1")
			{
				status += "预约失败";
			}
			else
			{
				status += "预约取消";
			}
			cout << status << endl;

		}
	}
	//if (k == 1)
	//{
	//	cout << "您没有进行过预约" << endl;
	//	k = 0;
	//}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllorder()
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
		cout << i + 1 << " ";

		cout << "预约日期：周" << of.m_orderDate[i]["date"];
		cout << "时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");
		cout << "学号：" << of.m_orderDate[i]["stuId"];
		cout << "姓名：" << of.m_orderDate[i]["stuName"];
		cout << "机房：" << of.m_orderDate[i]["roomId"];
		string status = "状态：";// 0 取消预约  1 审核中  2  已预约  -1 预约失败

		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "已成功预约";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "预约失败,审核未通过";
		}
		else
		{
			status += "取消预约";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder()
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
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int>v;   //存放在最大容器中的下标编号
	int index = 1;

	for (int i = 0; i < of.m_size; i++)
	{
		//先判断属于自身的
		if (atoi(of.m_orderDate[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderDate[i]["status"] == "1" || of.m_orderDate[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、 ";
				cout << "预约日期：周" << of.m_orderDate[i]["date"];
				cout << "时段：" << (of.m_orderDate[i]["interval"] == "1" ? "上午" : "下午");

				cout << "机房：" << of.m_orderDate[i]["roomId"];

				string status = "状态";   //0 取消预约   1  审核中  2  预约成功  -1 预约失败

				if (of.m_orderDate[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderDate[i]["status"] == "2")
				{
					status += "预约成功";
				}

				cout << status << endl;
			}
		}
	}

	cout << "请输入取消预约的记录，0代表返回" << endl;

	int select = 0;
	while (true)
	{
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "记录所在位置：" << v[select - 1] << endl;

				of.m_orderDate[v[select - 1]]["status"] = "0";//状态置为0就可以取消了
				//我怎么知道v里面的序号意义呢？有点迷  --根据上面输出的序号知道
				//但是里面的隔很远那种，只是-1，就合适了？
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
