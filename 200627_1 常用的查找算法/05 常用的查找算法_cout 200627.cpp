#include<iostream>
#include<vector>
#include<string>

using namespace std;

//count   功能描述：
//统计元素个数

//函数原型：
//count(iterator beg,iterator end,value);
//统计元素出现的次数
//beg    开始迭代器
//end    结束迭代器
//value  统计的元素


//1、统计  内置数据类型
void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(3);
	v.push_back(10);

	int num=count(v.begin(), v.end(), 10);

	cout << "查找的数据个数为：" << num << endl;

}

//2、统计  自定义数据类型
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//重载== 以告诉该算法 底层的比对规则
	bool operator==(const Person& p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	string m_Name;
	int m_Age;
};
//class mycompare {
//public:
//	bool operator()(Person& p1, Person& p2)
//	{
//		return p1.m_Age == p2.m_Age;
//	}
//};

void test02()
{
	vector<Person>v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 40);

	Person p("诸葛亮", 35);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num=count(v.begin(), v.end(), p);

	cout << "容器内，和诸葛亮同年龄人数有：" << num << endl;
}



int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//总结：
//统计自定义数据类型时候，需要配合重载  operator==