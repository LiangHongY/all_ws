#include<iostream>

using namespace std;

//堆区
//由程序员分配、释放，若程序员不释放，程序结束后由操作系统回收
//在c++里面主要利用new在堆区开辟内存

int * func()
{
	//利用new关键字，可以将数据开辟到堆区
	//指针  本质也是局部变量，放在栈上，指针保存的数据是放在堆区
	int * p=new int(10);//这里理解是，在堆区创建一个内存保存10，然后，把该堆区的该内存给了指针*p，而*p保存在栈区，栈区数据编译器控制
	return p;
}

int main()
{
	//在堆区开辟数据
	int *p=func();
	cout <<*p<<endl;
	cout <<*p<<endl;
	cout <<*p<<endl;

	system("pause");
	return 0;
}

//总结：
//堆区数据由程序员管理开辟和释放
//堆区数据利用new进行开辟内存的