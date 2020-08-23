#include<iostream>
using namespace std;
#include<string>

//类对象作为类成员

//手机类
class Phone
{
public:
	Phone(string pName)
	{
		m_PName = pName;
		cout << "Phone构造函数调用" << endl;
	}
	~Phone()
	{
		cout << "Phone析构函数的调用" << endl;
	}
	//手机品牌名称
	string m_PName;
};

//人类
class Person
{
public:
	//初始化列表知识
	//m_PName = pName 隐式转换法
	Person(string name, string pName):m_Name(name),m_Phone(pName)
	{
		cout << "Person构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}

	//姓名
	string m_Name;
	//手机
	Phone m_Phone;
};
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
//如本案例中，手机类是作为人类的一个成员的，所以，先构造Phone
//类再构造Person类

//析构函数执行顺序与构造函数执行顺序相反的，遵循先进后出原则
//案例中，先释放的是Person类再释放Phone类
void test01()
{
	Person p("张三","苹果max");
	cout << p.m_Name << "秀着妈妈新买的" << p.m_Phone.m_PName<<"自拍效果"<< endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
