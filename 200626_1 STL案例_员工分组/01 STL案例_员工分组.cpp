//案例描述
//公司招聘了10个员工（ABCDEFGHI），10个员工进入公司之后，需要指派员工在
//那个部门工作
//员工信息有：姓名  工资组成；部门分为：策划、美术、研发
//随机给10名员工分配部门和工资

//通过multimap进行信息插入   key（部门编号）  value（员工）
//分部门显示员工信息


//实现步骤
//1、创建10名员工，放到vector容器中
//2、遍历vector容器，取出每个员工进行随机分组
//3、分组后，将员工部门编号作为key，具体员工作为value，放到multimap容器中
//4、分部门显示员工信息






#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>

using namespace std;


#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;//10000~19999

		//将员工放到容器中
		v.push_back(worker);
	}
}

//员工分组
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int deptId = rand() % 3;//0\1\2

		//将员工插入分组中
		//key表示部门编号；value表示具体员工
		m.insert(make_pair(deptId,*it));
	}
}

//显示员工
void showWorkerGroup(multimap<int,Worker>&m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << endl;

	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << endl;

	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
	cout << endl;
}


int main()
{
	//系统时间真实随机
	srand((unsigned int)time(NULL));

	//1、创建员工
	vector<Worker>vWorker;
	createWorker(vWorker);

	////测试创建员工
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "姓名：" << it->m_Name << "  工资：" << it->m_Salary << endl;
	//}
	
	//2、员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker,mWorker);

	//3、分组显示员工
	showWorkerGroup(mWorker);

	system("pause");
	return 0;
}


//个人体会：
//这个案例太厉害了！！！！
//通过宏定义来对应了随机生成的部门编号
//multimap容器里面放着一个vector容器（员工分组里面应用）
//应用map容器中的find()  count() 函数来遍历容器（显示员工应用）

//重点是，我太菜了，这些容器性质函数并没有反应到脑海中，只是老师说出来才理解到这些内容
//200626