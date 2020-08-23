
//--200711
//1、机房预约系统需求
//1、1系统简介
//学校现有几个规格不同的机房，由于使用时经常出现“撞车”现象，开发的机房预约
//系统，解决这个问题

//1.2 身份简介
//分别由三种身份使用该程序
//学生带别：申请使用机房
//教师：审核学生的预约申请
//管理员：给学生、教师创建账号

//1.3机房简介
//1号机房  ---  最大容量20人
//2号机房  --最多容量50人
//3号机房  --最多容量100人

//1.4申请简介
//申请的订单每周由管理员负责清空
//学生可以预约的未来一周内的机房使用，预约时间的日期未周一到周五，预约时间
//需要选择预约时段（上午、下午）
//教师来审核预约，一局实际情况审核预约通过或者不通过

//1.5系统具体需求
//首先进入登陆界面，可选登录身份：
//学生代表、老师、管理员、退出

//每个身份都需要进行验证后，进入子菜单
//学生需要输入：学号、姓名、登录密码
//老师需要输入：职工号、姓名、登录密码
//管理员需要输入：管理员姓名、登录密码

//学生具体功能：
//申请预约    --预约机房（日期、时间段、机房号、生成记录）
//查看自身预约  --查看全部预约信息以及预约状态
//取消预约  --取消自身预约，预约成功或审核中的预约都可以取消
//注销登录  退出学生登录

//教师具体功能：
//查看所有预约  --查看全部的预约信息以及预约状态
//审核预约  --对学生的预约进行审核
//注销登录  --退出登录

//管理员具体功能
//添加账号   --添加学生或教师的账号，需要检测学生编号或教师工号是否重复
//查看账号  --可以选择查看学生或教师全部信息
//查看机房  --查看所有机房的信息

//预约状态：审核中、预约成功、预约失败、取消预约
//机房信息：机房编号、最大容量

//--200711

//2、创建项目

//3、创建主菜单，功能描述：
//设计主菜单，与用户进行交互  --200711

//3.1菜单实现
//在主函数main中添加菜单提示  --200711

//3.2搭建接口
//接受用户的选择，搭建接口
//在main中添加代码  --200711

//4、退出功能实现  --200711

//5、创建身份类
//5.1身份的基类
//在整个系统中，有三种身份，分别为：学生代表、老师以及管理员
//三种身份有其特性，因此我们可以有三种身份抽象出一个身份基类identity
//在头文件下创建identity.h文件   --200712

//5.2学生类
//5.2.1功能分析
//学生类组要功能是可以通过类中成员函数，事先预约实验室操作
//学生类中主要功能有：
//显示学生操作功能的菜单界面
//申请预约
//查看自身预约
//查看所有预约
//取消预约

//5.2.2在头文件以及源文件下创建student.cpp文件
//student.h中添加代码    --200712

//5.3老师类
//5.3.1功能分析
//教师类主要功能时查找学生的预约，并进行审核
//教师类中主要功能有:
//显示教师操作的菜单界面
//查看所有预约
//审核预约       --200712

//5.3.2管理员类的创建
//在头文件以及源文件下创建teacher.h和teacher.cpp文件   --200712

//5.4管理员类
//5.4.1功能分析
//管理员类主要功能是对学生和老师账户进行管理，查看机房信息以及清空预约记录
//管理员类中主要功能：
//显示管理员操作的菜单界面
//添加账号
//查看账号
//查看机房信息
//清空预约信息       --200712

//6、登录模块
//6.1全局文件添加
//功能描述：
//不同身份可能会用到不同文件操作，我们可以将所有的文件定义到一个全局的文件中
//在头文件globalFile.h文件声明    --200712

//6.2登录函数封装
//功能描述：
//根据用户选择，进入不同的身份登录
//在预约系统中  .cpp  文件中添加全局函数  void LoginIn(string fileName,int type)

//参数：
//fileName   --操作的文件名
//type  --登录的身份  （1代表学生、2代表老师、3代表管理员）

//6.3学生登录实现：在student.txt文件中添加两天学生信息，用于测试

//6.4教师端登录实现 --200712

//7、管理员模块
//7.1管理员登录和注销
//7.1.1构造函数  在Manger类的构造函数中，初始化管理员信息。

//7.1.2管理员子菜单
//在机房预约系统cpp中，当用户登录的是管理员，添加管理员菜单接口
//将不同的分支提供出来
//添加账号、查看账号、查看机房、清空预约、注销登录
//添加管理员菜单全局函数  --200714

//7.2添加账号
//功能描述
//给学生或教师添加新的账号
//功能要求：
//添加时学生学号不能重复，教师职工号不能重复

//7.2.1添加功能实现
//在Manager的addPerosn成员函数中，实现添加新账号功能  --200714

//7.2.2去重操作
//功能描述：添加新账号时，如果时重复的学生编号，或是重复的教师职工编号，提示有误

//7.2.2.1读取信息
//要去除重复的账号，首先要将学生教师的账号信息获取到程序中，方可检测
//在manager.h中，添加两个容器，用于存放学生和教师信息
//添加一个新的成员函数  void initVector()  初始化容器    --200714

//7.2.2.2去重函数封装
//在manager.h文件中添加成员函数 bool chechRepeat(int id,int tyoe);  --200714

//7.2.2.4bug解决
//bug描述：
//虽然可以检测重复的账号，但是刚添加的账号由于没有更新到容器中，因此不会做检测
//虽然刚加入的账号的学生号或者职工编号，再次添加时依然可以重复

//解决方案，在每次添加账号时，重新初始化容器   --200715

//7.3.1显示功能实现
//在Manager中showPerson成员函数中，实现显示账号功能  --200715

//7.4查看机房
//7.4.1添加机房信息   --200715

//7.5清空预约 
//功能描述：清空生成的order.txt预约文件
//在Manager的cleanFile成员函数中添加代码  --200714

//8、学生模块
//8.1学生登陆和注销
//8.1.1构造函数
//在Student类中的构造函数，初始化学生信息  --200715

//8.1.2管理员子菜单
//在机房预约系统cpp中，当用户登录的是学生，添加学生菜单接口
//将不同的分支提供出来
//申请预约、查看我的预约、查看所有预约、取消预约、注销登录
//实现注销功能

//添加全局函数  void studentMenu(Identity * &manager)  
//8.1.4接口对接    
//学生登录成功后，调用学生的子菜单界面
//在学生分支中 添加代码    --200715

//8.2申请预约
//8.2.1获取机房信息
//在申请预约时，学生可以看到机房的信息，因此我们可以需要让学生获取机房的信息
//在student中添加新的成员函数，vector<ComputerRoom> vCom;
//在构造函数中补充获取机房信息代码    --200715

//8.2.2 预约功能实现
//在student.cpp中实现成员函数  void Student::applyOrder();    --200715

//8.3显示预约
//8.3.1创建预约类
//功能描述：显示预约记录时，需要从文件中获取到所有记录，用来显示、创建预约的类来管理记录
//以及更新
//在头文件以及源文件中分别创建 orderFile.h  和  orderFile.cpp  文件   --200715

//更新预约记录的成员函数updateOrder   --200716

//8.3.2显示自身预约
//首先我们添加几条预约记录，可以用程序添加或者直接修改order.txt文件  
//在Student类的void Student::showOrder()成员函数中更新代码   --200716

//8.3.3显示所有预约
//在Student类的void Student::showAllOrder() 编写   --2007167

//8.4取消预约
//在Student类的void Student::cancelOrder()  成员函数  添加取消预约代码  --200716

//9、教师模块
//9.1教师登录和注销
//9.1.1构造函数
//在Teacher类的构造函数中，初始化教师信息  

//教师子菜单
//在机房预约系统.cpp中，当用户登录的是教师，添加教师菜单接口 
//查看所有预约、审核预约、注销登录 
//实现注销功能   --200716

//9.2  查看所有预约
//9.2.1所有预约功能实现
//该功能和学生的查看所有预约功能相似，用于显示所有预约记录 
//在Teacher.cpp中  实现成员函数  void Teacher::showAllOrder();  --200716

//9.3审核预约
//9.3.1审核功能实现
//功能描述：教师审核学生的预约，依据实际清空审核预约
//在Teacher.cpp中实现成员函数  void Teacher::validOrder()   --200716


#include<iostream>

using namespace std;

#include"globalFile.h"
#include"identity.h"
#include<fstream>
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"


//进入学生子菜单    --200715
void studentMenu(Identity*& student)
{
	while (true)
	{
		//学生菜单 
		student->operMeun();

		Student* stu = (Student*)student;
		int select = 0;
		
		cin >> select;

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select==2)  //查看自身预约
		{
			stu->showMyorder();
		}
		else if (select == 3)  //查看所有预约
		{
			stu->showAllorder();
		}
		else if (select == 4)  //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//教师子菜单
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//教师菜单
		teacher->operMeun();

		Teacher* tea = (Teacher*)teacher;//看不出来问题出在哪里？--原来函数开头写成了构造函数了
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//管理员菜单  --200714
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMeun();

		Manager* man = (Manager*)manager;  //将父类指针强转为子类指针访问子类接口
		int select = 0;

		cin >> select;

		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			//注销模块
			delete manager;   //手动开辟在堆区的，需要手动释放
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}    //--200714
}


//登录功能  参数1  操作文件名  参数2  操作身份类型   --200712
void LoginIn(string fileName, int type)   
{                                         //二次判断都是进不去的  -200712
	//cout << "调用登录函数" << endl;

	//父类指针，用于指向子类对象
	Identity * person = NULL;  //多态原理，父类指针创建子类对象

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	else
	{
		//准备接受用户信息
		int id = 0;
		string name;
		string pwd;

		//判断身份
		if (type == 1)   //学生登录
		{
			cout << "请输入您的学号" << endl;
			//cout << fileName << " " << type << endl;
			cin >> id;
		}
		else if (type == 2)    //教师登录
		{
			cout << "请输入您的职工号" << endl;
			cin >> id;
		}

		cout << "请输入用户名：" << endl;
		cin >> name;

		cout << "请输入密码：" << endl;
		cin >> pwd;

		//cout << "******************************" << endl;
		if (type == 1)
		{
			//学生身份验证  --200712
			int fId;   //从文件中读取的id号
			string fName;   //从文件中获取的姓名
			string fPwd;    //从文件中获取密码
			//ifs >> fId;
			//cout << fId << endl;  //测出读取文件异常  --200714
			while (ifs >> fId && ifs >> fName && ifs >> fPwd)//一行一行右移方式，根据空格来读写
			{
				//cout << fId << " " << fName << " " << fPwd << endl;//又是编译不进入该循环

				if (fId == id && fName == name && fPwd == pwd)
				{
					cout << "学生验证登录成功！" << endl;
					system("pause");
					system("cls");
					person = new Student(id, name, pwd);    //一直提示无法实例化,下面老师那边没有提示，搞不懂  --200712
					//学生就是个个奇葩，搞不懂这个bug出在哪里  --200712  
					//原来是继承父类的虚构造函数operMeun写错了，un写成了nu.  -200714
					//进入学生身份的子菜单
					studentMenu(person);
					return;
				}
			}

		}
		else if (type == 2)
		{
			//教师登录，身份验证
			int fId;   //从文件中读取的id号
			string fName;   //从文件中获取的姓名
			string fPwd;    //从文件中获取密码
			while (ifs >> fId && ifs >> fName && ifs >> fPwd)//根据空格来读写
			{
				cout << fId << " " << fName << " " << fPwd << endl;//又是编译不进入该循环

				if (fId == id && fName == name && fPwd == pwd)
				{
					cout << "老师验证登录成功！" << endl;
					system("pause");
					system("cls");
					person = new Teacher(id, name, pwd);
					//进入老师身份的子菜单    -200712
					TeacherMenu(person);  //--200716
					return;
				}
			}
		}
		else if (type == 3)
		{
			//管理员登陆，身份验证
			string fName;   //从文件中获取的姓名
			string fPwd;    //从文件中获取密码
			//cout << "******************************" << endl;

			while (ifs >> fName && ifs >> fPwd)//根据空格来读写
			{
				cout << fName << " " << fPwd << endl;//又是编译不进入该循环

				if (fName == name && fPwd == pwd)
				{
					cout << "管理员验证登录成功！" << endl;
					system("pause");
					system("cls");
					person = new Manager(name, pwd);
					//进入管理员身份的子菜单    -200712

					//进入管理员子菜单  --200714
					managerMenu(person);

					return;
				}
			}
		}
		cout << "验证失败，不可登录！" << endl;
	}
	system("pause");
	system("cls");
	return;

}    //--200712




int main()
{
	//ofstream ofs;
	//ofs.open("computerRoom.txt", ios::trunc);
	//通过使用自带的方式创建的文本文件，采用英文
	//输入法填写资料，基本上功能都是ok了  --200717

	int select = 0;//用于接受用户选择
	while (true)
	{
		cout << "----欢迎来到机房预约系统-----" << endl;
		cout << endl << "请登录您的身份" << endl;
		cout << "\t\t----------------------\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    1、学生代表     |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    2、老   师      |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    3、管理员       |\n";
		cout << "\t\t|                    |\n";
		cout << "\t\t|    0、退 出        |\n";//使用转义字符搭建界面
		cout << "\t\t|                    |\n";
		cout << "\t\t----------------------\n";
		cout << "请输入您的选择：";

		cin >> select;//接受用户的选择

		switch (select)//根据用户的选择，实现不同的接口
		{
		case 1:     //学生身份
			LoginIn(STUDENT_FILE, 1);
			//cout << "学生省份" << endl;
			break;

		case 2:     //老师身份
			LoginIn(TEACHER_FILE, 2);
			//cout << "老师省份" << endl;
			break;

		case 3:     //管理员身份
			LoginIn(ADMIN_FILE, 3);
			//cout << "管理员省份" << endl;
			break;

		case 0:     //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");  //按任意键
			return 0;   //退出系统  --200711
			break;

		default:
			cout << "输入有误，请重新输入选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}