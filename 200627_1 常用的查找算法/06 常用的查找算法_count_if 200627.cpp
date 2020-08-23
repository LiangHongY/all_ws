#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//count_if   功能描述
//按条件统计元素个数

//函数原型：
//count_if(iterator beg,iterator end,_Pred);
//按照条件统计元素出现的次数
//beg   开始迭代器
//end   结束迭代器
//_Pred  谓词


//1、内置数据类型
class Greater20
{
public:
	bool operator()(int v1)
	{
		return v1 > 20;
	}
};

void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(13);
	v.push_back(40);
	v.push_back(30);
	v.push_back(100);
	v.push_back(90);
	v.push_back(80);

	int num=count_if(v.begin(), v.end(), Greater20());

	cout << "大于20的元素个数：" << num << endl;

}



//2、自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}


	string m_Name;
	int m_Age;
};
class greater40
{
public:
	bool operator()(Person p)
	{
		return p.m_Age > 40;
	}
};


void test02()
{
	vector<Person>v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 25);
	Person p5("曹操", 45);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(),greater40());

	cout << "大于40的人数为：" << num << endl;

}



int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
