#include<iostream>
using namespace std;

//第一种解决方式，直接包含源文件
//#include"person.cpp"

//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀名改写为.hpp文件（声明和实现放在同一文件中）
#include"person.hpp"//.hpp表示的是一个分文件处理的类模板，不必须这么命名，但是是约定俗成

//导入
//目标：掌握类模板成员函数分文件编写产生的问题以及解决方式

//问题：类模板中成员函数创建时机实在调用阶段，导致分文件编写时链接不到
//解决：
//解决方式1：直接包含.cpp源文件
//解决方式2：将声明和实现写到同一个文件中，并更改后缀名为.hpp，hpp是约定的名称，并不是强制的

//开始
//类模板分文件编写问题以及解决
//#include<string>
//template<class T1,class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};
//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1,T2>::showPerson()
//{
//	cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
//}

void test01()
{
	Person<string, int>p("Tom", 19);
	p.showPerson();//如果头文件是person.h,那么编译器会报错；修改为person.cpp就可以正常输出了
	               //原因是，写person.h时，编译器并不会编译person.cpp文件两函数，导致无法找
	               //该函数而导致无法解析；如果直接写person.cpp,编译器直接编译该文件，可以
	               //找到这些函数，进行编译
}
int main()
{
	test01();
	system("pause");
	return 0;
}

//总结：方式二的特点就是声明和定义都写到同一个文件中。当前解决类模板分文件编写产生问题
//采用的方式是第二种，将类模板成员函数写在一起，并将后缀名改为.hpp