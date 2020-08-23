#include<iostream>
using namespace std;
#include<set>

//set容器排序，学习目标：
//set容器默认排序规则为从小到大，掌握如何改变排序规则

//主要技术点：
//利用仿函数，可与i改变排序规则

void printSet(const set<int>& s) 
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)//仿函数
	{
		return v1 > v2;
	}
};


void test01()
{
	set<int>s1;

	s1.insert(10);
	s1.insert(14);
	s1.insert(54);
	s1.insert(70);
	s1.insert(190);
	s1.insert(9);

	printSet(s1);//默认排序是从小到大

	//指定排列规则为从大到小

	set<int,MyCompare>s2;   //这里指定排列的规则

	s2.insert(10);
	s2.insert(14);
	s2.insert(54);
	s2.insert(70);
	s2.insert(190);
	s2.insert(9);

	//printSet(s2);//报错原因是，每种类型容器都有专用的迭代器
	for (set<int, MyCompare>::iterator it = s2.begin();it != s2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;//报错，说指定规则后，底层代码出错，原因未知。200625

}


int main()
{
	test01();

	system("pause");
	return 0;
}
//总结：利用仿函数可以指定set容器的排序规则
//自定义排序规则报错，未解决200625