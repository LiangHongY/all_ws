//导入:STL基本知识
//C++三大特性：封装、继承、多态

//C++的面对对象和范式编程思想，目的是复用性的提升
//大多数情况下，数据结构和算法都未能有一套标准，导致被迫从事大量重复工作
//为了建立数据结构和算法的一套标准，诞生了STL

//STL（Standard Template Library，标准模板库）
//STL 从广义上分：容器（container）、算法（algorithm）、迭代器（iterator）
//容器和算法直接通过迭代器进行无缝连接
//STL几乎所有迭代器的代码都采用了模板类或者模板函数

//STL六大组件
//STL大体分为六大组件：容器、算法、迭代器、仿函数、适配器（配接器）、空间配置器

//需要记住：
//1、容器：各种数据结构，如：vector、list、deque、set、map等，用来存放数据
//2、算法:各种常用算法，如：sort、find、copy、for_each等
//3、迭代器：扮演了容器与算法之间的胶合剂
//4、仿函数：行为类似函数，可作为算法的某种策略
//5、适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
//6、空间适配器：负责空间的配置与管理

//容器：置物所也
//STL容器就是运用最广泛的一些数据结构实现出来
//常用的数据结构：数组、链表树、栈队列、集合、映射表等
//这些容器分为：序列式容器和关联式容器两种：
//序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置
//关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

//算法：问题之解法也
//有限的步骤，解决逻辑数学上的问题，这一门科学叫做算法（Algorithms）
//算法可分为：质变算法和非质变算法
//质变算法：是指算法过程中会更改区间内的元素的内容，例如拷贝、替换、删除等等
//非质变算法：是指运算过程中不会更改区间内的元素内容，例如：查找、计数、遍历、寻找极值等等

//迭代器：容器和算法之间粘合剂
//提供一种方法，使之能偶依序寻访某个容器所含的各个元素，而无需暴露该容器的内部表示方式，
//每个容器都有自己专属的迭代器
//迭代器非常类似指针，初始阶段，可以将迭代器理解为指针

//迭代器种类：

//种类：功能：支持运算
//输入型：对数据的只读访问：只读，支持++、==、！=
//输出型：对数据的只写访问：只写，支持++
//前进型：读写操作，并能向前推进迭代器：读写，支持++、==、！=
//双向型：读写操作，并能向前和向后操作：读写，支持++、--
//随机访问型：读写操作，可以以跳跃方式访问任意数据，功能最强的迭代器：读写，支持
//++、--、[n]、-n、<、<=、>、>=

//常用的容器为双向迭代器和随机访问迭代器

//vector存放内置数据类型
//容器：vector
//算法：for_each
//迭代器：vector<int>::iterator

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>//标准算法头文件

//vector容器存放内置数据类型

void myPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	//创建了一个vector容器，数组
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);//固定关键字，尾插数据
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	////通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
	//vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置

	////第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	////第二种遍历方式
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//第三种遍历方式，利用STL提供遍历算法
	for_each(v.begin(), v.end(), myPrint); //这里的myPrint采用了回调原理

}

void main()
{
	test01();

}