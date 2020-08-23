#include<iostream>
using namespace std;
#include<string>

//类模板成员函数类外实现
template<class T1,class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	//{
	//	this->m_Name = name;
	//	this->m_Age = age;
	//}

	void showPerson();
	//{
	//	cout << "姓名是：" << this->m_Name << "  年龄：  " << this->m_Age << endl;
	//}

	T1 m_Name;
	T2 m_Age;
};

//构造函数的类外实现
template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age)//作用域处需要给出模板的参数列表T1，T2写进去
{
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数的类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名是：" << this->m_Name << "  年龄：  " << this->m_Age << endl;
}

void test01()
{
	Person<string, int>p("猴子", 18);
	p.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//类模板中成员函数类外实现时，需要加上模板参数列表