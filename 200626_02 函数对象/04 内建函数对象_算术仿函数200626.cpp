//内建函数对象意义

//概念：
//STL内建了一些函数对象

//分类：
//算术仿函数
//关系仿函数
//逻辑仿函数

//用法：
//这些仿函数所产生的对象，用法和一般函数完全相同
//使用内建函数对象，需要引用头文件   #include<functional>



#include<iostream>
#include<functional>
using namespace std;

//算术仿函数，功能描述：
//实现四则运算
//其中negate是一元运算，其他都是二元运算

//仿函数原型：
//template<class T> T plus<T>       //加法仿函数
//template<class T> T minus<T>      //减法仿函数
//template<class T> T multiplies<T>  //乘法仿函数

//template<class T> T divides<T>     //除法仿函数
//template<class T> T modulus<T>     //取模仿函数
//template<class T> T negate<T>      //取反仿函数


//内建函数对象   算术仿函数


//negate 一元仿函数   取反仿函数
void test01()
{
	negate<int>n;
	cout << n(50) << endl;
}


//plus 二元仿函数      加法
void test02()
{
	plus<int>p;     //该函数默认取的是同类型的数据，并且不是自定义类型的

	cout << p(10, 2) << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

//总结：使用内建函数对象时，需要引用头文件    #include<functional>
