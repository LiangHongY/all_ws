#include<iostream>
using namespace std;
#include<list>

//list 基本概念

//功能：将数据进行链式存储

//链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针
//链接实现的

//链表的组成：链表由一系列 结点 组成

//结点的组成：一个是存储数据元素的 数据域 ，另一个是存储下一个结点地址的  指针域 
//最后一个元素的指针域放的地址是NULL

//STL中的链表是一个双向循环链表

//为啥称为双向链表？
//结点的指针域是有两个指针的，一个是指向下一个结点地址，一个是指向上一个结点地址

//如果最后的一个结点的指针域有指针指向第一个结点，第一个结点指针域有指向向最后一个结点
//指针，那么，称该链表为双向循环链表

//从物理层面看，vector/deque/queue等等都是连续的，而链表是不连续的


//链表优点：
//可以对任意位置进行快速插入或删除元素
//缺点：
//list容器遍历速度没有数组快
//list容器占用空间比较大

//链表提供的一些函数：
//front();    //指向链表第一个元素迭代器
//back();     //指向最后一个元素

//begin();    //迭代器 ，指向第一个元素
//end();      //迭代器，指向最后一个元素
//insert();   //迭代器

//push_front();    //头插
//pop_front();     //头删
//push_back();     //尾插
//pop_back();      //尾删

//由于链表的存储方式不是连续的内存空间，因此链表list中的迭代器 只 支持前移和后移，
//属于双向迭代器;所以迭代器不能跳跃式访问

//list的优点：
//采用动态存储分配，不会造成内存浪费和溢出
//链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

//list的缺点
//链表灵活，但是空间（指针域）和时间（遍历时）额外耗费较大


//list 有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是
//不成立的

//总结：STL中的  list和vector  是两个最常被使用的容器，各有优缺点


//list构造函数，功能描述：
//创建list容器

//函数原型：
//list<T> lst;       //list采用模板类实现对像的默认构造形式
//list(beg,end);     //构造函数将（beg,end）区间中的元素拷贝给本身
//list(n,elem);      //构造函数将n个elem拷贝给本身
//list(const list &lst);   //拷贝构造函数

void printList(const list<int>&L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test01()
{
	//创建list容器
	list<int> L1;//默认构造

	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	//遍历容器
	printList(L1);

	//区间方式构造
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	//拷贝构造
	list<int>L3(L2);
	printList(L3);

	//n个elem形式
	list<int>L4(4, 65);
	printList(L4);

}

int main()
{
	test01();

	system("pause");
	return 0;
}
//总结：
//list构造方式和其他几个STL常用容器基本一样，熟练掌握即可