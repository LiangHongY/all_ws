#include<iostream>
using namespace std;

#include<string>

//string子串
//功能描述：
//从字符串中获取想要的子串

//函数原型：
//string substr(int pos=0,int n=npos) const;//返回由pos开始的n个字符组成的字符串

//string 求子串

void test01()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);
	cout << "subStr= " << subStr << endl;
}

//实用操作
void test02()
{
	string email = "zhangsan@sina.com";

	//从邮箱地址中获取用户信息

	int pos = email.find("@");

	string userName = email.substr(0, pos);
	cout << "用户信息：" << userName << endl;
}

int main()
{
	test01();

	test02();
	system("pause");
	return 0;
}
//总结：灵活的运用求子串功能，可以在实际开发中获取有效的信息