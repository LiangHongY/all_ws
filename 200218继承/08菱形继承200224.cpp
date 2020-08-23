#include<iostream>
using namespace std;

//动物类

class Animal
{
public:
	int m_Age;
};
//利用虚继承  可以解决菱形继承问题
//继承之前  加上关键字 virtual  变为虚继承
//Animal类称为虚基类

//羊类
class Sheep :virtual public Animal{};

//驼类
class Tuo:virtual public Animal{};

//羊驼类
class SheepTuo:public Sheep,public Tuo{};

void test01()
{
	SheepTuo st;
	st.Tuo::m_Age = 28;
	st.Sheep::m_Age = 18;
	
	//当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age=" << st.Tuo::m_Age << endl;

	cout << "st.m_Age=" << st.m_Age << endl;//这是添加了虚继承关键字virtual后可以使用的

	//年龄这份数据，只有一份就可以了，菱形继承会导致数据有两份，资源浪费
	//指针只是保留最后一次输入的参数值200525
}


int main()
{
	test01();

	system("pause");
	return 0;
}

//在数据结构查询工具里面出现的vbptr指的是一个指针

//总结
//菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
//利用虚继承可以解决菱形继承问题

//个人理解这个虚继承问题，添加了virtual关键字后，Sheep以及Tuo这两个父类都是继承一个虚指针了，
//都是指向同一个东西，然后子类Son继承他们两个父类，然后都是指向同一个东西，所以本质上就是
//指的是同一个东西，从而避免了资源的重复占用带来的浪费。