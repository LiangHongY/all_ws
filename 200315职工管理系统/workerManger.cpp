#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNun = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空！" << endl;
		//初始化记录人数
		this->m_EmpNun = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，并且记录数据200323
	int num = this->get_EmpNum();
	cout << "职工人数为： " << num << endl;
	this->m_EmpNun = num;   

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNun];
	//将文件中数组存到数组中
	this->init_Emp();

	////测试代码200323
	//for (int i = 0; i < this->m_EmpNun; i++)
	//{
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
	//		<< "姓名： " << this->m_EmpArray[i]->m_Name
	//		<< "部门编号： " << this->m_EmpArray[i]->m_DepthId << endl;
	//}
}


//展示菜单
void WorkerManager::Show_Menu()
{
	cout << "**********************" << endl;
	cout << "***欢迎使用职管系统***" << endl;
	cout << "***0、退出管理程序***" << endl;
	cout << "***1、增加职工信息***" << endl;
	cout << "***2、显示职工信息***" << endl;
	cout << "***3、删除离职职工***" << endl;
	cout << "***4、修改职工信息***" << endl;
	cout << "***5、查找职工信息***" << endl;
	cout << "***6、按照编号排序***" << endl;
	cout << "***7、清空所有文档***" << endl;
	cout << "*********************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序(这是一个退出系统函数，无论在哪里调用都会退出当前程序)
}

//添加职工

//用户在批量添加时候，可能会创建不同种类的职工
//如果想将所有不同种类的员工的指针维护到一个数组里
//如果想在程序中维护这个不定长度的数组，可以将数组创建在堆区，并利用Worker **的指针维护//20200422
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量： " << endl;
	int addNum = 0;//保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNun + addNum;//新空间人数=原来记录人数+新增人数//这里
		//this后面报语法错误，原因是，这个->号是敲进去的，而不是使用  .  ，编译器自动装换的

		//cout << newSize << endl;

		//开辟新空间
		Worker ** newSpace = new Worker * [newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNun; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		int b[1000];
		for (int i = 0; i < 1000; i++)
		{
			b[i] = 0;
		}//用于记录单次添加的id，防止单次添加相同的ID  20200423

		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			while (1) 
			{
				cout << "请输入第" << i + 1 << " 个员工编号:" << endl;
				cin >> id;
				int ret = this->IsExist(id);
				int c = 1;

				for (int i = 0; i < 1000; i++)
				{
					if (b[i] == id)
					{
						c = 0;
					}
				}

				//cout << id;
				if ((ret != -1)||(c==0))
				{
					cout << "编号已存在，请重新输入" << endl;
				}
				else
					break;
			}//添加了这个循环后还没有添加b[]数组时，可以避免原来文档中存在编号成员会再次重复输入情况发生，但是同一次读入多个相同编号成员是没有办法识别的。20200423
			b[i] = id;//记录新添加的ID，解决151行的bug。20200423



			cout << "请输入第" << i + 1 << " 个员工姓名:" << endl;
			cin >> name;
			
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、总裁" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1://普通职工
				worker = new Employee(id, name, 1);
				break;
			case 2://经理
				worker = new Manager(id, name, 2);
				break;
			case 3://老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工指针，保存到数组中
			newSpace[this->m_EmpNun + i] = worker;
			//cout <<"aaaaaa" << endl;
		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNun = newSize;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存数据
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键后，清屏回到上级目录
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//用输出的方式打开文件---写文件

	//将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNun; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id<< " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DepthId << endl;//录入工作人员处报错，原因未知。20200319//在103添加了该测试点后，发现可以写数据进文件里面了；后面注释掉这个测试点，
		                                              //发现也是可以写数据进去了，没有出现录入失败报错出现了20200422
	}

	//关闭文件
	ofs.close();
}
//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件，读

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		//统计人数变量
		num++;
	}
	return num;
	cout << num << endl;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//普通员工
		{
			worker = new Employee(id ,name,dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else//老板
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();//关闭文件

}

//展示职工200326
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空！" << endl;
	}
	else
	{
		for( int i=0;i < m_EmpNun; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//按任意键后清屏
	system("pause");
	system("cls");
}//测试异常：第一步的if输出异常

//删除职工200326
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入要删除职工编号： " << endl;
		int id = 0;
		cin >> id;

		int index=this->IsExist(id);

		if (index != -1)//说明职工存在，并且删除index位置的员工
		{
			for (int i = index; i < this->m_EmpNun - 1; i++)
			{
				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNun--;//更新数组中记录人员个数
			//同步更新到文件中
			this->save();

			cout << "删除成功！" << endl;

		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	//按任意键清屏操作
	system("pause");
	system("cls");
}//测试异常：每次都自动删除一个人，然后也没有提示删除成功；显示数据部分也是异常的
//即使文件为空也没有任何提示；推测是调用save函数也就是添加员工那个步奏导致的。（202003xx）
//现在这个程序可以正常使用了，save函数逻辑上没有错误，

//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1   200326
int WorkerManager::IsExist(int id)
{
	int index = -1;
	//cout << id << endl;
	//cout << this->m_EmpNun;

	for (int i = 0; i < this->m_EmpNun; i++)
	{
		if ((this->m_EmpArray[i]->m_Id )== id)
		{
			//找到职工
			index =i;
			//cout << this->m_EmpArray[i]->m_Id << endl;
			//cout << index << endl;
			//cout << i << endl;
			break;
		}
		//cout << this->m_EmpNun << endl;//添加这个测试语句后，整个存在查找表现正常了，并且所有功能都可以正常使用了。具体原因未知。
		//给我的感觉是，这个程序没加过这句话之前都是没有正常完整读到这个程序的。20200423
	}
	return index;
}

//修改职工200327
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找编号的职工
			delete this->m_EmpArray[ret];
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查找：" << id << "号员工，请输入新职工编号" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1. 普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
				
			default:
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();

		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}

//查找职工200327
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//找到该职工
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else 
			{
				cout << "该员工不存在" << endl;
			}//修正619行的bug
		}
		else if (select == 2)
		{
			//按照职工姓名查
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			//加入判断是否查找到标志
			bool flag = false;//默认未找到职工

			for (int i = 0; i < m_EmpNun; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为：" 
						<< this->m_EmpArray[i]->m_Id 
						<< "号信息如下：" << endl;

					flag = true;

					//显示信息
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}

		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");

}//名字查找显示异常的

//按照职工编号排序200328
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		
		for (int i = 0; i < m_EmpNun; i++)
		{
			int minOrMax = i;//声明最小值或最大值下标

			for (int j = i + 1; j < this->m_EmpNun; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id <this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

          //判断一开始认定最小值或最大值，是不是计算最小值或最大值，如果不是，就交换数据
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
	}
	cout << "排序成功！排序结果为：" << endl;
	this->save();//排序后结果保存到文件中
	this->Show_Emp();//展示所有职工
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		//打开模式 ios::trunc 如果存在，删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNun; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
           //删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;

			this->m_EmpNun = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;

	}
}

//新bug：当使用编号查找员工，不存在时候，没有提示不存在该人，而姓名查找会提示20200601   已解决
//新bug：但需要输入编号时，输入的是字符类型会导致程序陷入死循环200602  查明：id属于int类型，不能写字符串，或者说，应该让字符串自动转化为int或者添加循环，直到输入是int类型的id
