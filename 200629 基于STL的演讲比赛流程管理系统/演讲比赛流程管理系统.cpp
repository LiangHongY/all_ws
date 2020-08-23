
//1.1
//比赛规则：
//学校举行一场演讲比赛，共有12人参加，比赛共两轮，第一轮为淘汰赛，第二轮为决赛

//每名选手都有对应的编号，如10001~10012
//比赛方式：分组比赛，每组6人
//第一轮分为两个小组，整体按照选手编号进行抽签后顺序演讲
//十个评委给每个选手打分，去除最高分和最低分，求的平均分为本轮选手的成绩
//当小组演讲完后，淘汰组内排名最后的三名选手，前三名晋级，进入下一轮比赛
//第二轮为决赛，前三名胜出
//每轮比赛后需要显示晋级选手的信息

//程序功能
//开始演讲比赛：完成整个比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
//查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用 .csv 后缀名保存
//清空比赛记录：将文件数据清空
//退出比赛程序：可以退出当前程序   --200705

//2、项目创建
//创建新项目
//添加文件   --200705



#include<iostream>
#include"speechManager.h"


using namespace std;

//3、创建管理类
//功能描述：
//提供菜单界面与用户交互
//对演讲比三流程进行控制
//与文件的读写交互

//3.1创建文件
//在头文件和原文件的文件夹下分别创建speechManager.h和speechManager.cpp文件  --200705

//4、菜单功能
//功能描述：与用户的沟通界面

//4.1 添加成员函数
//在管理类speechManager.h中添加成员函数  void show_Menu();

//5、推出功能
//功能描述：实现退出程序
//5.1提供功能接口
//在main函数中提供分支选择，提供美工功能接口   --200705

//6、演讲比赛功能
//6.1功能分析
//比赛流程分析
//抽签--开始演讲比赛---显示第一轮比赛结果
//抽签--开始演讲比赛---显示前三名结果---保存分数  --200705

//6.2创建选手类
//选手类属性包含：选手名字、分数
//头文件中创建speaker.h头文件并添加代码  --200705

//6.3比赛
//成员属性添加
//在speechManager.h中添加属性    --200705

//6.3.2初始化属性
//在speechManager.h中提供开始比赛的成员函数 void initSpeech();

//6.3.3创建选手
//在speechManager.h中提供开始演讲比赛的成员函数  void createSpeaker();   
//在speechManager.cpp中实现 void createSpeaker();
//在SpeechManager类的构造函数中调用  void createSpeaker();
//在main();函数中测试：可以在创建完管理对象后，使用迭代器方式访问并打印12名选手的初始方式   --200705

//6.3.4开始比赛成员函数添加
//在speechManager.h中添加开始比赛的成员函数  void startspeech();
//该函数功能主要控制比赛的流程             
//在speechManager.cpp中将startSpeech的空实现先写入
//我们可以先将整个比赛的流程写到函数中       --200705

//6.3.5抽签
//功能描述：
//正式比赛前，所有选手的比赛顺序需要打乱，我们只需要将存放选手编号的容器大陆按次序即可
//在SpeechManager.h中提供抽签的成员函数   void speechDraw();     --200705

//6.3.6开始比赛
//在speechManager.h中提供比赛的成员函数   void speechContest();   
//在speechManger.cpp中实现成员函数 --200706

//6.3.7显示比赛分数
//在speechManager.h中提供显示分数的成员函数  void showScore();
//在speechManager.cpp中实现成员函数  void showScore();   --200707

//6.3.8第二轮比赛
//第二轮比赛流程同第一轮，只是比赛的轮式+1，其余流程不变
//在startSpeech比赛流程种植的函数加上第二轮的流程   --200707

//6.4保存数据，功能描述
//将每次演讲比赛的得分记录到文件中
//功能实现：在speechManager.h中添加保存记录的成员函数  void saveRecord();
//在speechManager.cpp 中实现成员函数   void saceRecord();    --200707

//7、查看记录
//7.1读取记录分数
//在speechManager.h中添加保存记录的成员函数   void loadRecord();
//添加判断文件是否为空标志   bool fileIsEmpty;
//添加往届记录的容器   map<int,vector<string>> m_Record;
//其中m_Record中的key代表第几届，value记录具体的信息
//在speechManager.cpp中实现成员函数，void loadRecord();     --200708

//7.2 查看记录功能
//在speechManager.h中添加保存记录的成员函数 void showRecord();
//在speechManager.cpp中实现成员函数  void showRecord();   --200708

//7.3  测试功能缺   --200709

//7.4  bug解决
//目前程序中有几处bug没有解决，若文件不存在或为空，并未提示
//1、查看往届记录，若文件不存在或为空，并未提示
//解决方式：在showRecord()函数中，开始判断文件状态加以判断   --200709

//2、若记录为空或者不存在，比完赛后依然提示记录为空
//解决方式：saveRecord更新文件为空的标志    --200709

//3、比完赛后查不到本届比赛的记录，没有实时更新
//解决方式：比完赛后，所有数据重置       --200709

//4、在初始化时，没有初始化记录容器
//解决方式：initSpeech添加初始化记录容器    --200709

//5、解决每次记录数据都是一样的
//解决方式： 在main函数中一开始添加随机数种子   --200709


//8、清空记录
//8.1清空记录功能实现
//在speechManager.h中添加保存记录的成员函数  void clearRecord();
//在speechManager.cpp中实现成员函数  void clearRecord();   --200710

int main()
{
	//添加随机数种子   解决每次比赛后的数据一样的bug   --200709
	srand((unsigned int)time(NULL));

	//创建管理类对象
	SpeechManager sm;
	

	//选择功能
	int choice = 0;//存储用户选项

	while (true)
	{
		sm.show_Menu();//200705

		cout << "请输入您的选择：" << endl;
		cin >> choice;//接受用户的选择

		switch (choice)
		{
		case 1://开始比赛
			sm.startspeech();
			////测试创建12名成员
			//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
			//{
			//	cout << "选手编号：" << it->first
			//		<< "姓名：" << it->second.m_Name
			//		<< "成绩：" << it->second.m_Score[0] << endl;
			//}  --200705
			break;

		case 2://查看往届比赛记录
			sm.showRecord();
			break;

		case 3://清空比赛记录
			sm.clearRecord();    //--200710
			break;

		case 0://退出系统
			sm.exitSystem();
			break;

		default:
			system("cls");//清屏
			break;
		}
	}


	system("pause");
	return 0;
}

//个人体会
//这个案例最大感觉，通过随机数种子产生编号以及成绩
//容器里面仿真容器，访问时候要不断的记住，这个容器里面到底放着什么成员。   --200710