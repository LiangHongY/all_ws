#include<iostream>
using namespace std;
#include<string>

//类模板对象做函数参数

template <class T1,class T2>

class Person
{
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名： " << this->m_Name << "  年龄： " << this->m_Age << endl;
	}
	T1 m_Name;
	T2 m_Age;
};

//1、指定传入类型（最常用的）
void printPerson1(Person<string,int>&p)
{
	p.showPerson();
}

void test01()
{
	Person<string, int>p("猴子", 100);
	printPerson1(p);
}

//2、参数模板化
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1类型为： " << typeid(T1).name() << endl;//用来查看类型的代号的表示的类型语句
}
void test02()
{
	Person<string, int>p("老猪", 90);
	printPerson2(p);
}


//3、整个类模板化
template<class T>
void printPerson3(T &p)
{
	p.showPerson();//为什么都没有找到该函数定义却可以正常输出呢？200510 //这里该函数是上面类里面一个成员函数，所以是已经定义的了200604
	cout << "T的类型  " << typeid(T).name() << endl;
}
void test03()
{
	Person<string, int>p("和尚", 30);
	printPerson3(p);
}


int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
//总结：
//1、指定传入的类型，直接显示对象的数据类型
//2、参数模板化，将对象中的参数变为模板进行传递
//3、整个类模板化，将这个对象类型模板化进行传递

//通过类模板创建的对象，可以有三种方式向函数中进行传参
//使用比较广泛的是第一种：指定类型传入的方式