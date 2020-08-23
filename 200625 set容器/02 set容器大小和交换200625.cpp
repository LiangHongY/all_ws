#include<iostream>
using namespace std;
#include<set>

//set大小和交换，功能描述：
//统计set容器大小和交换set容器

//函数原型：
//size();     //返回容器中元素的数目
//empty();    //判断容器是否为空
//swap(st);   //交换两个集合容器

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test01()
{
	set<int>s;

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(6);

	printSet(s);

	if(s.empty())
	{
		cout << "该容器数据为空" << endl;
	}
	else
	{
		cout << "该容器数据不为空，容量大小为：" << s.size() << endl;
	}

	set<int>s1;
	s1.insert(21);
	s1.insert(32);
	s1.insert(12);
	
	cout << "交换前s1：" << endl;
	printSet(s1);

	cout << "交换后的s1:" << endl;
	s1.swap(s);
	printSet(s1);
}

int main()
{
	test01();

	system("pause");
	return 0;
}

//set容器不能指定大小
//总结：
//统计大小  --size
//判断是否为空  --empty
//交换容器     --swap

