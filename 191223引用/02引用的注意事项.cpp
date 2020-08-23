#include<iostream>
using namespace std;

int main()
{
	int a=10;
	//1、引用必须初始化
	int &b=a;//如果不写后面时候，会报错的
	//2、引用初始化后，不得更改（指的是该符号只能操作初始化对应的内存区，而不能更改其他的）
	int c=20;
	b=c;//赋值操作，而不是更改  （指的是更改引用），所以不报错
	//&b=c;//这是更改引用操作，系统会报错的
	cout <<"a= "<<a<<endl;//20
	cout <<"b= "<<b<<endl;//20
	cout <<"c= "<<c<<endl;//20
	system("pause");
	return 0;
}