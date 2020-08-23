//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}

//多态是C++面向对象三大特性之一
//多态分为两类
//静态多态：函数重载和运算符重载属于静态多态，复用函数名
//动态多态，派生类和虚函数实现运行时多态

//静态多态和动态多态区别
//静态多态的函数地址早绑定，编译阶段确定函数地址
//动态多态的函数地址晚绑定，运行阶段确定函数地址


#include<iostream>
using namespace std;

//多态

//动物类
class Animal
{
public:
	//晚绑定操作，添加virtual
	//虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

//猫类
class Cat :public Animal
{
public:
	//重写  指的是  函数返回值类型   函数名  参数列表   完全相同
	//重写时，父类中virtual关键字必须写，子类中可写可不写
	//当子类中重写父类中虚函数时，子类中的虚函数  列表内部(原来是父类的)会
	//替换成子类虚函数地址
	virtual void speak()
	{
		cout << "小猫在说话" << endl;

	}
};

//狗类
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;

	}
};

//执行说话函数
//地址早绑定，在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定；需要在运行阶段进行绑定，
//也就是地址晚绑定

//动态多态满足条件
//1、有继承关系
//2、子类要重写父类虚函数

//动态多态使用
//父类的指针或者引用 指向子类对象

void doSpeak(Animal& animal)//Animal &animal=cat;
{
	animal.speak();//产生多态
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test02()
{
	cout << "sizeof Animal=" << sizeof(Animal) << endl;
}

int main()
{
	//test01();//在未进行晚绑定操作时候，输出的是  动物在说话
	test02();
	system("pause");
	return 0;
}