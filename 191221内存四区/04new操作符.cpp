//c++中利用new操作符在堆区开辟数据
//堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
//语法： new  数据类型
//利用new创建数据，会返回数据对应的类型的指针


#include<iostream>
using namespace std;

//1、new的基本语法
int * func()
{
	//在堆区创建整型数据
	//new返回的是   该数据类型的指针
	int *p=new int(10);//因为创建的是整型数据10，所以采用一个整型指针来接收
	return p;
}

void test01()
{
	int *p=func();
	cout <<*p<<endl;
	cout <<*p<<endl;
	cout <<*p<<endl;
	//多次测试，发现输出结果不变
	//堆区的数据，由程序员管理开辟，程序员管理释放
	//如果想释放堆区的数据，利用关键字delete
	delete p;
	//cout <<*p<<endl;//内存已经释放，再次访问就是非法操作，是会报错的
}

//2、在堆区利用new开辟数组
void test02()
{
	//创建10个整型数据的数组，在堆区
	int * arr=new int [10];//10代表数组有10个元素，里面的arr后面不能写中括号，写了会报错
	for(int i=0;i<10;i++)
	{
		arr[i]=i+100;
	}
	for(int i=0;i<10;i++)
	{
		cout <<arr[i]<<endl;
	}
	delete [] arr;//加  []  表示释放的是数组，如果进行输出操作会输出一系列随机内存地址，但是还没报语法上面错误。
	//delete [] arr;//加  []  表示释放的是数组,在这里重复一次系统直接报语法错误
	//	for(int i=0;i<10;i++)
	//{
	//	cout <<arr[i]<<endl;
	//}
}



int main()
{
	//test01();
	test02();


	system("pause");
	return 0;
}