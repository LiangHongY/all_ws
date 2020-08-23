#include<iostream>
using namespace std;

//string字符串插入和删除
//功能描述
//对string字符串进行插入和删除字符串操作

//函数原型：
//string& insert(int pos,const char* s);  //插入字符串
//string& insert(int pos,const string& str);//插入字符串
//string& insert(int pos,int n,char c);  //在指定位置插入n个字符c
//string& erase(int pos,int n=npos);  //删除pos开始的n个字符

//字符串的  插入和删除

void test01()
{
	string str = "hello";

	//插入
	//str.insert(1, "222");
	//cout << "str= " << str << endl;

	//str.insert(1, str);
	//cout << "str= " << str << endl;

	str.insert(1, 3,'2');
	cout << "str= " << str << endl;

	//删除
	str.erase(1, 3);
	cout << "str= " << str << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//总结：
//插入和删除的起始下标都是从0开始