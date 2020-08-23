#include<iostream>
using namespace std;

#include<string>

//string中单个字符存取方式有两种

//char& operator[](int n); //通过[]方式获取字符
//char& at(int n);   //通过at方式获取字符

//string 字符存取

void test01()
{
	string str = "hello";

	//cout << "str= " << str << endl;

	//逐个字符输出方式

	//1、通过[]访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	//2、通过at方式访单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//修改单个字符
	str[0] = 'x';
	cout << "[]str= " << str << endl;

	str.at(0) = 'k';
	cout << "at str= " << str << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：string字符串中单个字符串存取（读和写）有两种方式，利用[]或at