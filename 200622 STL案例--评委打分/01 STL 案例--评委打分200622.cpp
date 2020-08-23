#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>


//案例描述：
//有5名选手，ABCDE，10个评委分别对每一名选手进行打分，去除最高分，
//去除评委最低分，取平均分

//实现步骤
//1、创建5名选手，放到vector容器中，
//2、遍历容器，去除每一个选手，执行for循环，可以把10个评委打分保存到deque容器中
//3、sort算法对deque 容器中分数排序，去除最高分很最低分

//4、deque容器遍历一遍，累加总分
//5、获取平均分

//创建成员类
class Person 
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;//姓名
	int m_Score;//平均分
};

//创建成员
void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";//选手的名称
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);
		//cout << p.m_Name << " " << p.m_Score << endl;

		//cout << name<< " "<<score<<endl;//验证p的正常是否赋值
		//将创建的person对象放到容器中

		v.push_back(p);
		//cout << v[i].m_Name << " " << v[i].m_Score << endl;

	}

}//这个部分有错，还没有找出原因200622      //貌似没有问题了，现在200706

//打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数，放入deque容器中
		deque<int>d;

		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//40~100
			d.push_back(score);
		}

		//cout << "选手： " << it->m_Name << "打分：" << it->m_Score << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit<<" ";
		//}

		//排序
		sort(d.begin(), d.end());

		//去除最高和最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;//累加每个评委的分数
		}
		int avg = sum / d.size();

		//将平均分赋值到选手上面
		it->m_Score = avg;
		
	}
}

//显示分数
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 分数：" << it->m_Score << endl;
	}
}

int main()
{
	//随机数种子,可以使得每次运行程序生成的学生打分都不一样的
	srand((unsigned int)time(NULL));

	//1、创建5名选手
	vector<Person>v;//存放选后的容器

	createPerson(v);

	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名："<<(*it).m_Name << " 分数：" << (*it).m_Score<< endl;
	//}//输出是错误的200622  原因是Person类里面的构造函数成员错误了，错把分数赋值给名字了。200623

	//2、给5名选手打分
	setScore(v);



	//3、显示最后得分
	showScore(v);

	system("pause");
	return 0;
}