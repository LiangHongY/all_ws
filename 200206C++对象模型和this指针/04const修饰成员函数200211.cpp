#include<iostream>
using namespace std;

//常函数
class Person
{
public:

	//this指针的本质是指针常量，指针的指向不可修改
	//形式如：Person * const this;
	//在成员函数后面加const，修饰的是this指向，让指针指向
	//的值不可以修改
	void showPerson()const//加了const导致下面的值不可修改
	{
		this->m_B = 100;//因为这里属于特殊变量，所以不报错
		
		//this->m_A = 100;

		//this = NULL;//this指针不可修改指针的指向的
	}

	void func()
	{

	}

	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值
};
void test01()
{
	Person p;
	p.showPerson();
}

//常对象
void test02()
{
	const Person p;//在对象前加const，变为常对象
	//p.m_A = 100;//m_A不是特殊值，所以在有const修改时不可以修改
	
	p.m_B = 100;//m_B是特殊值，在常对象也可以修改

	//常对象只能调用常函数
	p.showPerson();
	//p.func();//这里是个对比例子，说明上面的结论：
	//常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
}



int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}

//概要：
//常函数
//成员函数加const后，我们称这个函数为常函数
//常函数内不可以修改成员属性
//成员属性声明时加关键字mutable，在常函数中依然可以修改

//常对象：
//声明对象前加const称对象为常对象
//常对象只能调用常函数
