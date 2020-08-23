//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	system("pause");
//	return 0;
//}



#include<iostream>

using namespace std;

//引用做函数的返回值
//1、不要返回局部变量的引用
int & test01()
{
	int a=10;//局部变量存储在四区中的   栈区（操作完成就会释放，而非程序结束释放）
	return a;
}

//2、函数的调用可以作为左值
int & test02()
{
	static int a=10;//静态变量，存放在全局区，程序结束后，由系统释放
	return a;
}

int main()
{
	int &ref=test01();
	cout<<"ref="<<ref<<endl;//第一次结果正确，是因为编译器做了保留
	cout<<"ref="<<ref<<endl;//第二次错误，因为内存已经释放

	int &ref2=test02();
	cout<<"ref2="<<ref2<<endl;
	cout<<"ref2="<<ref2<<endl;

	test02()=1000;//如果函数的返回值是  引用，这个函数调用作为左值
	cout<<"ref2="<<ref2<<endl;//1000//ref2就是a的别名 
	cout<<"ref2="<<ref2<<endl;//1000
	system("pause");
	return 0;
}