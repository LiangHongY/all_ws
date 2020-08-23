#include<iostream>
#include<map>
using namespace std;

//map大小和交换，功能描述：
//统计map容器大小以及交换map容器

//函数原型：
//size();      //返回容器中元素的数目
//empty();     //判断容器是否为空
//swap();      //交换两个集合容器

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "   " << it->second << endl;
	}
	cout << endl;
}


void test01()
{
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 40));
	m.insert(pair<int, int>(9, 30));

	printMap(m);

	//判断容器是否为空
	if (m.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		//返回容器数目
		//int i = m.size();
		cout << "容器不为空,大小为：" << m.size()<< endl;
		
	}


	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(7, 90));

	cout << "交换前：" << endl;
	printMap(m);
	printMap(m1);

	cout << "交换后： " << endl;
	m1.swap(m);
	printMap(m);
	printMap(m1);
	

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：
//统计大小   --size
//判断是否为空  --empty
//交换容器     --swap