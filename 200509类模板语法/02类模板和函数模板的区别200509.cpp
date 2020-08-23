#include<iostream>
using namespace std;
#include<string>

//类模板和函数模板区别
template<class NameType, class AgeType=int>//6,7行不能隔行写，否则报错。         但是01 就是隔行写的，正常运行。所以可以认为这说法是错误的。200630
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名： " << this->m_Name << endl;
		cout << "年龄： " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

//1、类模板没有自动推导类型
void test01()
{
	//Person p1("猴子",999)；//报错，类模板没有自动推导类型功能
	Person<string,int>p("猴子", 999);//正确，只能指定类型
	p.showPerson();
}
//2、类模板在模板参数列表中可以有默认参数
void test02()
{
	Person<string>p1("老猪", 990);//这里不报错是因为，模板里面年龄类型默认为int类型了
	p1.showPerson();
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
//总结
//类模板使用只能用显示指定类型方式
//类模板中的模板参数列表可以有默认参数