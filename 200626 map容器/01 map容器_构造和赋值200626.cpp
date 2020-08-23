#include<iostream>
#include<map>
using namespace std;

//map容器基本概念，简介：
//map中所有元素都是pair
//pair中第一元素为key(键值)，起到索引作用，第二元素为value（实值)
//所有元素都会根据元素的key键值自动排序

//本质：
//map/multimap属于关联式容器，底层结构是用二叉树实现

//优点：
//可以根据key值快速找到value值
//（key值可以理解为学号，value值理解为学生，通过学号可以快速找到该学生）

//map和multimap的区别：
//map不允许容器中有重复的key值元素
//multimap允许容器中有重复key值元素




//map构造和赋值，功能描述：
//对map容器进行构造和赋值操作

//函数原型

//构造：
//map<T1,T2> mp;       //map默认构造函数
//map(const map &mp);  //拷贝构造函数

//赋值：
//map& operator=(const map &mp);    //重载等号操作符



//map容器 构造和赋值

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " " << it->second << endl;
	}
	cout << endl;
}


void test01()
{
	//创建map容器
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));//注意插入数据时的样式
	m.insert(pair<int, int>(6, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	//遍历
	printMap(m);

	//拷贝构造
	map<int, int>m2(m);
	printMap(m2);

	//赋值
	map<int, int> m3;
	m3 = m2;
	printMap(m3);

}


int main()
{
	test01();
	system("pause");
	return 0;
}

//总结：map中所有元素都是成对出现，插入数据时候要使用对组