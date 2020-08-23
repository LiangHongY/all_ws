#include<iostream>
using namespace std;

#include<deque>
//deque数据存取，功能描述
//对deque中的数据存取操作

//函数原型：
//at(int idx);   //返回索引idx所指的数据
//operator[];    //返回索引idx所指的数据
//front();       //返回容器中第一个数据元素
//back();        //返回容器中最后一个数据元素


//数据存取

void printDeque(deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	d.push_front(100);
	d.push_front(203);
	d.push_front(204);
	d.push_front(205);

	//通过[]方式访问元素
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	//通过at方式访问元素
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素是： " << d.front() << endl;
	cout << "最后一个元素为：" << d.back() << endl;
}


int main()
{
	test01();
	system("pause");
	return 0;
}

//总结：
//除了用迭代器获取deque容器中元素，[]和at也可以
//front返回容器第一个元素
//back返回容器最后一个元素