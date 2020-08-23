#include"speechManager.h"
//构造函数
SpeechManager::SpeechManager()
{
	//初始化属性  --200705
	this->initSpeech();

	//创建选手  --200705
	this->createSpeaker();

	//获取往届记录  --200708
	this->loadRecord();


}

//显示菜单  --200705
void SpeechManager::show_Menu()
{
	cout << "*************************************" << endl;
	cout << "************欢迎参见比赛*************" << endl;
	cout << "*********1、开始演讲比赛*************" << endl;
	cout << "*********2、查看往届记录*************" << endl;
	cout << "*********3、清空比赛记录*************" << endl;
	cout << "*********0、退出比赛系统*************" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	
}

//退出功能  --200705
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//使用该函数实现退出功能
}

//开始比赛的成员函数 --200705
void SpeechManager::initSpeech()
{
	//容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index = 1;

	//初始化记录容器  解决没有初始化容器的bug  --200709
	this->m_Record.clear();
}

//创建比赛成员   --200705
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建选手编号，并放到v1容器中
		//12名选手
		this->v1.push_back(i + 10001);

		//选手编号  以及对应的选手  存放到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));//将两个编号和名字联系起来
	}
}

//开始比赛  --200705
void SpeechManager::startspeech()
{
	//第一轮比赛
	//1、抽签
	this->speechDraw();    //--200705

	//2、比赛
	this->speechContest();   //--200706

	//3、显示晋级结果
	this->showScore();     //--200707

	//第二轮比赛
	this->m_Index++;     //--200707

	//1、抽签
	this->speechDraw();    //--200707

	//2、比赛
	this->speechContest();   //--200707

	//3、显示最终结果
	this->showScore();      //--200707

	//4、保存分数
	this->saveRecord();     //--200707

	//重置比赛，获取记录  以解决数据未实时更新的bug   --200709  
	//初始化属性  
	this->initSpeech();
	//创建选手 
	this->createSpeaker();
	//获取往届记录  
	this->loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

//抽签
void SpeechManager::speechDraw()
{
	cout<<"第<<"<<this->m_Index<<">>轮比赛选手正在抽签"<<endl;//!!!!!!!!!!!!!!一种新的描述方式
	cout << "-----------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());//打乱保存选手编号的容器
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";

		}
		cout << endl;
		
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";

		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	system("pause");
	cout << endl;
}

//比赛  --200706
void SpeechManager::speechContest()
{
	cout << "-------------第" << this->m_Index << "轮正式比赛：----------------" << endl;
	multimap<double,int,greater<double>> groupScore;   //临时容器，保存key分数，value选手编号

	int num = 0;           //记录人员数，6个为一组

	vector<int>v_Src;     //比赛的人员容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//遍历所有参赛选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end();it++)
	{
		num++;

		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//600~1000
			//cout<<score<<" ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());      //排序
		d.pop_front();         //去掉最高分
		d.pop_back();          //去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);     //获取总分
		double avg = sum / (double)d.size();                   //获取平均分


		//cout << "编号：" << *it << "选手：" << this->m_Speaker[*it].m_Name << "获取平均分为：" 
		//	<< avg << endl;//打印分数

		//每个人平均分,将平均分放到map容器里/将打分数据放入到临时小组容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//6人为一组，用临时容器保存
		groupScore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号

		//每6人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次" << endl;

			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); 
				it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << "姓名：" << this->m_Speaker[it->second].m_Name
					<< "成绩：" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			int count = 0;

			//取走前三名，放到新容器里面保存
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();
			cout << endl;

		}

	}
	cout << "---------第" << this->m_Index << "轮比赛完毕-----------" << endl;
	system("pause");
}

//显示比赛结果  --200707
void SpeechManager::showScore()
{
	cout << "----------第" << this->m_Index << "轮晋级比赛选手信息如下：-------------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << "姓名：" << m_Speaker[*it].m_Name 
			<< " 得分：" << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

//保存数据    --200707
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out|ios::app);//用输出的方式打开文件,下次使用追加方式添加数据    
											  //也就是使用追加方式写文件

	//将每个人数据写进文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();

	cout << "记录已经保存" << endl;

	//有记录了，文件不为空 ；解决跟新了文件，还提示文件为空的bug  --200709
	this->fileIsEmpty = false;

}

//查看记录   --200708
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);     //输入流对象，读取文件

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())//判断是否读到文件尾部
	{
		cout << "文件为空！" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch);//把刚才读取的单个字符   放回去

	string data;

	int index = 0;

	while (ifs >> data)
	{
		//cout<<data<<endl;
		vector<string>v;

		int pos = -1;//查找","位置的变量
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);    //从0开始查找  ","
			if (pos == -1)
			{
				break;//找不到break返回
			}
			string tmp = data.substr(start, pos - start); //找到了，进行分割，
														  //参数1 起始位置，参数2  截取长度

			v.push_back(tmp);
			start = pos + 1;

		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	//{
	//	cout << it->first << "冠军编号：" << it->second[0] << " 分数：" << it->second[1] << endl;
	//}

}

//查看记录功能   --200708
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件不存在，或记录为空！" << endl;
	}//解决查看时文件为空或者不存在没有提示的bug   --200709
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届" <<
				" 冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				<< "亚军编号:" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				<< " 季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

//清空记录   --200710
void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式，  ios::trunc  如果存在文件，则删除文件并重新创建（利用文件打开方式来达到删除记录目的）
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->initSpeech();

		//创建选手
		this->createSpeaker();

		//获取往届记录
		this->loadRecord();

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}


//析构函数   --200705
SpeechManager::~SpeechManager()
{

}