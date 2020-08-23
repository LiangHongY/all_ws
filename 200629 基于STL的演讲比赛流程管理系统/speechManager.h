#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>     //
#include<functional>
#include<numeric>    
#include<string>     //字符串变量
#include<fstream>   //读写文件
#include<ctime>     //随机数种子需要系统时间产生随机数

using namespace std;

//设计演讲管理类
class SpeechManager
{
public:
	//构造函数 --200705
	SpeechManager();

	//显示菜单  --200705
	void show_Menu();

	//退出功能  --200705
	void exitSystem();

	//成员属性添加  --200705
	//比赛选手   容器  12人
	vector<int>v1;
	//第一轮晋级容器   6人
	vector<int>v2;
	//胜利前三名容器   3人
	vector<int>vVictory;
	//存放编号  以及对应的  具体选手  容器
	map<int, Speaker> m_Speaker;
	//记录比赛轮数
	int m_Index;

	//开始比赛的成员函数 --200705
	//初始化容器和属性
	void initSpeech();

	//提供开始演讲比赛的成员函数,创建12名选手  --200705
	void createSpeaker();

	//开始比赛   比赛整个流程控制函数    --200705
	void startspeech();

	//抽签     --200705
	void speechDraw();

	// 比赛  --200706
	void speechContest();

	//显示比赛结果  --200707
	void showScore();

	//保存数据    --200707
	void saveRecord();

	//读取记录   --200708
	void loadRecord();

	//文件为空标志   --200708
	bool fileIsEmpty;

	//记录往届记录   --200708
	map<int, vector<string>> m_Record;

	//查看记录功能   --200709
	void showRecord();

	//清空记录   --200710
	void clearRecord();


	//析构函数  --200705
	~SpeechManager();
};