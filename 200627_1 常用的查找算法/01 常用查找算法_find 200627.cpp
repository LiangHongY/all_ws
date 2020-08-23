//常用查找算法，学习目标：
//掌握常用的查找算法

//算法简介：
//find          //查找元素
//find_if       //按条件查找元素
//adjacent_find   //查找相邻重复元素

//binary_search    //二分查找法,有的话就返回真，否则返回假
//count            //统计元素个数
//count_if         //按条件统计元素个数


#include<iostream>
#include<vector>
#include<string>

using namespace std;

//find  功能描述：
//查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

//函数原型：
//find(iterator beg,iterator end,value);
//按值查找元素，则返回指定位置迭代器，找不到就返回结束迭代器位置
//beg开始迭代器
//end结束迭代器
//value 查找的元素


//find

//查找  内置数据类型
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找 容器中 是否有  5 这个元素
	vector<int>::iterator pos= find(v.begin(), v.end(), 5);

	if (pos != v.end())
	{
		cout << "找到该元素：" << *pos << endl;
	}
	else
	{
		cout << "不存在该元素" << endl;
	}
}

class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//重载 ==  ，让底层find 知道如何对比  person  数据类型

	bool operator==(const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
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


//查找  自定义数据类型
void test02()
{
	vector<Person>v;

	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 310);
	Person p3("ccc", 30);
	Person p4("ddd", 550);

	//放到容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("aaa", 10);//容器外成员

	//对于自定义数据类型，涉及对比类型，需要给定对比规则，否则find底层是不知道怎么对比的
	vector<Person>::iterator pos = find(v.begin(), v.end(), pp);//找容器里面有没有和pp成员一样

	if (pos != v.end())
	{
		cout << "找到该成员：" << endl;
		cout << "年龄：" << pos->m_Age << " 姓名：" << pos->m_Name << endl;
	}
	else {
		cout << "未找到该成员" << endl;
	}
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//总结：利用find可以在容器中找指定的元素，返回的是迭代器
//find函数，对于自定义数据类型，需要重载  ==  号，让其底层知道   对比的   规则