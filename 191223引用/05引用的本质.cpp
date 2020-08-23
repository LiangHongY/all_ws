#include<iostream>

using namespace std;

//发现，引用，可以转化为 int* const ref=&a;
void func(int& ref)
{
	ref=100;//ref是引用，转换为*ref=100
}

int main()
{
	int a=10;

	//自动转化为int* const ref =&a；指针常量是指向不可更改，（引用的本质是指针常量），也就是说明引用不可更改原因
	int& ref=a;
	ref=20;//内部发现ref是引用，编译器自动帮我们转换为*ref=20；

	cout<<"a="<<a<<endl;//20
	cout<<"ref="<<ref<<endl;//20

	func(a);
	cout << "a=" << a << endl;//100
	system("pause");
	return 0;
}

//引用的本质就是指针常量（指向不可变）