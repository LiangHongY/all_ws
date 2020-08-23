#include<iostream>
#include<string>
using namespace std;

//访问权限
//公共权限   public            成员     类内可以访问，类外可以访问
//保护权限   protected     成员    类内可以访问，类外不可以访问     ；继承上：儿子可以访问父亲中保护的内容
//私有权限   private           成员    类内可以访问，类外不可以访问     ；继承上：儿子不可以访问父亲的私有内容

class Person
{
public:
	//公共权限
	string m_Name;
protected:
	//保护权限
	string m_car;
private:
	//私有权限
	int m_Password;//银行密码
public:
	void func()
	{
		m_Name="张三";
		m_car="拖拉机";
		m_Password=123456;//这三个属于类内访问
	}
};

int main()
{
	Person p1;
	//类外访问属性

	p1.m_Name="李四";
	//p1.m_car="奔驰";//会报错，由于保护权限内容，在类外访问不到的
	//p1.m_Password=123;//会报错，由于私有权限内容，类外访问不了的
	p1.func();//公共权限，类外可以访问

	system("pause");
	return 0;
}