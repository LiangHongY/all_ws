#include<iostream>
using namespace std;
#include"workerManager.h"

//#include"worker.h"
//#include"employee.h"
//#include"manager.h"
//#include"boss.h"

int main()
{
	////测试代码
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;



	//实例化管理者对象
	WorkerManager wm;

	int choice = 0;//用来存储用户的选项

	while (true)
	{
		//调用展示菜单成员函数
		wm.Show_Menu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;//接受用户的选项

		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
		//{
		//	//测试
		//	int ret = wm.IsExist(1);
		//	if (ret != -1)
		//	{
		//		cout << "职工存在" << endl;
		//	}
		//	else
		//	{
		//		cout << "职工不存在" << endl;
		//	}
		//	break;
		//}
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://排序职工200328
			wm.Sort_Emp();
			break;
		case 7://清空文档200328
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏操作
			break;
		}
	}
	system("pause");
	return 0;
}
//截止20200423，该项目现有基本调试功能调试完毕。但是，还是存在一个内存有可能溢出的bug没有解决。