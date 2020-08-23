#include<iostream>
using namespace std;
#include<string>

//功能描述：
//查找：查找指定字符串是否存在
//替换：在指定的位置替换字符串

//函数原型
//int find(const string& str,int pos=0)const   //查找str第一次出现位置，从pos开始查找
//int find(const char* s,int pos=0)const;   //查找s第一次出现位置，从pos开始查找
//int find(const char* s,int pos,int n) const;//从pos位置查找s的前n的字符串第一次位置

//int find(const char c,int pos=0)const;  //查找字符c第一出线位置
//int rfind(const string& str,int pos=npos)const;//查找str最后一次位置，从pos开始查找
//int rfind(const char* s,int pos=npos)const;//查找s最后一次出现位置，从pos开始查找

//int rfind(const char*s,int pos,int n)const;//从pos查找s的前n个字符串最后一次位置
//int rfind(const char c,int pos=0)const;//查找字符c最后一次出现位置
//string& replace(int pos,int n,const string& str);//替换从pos开始n的字符为字符串str
//string& replace(int pos,int n,const char* s);//替换从pos开始的n个字符为字符串s

//字符串查找和替换

//1、查找
void test01()
{
	string str1 = "abckdefgke";
	int pos = str1.find("k");

	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串,pos= " << pos << endl;
	}
	//cout << "pos= " << pos << endl;//这里表示的d所在位置，因为是从0开始标记的

	//rfind和find的区别
	//rfind从右往左查找  ； find从左往右查找

	//查到就会pos就会返回位置

	pos=str1.rfind("k");
	cout << "rfind的pos= " << pos << endl;//从右往左查找时候，返回的还是本身的存储位置
	                       //存储位置时从左往右从0开始编号

}

//2、替换
void test02()
{
	string str1 = "abcdefg";

	//从1号位置起3个字符串，替换为“1111”
	str1.replace(1, 3, "1111");
	cout << "str1= " << str1 << endl;
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
//总结：find查找的是从左往右，rfing从右往左
//find找到字符串后返回查找的第一个字符串位置，找不到就返回-1
//replace在替换时，要指定从哪个位置开始，多少个字符，替换成什么样子的字符串