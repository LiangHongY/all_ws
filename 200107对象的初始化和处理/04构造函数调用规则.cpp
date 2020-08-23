#include<iostream>
using namespace std;

//构造函数调用规则
//在默认情况下，C++编译器至少给一个类添加三个函数
//1、默认构造函数（无参，函数体为空）
//2、默认析构函数（无参，函数体为空）
//3、默认拷贝构造函数，对属性值进行拷贝

//构造函数调用规则如下：
//如果用户定义有参构造函数，C++不再提供默认无参构造，
//但是会提供默认拷贝构造
//如果用户定义拷贝构造函数，C++不再提供其他构造函数

//构造函数调用规则
//1.创建一个类，C++编译器会给每一个类添加至少3各函数
//默认构造（空实现）
//析构函数（空实现）
//拷贝构造（值拷贝）

//2.如果我们写了有参构造函数，编译器就不再提供默认构造，
//依然提供拷贝构造
//如果我们只写了拷贝构造函数，编译器就不再提供其他普通构造函数了

class Person
{
public:
	//Person()
	//{
	//	cout << "Person的默认构造函数调用" << endl;
	//}

	Person(int age)
	{
		cout << "Person的有参构造函数调用" << endl;
		m_Age = age;
	}

	//Person(const Person & p)
	//{
	//	cout << "Person的有参拷贝构造函数调用" << endl;
	//	m_Age = p.m_Age;
	//}

	//结论就是，如果采用默认的构造函数，编译器会提供有参构造
	//函数以及有参拷贝构造函数；如果我们提供了有参构造函数，
	//编译器只会提供有参拷贝构造函数；如果我们提供了有参拷贝
	//构造函数，编译器则不会提供任何构造函数。

	~Person()
	{
		cout << "Pereon的析构函数调用" << endl;
	}
	int m_Age;
};

//void test01()
//{
//	Person p;
//	p.m_Age = 18;
//	Person p2(p);
//
//	cout << "p2的年龄为为多少   "<<p2.m_Age<<endl;
//}

void test02()
{
	Person p(28);
	Person p2(p);
	
	cout << "p2的年龄为   "<<p2.m_Age<<endl;
}


int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}

