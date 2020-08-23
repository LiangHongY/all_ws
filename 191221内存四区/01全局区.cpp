#include<iostream>
using namespace std;

//全局变量
int g_a=10;
int g_b=10;

//const修饰的全局变量，所以变成了全局常量
const int c_g_a=10;


int main()
{
	//全局区

	//全局变量、静态变量、常量

	//创建普通局部变量
	int a=10;
	int b=10;

	cout<<"局部变量a的地址为： "<<(int)&a<<endl;
	cout<<"局部变量b的地址为： "<<(int)&b<<endl;

	cout<<"全局变量g_a的地址为： "<<(int)&g_a<<endl;
	cout<<"全局变量g_b的地址为： "<<(int)&g_b<<endl;

	//静态变量     在普通变量前加static，属于静态变量
	static int s_a=10;
	static int s_b=10;
	cout<<"静态变量s_a的地址为： "<<(int)&s_a<<endl;
	cout<<"静态变量s_b的地址为： "<<(int)&s_b<<endl;

	//常量
	//字符串常量
	cout<<"字符串常量的地址为：  "<<(int)"hello world"<<endl;
	//const修饰的变量(属于常量范围)
	//const修饰的全局变量，const修饰的局部变量
	cout<<"全局常量c_g_a的地址为：  "<<(int)&c_g_a<<endl;

	const int c_l_a=10;//  常用的命名规则：c-const   g-global   l-local
	const int c_l_b=10;
	cout<<"局部变量c_l_a的地址为： "<<(int)&c_l_a<<endl;
	cout<<"局部变量c_l_b的地址为： "<<(int)&c_l_b<<endl;

	system("pause");
	return 0;
}

//全局区存放的量类型有：   全局变量、静态变量（由static关键字修饰的）、字符串常量、const修饰的全局变量（又称全局常量）

//不在全局区的量类型：局部变量、const修饰的局部变量（又称为局部常量）

//总结：
//c++中在程序运行前分为全局区和代码区
//代码区特点是共享和只读
//全局区存放全局变量、静态变量、常量（不包含局部常量）
//常量区中存放const修饰的全局常量和字符串常量


