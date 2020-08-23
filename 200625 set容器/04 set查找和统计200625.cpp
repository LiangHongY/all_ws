#include<iostream>
using namespace std;
#include<set>

//set查找和统计，功能描述：
//对set容器进行查找数据以及统计数据

//函数原型：
//find(key);   //查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end();
//count(key);  //统计key的元素个数

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
	set<int> s;

	s.insert(1);
	s.insert(89);
	s.insert(76);
	s.insert(23);

	printSet(s);

	set<int>::iterator pos = s.find(890);
	if (pos != s.end())
	{
		cout << "找到该数据 " <<*pos<< endl;
	}
	else
	{
		cout << "未找到该数据" << endl;
	}

	//统计元素个数
	int i = s.count(1);

	//对于set容器而言，set统计数据要么是0，要么是1
	cout << "个数为：" << i << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}