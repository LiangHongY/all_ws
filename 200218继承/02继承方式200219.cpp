#include<iostream>
using namespace std;

//继承语法：class 子类 ： 继承方式 父类

//继承方式：公共继承、保护继承、私有继承

//解释：首先，父类中有  public  a  ；protected  b  ；private  c
//公共继承：  子类：  public  a   ；protected  b
//保护继承：  子类：  protected  a； protected  b
//私有继承：  子类：  private    a；private   b

//继承方式

//公共继承
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//不报错表示，父类中的公共权限成员，到子类中依然是公共权限
		m_B = 10;//不报错，表示父类中保护权限成员，到子类中依然是保护权限
		//m_C = 10;//报错，表示父类中的私有权限成员，子类是访问不了的
	}
};

void test01()
{
	Son1 s1;
	s1.m_A = 100;//不报错表示公共权限成员类外也可以访问
	//s1.m_B = 100;//报错，表示保护权限在类外不可以访问
}

//保护继承
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100;//父类中公共成员，到子类中变为保护权限
		m_B = 100;//父类中保护成员，到子类中也是保护权限
		//m_C = 100;//报错，子类无访问权限
	}
};

void test02()
{
	Son2 s1;
	//s1.m_A = 100;//报错，在Son2中m_A为保护权限，因此类外访问不到的
	//s1.m_B = 100;//报错，在Son2中m_B为保护权限，不可访问
}

//私有继承
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 100;//父类中公共成员，到子类中变为私有权限
		m_B = 100;//父类中保护成员，到子类中也是私有权限
		//m_C = 100;//报错，子类无访问权限
	}
};

void test03()
{
	Son3 s1;
	//s1.m_A = 100;//报错，在Son2中m_A为私有权限，因此类外访问不到的
	//s1.m_B = 100;//报错，在Son2中m_B为私有权限，类外不可访问
}

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 100;//父类中私有成员，子类无权访问
		//m_B = 100;//父类中私有成员，子类无权访问
	}
};

int main()
{

	system("pause");
	return 0;
}