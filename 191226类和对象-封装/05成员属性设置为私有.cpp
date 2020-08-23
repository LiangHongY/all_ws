#include<iostream>
#include<string>
using namespace std;
//成员属性设置为私有
//1、可以自己控制读写权限
//2、对于写可以检测数据的有效性

//设计人类
class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name=name;
	}

	//获取姓名
	string getName()
	{
		return m_Name;
	}
	//获取年龄，只读
	int getAge()
	{
		//m_Age=0;//初始化为0
		return m_Age;
	}
	void setAge(int age)
	{
		if(age<0||age>150)
		{
			m_Age=0;
			cout<<"输入有误"<<endl;
			return;
		}
		else
		m_Age=age;
	}

	//设计情人，只写
	void setLover(string lover)
	{
		m_Lover=lover;
	}

private:
	//姓名   可读可写
	string m_Name;
	//年龄   只读（可写）  如果想修改年龄，年龄范围必须是0到150之间
	int m_Age;
	//情人   只写
	string m_Lover;

};

int main()
{
	Person p;
	p.setName("张三");

	cout<<"姓名为：  "<<p.getName()<<endl;

	//p.m_Age=18;
	p.setAge(18);//这两种方式设计年龄都是错的，因为没有定义到?//为啥我测试可以输出18的？200515
	cout<<"年龄为：  "<<p.getAge()<<endl;

	//设置情人为苍井
	p.setLover("苍井");
	//设置姓名
	p.setAge(1000);
	system("pause");
	return 0;
}
