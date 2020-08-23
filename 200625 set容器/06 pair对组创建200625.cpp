#include<iostream>
using namespace std;
#include<string>

//pair对组创建，功能描述：
//成对出现的数据，利用对组可以返回两个数据

//两种创建方式：
//pair<type,type> p (value1,value2);
//pair<type,type> p = make_pair(value1,value2);

//pair对组的创建
void test01()
{
	//第一种方式
	pair<string, int> p("TOM",33);

	cout << "姓名：" << p.first << "  年龄：" << p.second << endl;

	//第二种方式
	pair<string, int> p1=make_pair("Li型", 99);//方便记忆
	cout << " 姓名：" << p1.first << " 年龄：" << p1.second << endl;
}


int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：两种都可以创建对组，记住一种即可