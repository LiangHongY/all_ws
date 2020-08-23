#include<iostream>
using namespace std;

//导入：
//当类模板碰到继承时，需要注意以下几点
//当子类继承的父类是一个类模板时，子类在声明的时候，需要指定出父类中T的类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定父类T的类型，子类也需要变为类模板

//类模板与继承

template<class T>
class Base
{
public:
	T m;
};

//class Son :public Base//错误的，必须知道父类中的T的类型，才能继承给子类
class Son:public Base<int>//指定了类型就可以正常继承了
{

};

void test01()
{
	Son s1;
}

//如果想灵活指定父类中T类型，子类也需要变为类模板
template<class T1,class T2>//T2是传给父类的，T1是传给子类的
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1的数据类型为：" << typeid(T1).name() << endl;
		cout << "T2的数据类型为：" << typeid(T2).name() << endl;
	}
	T1 obj;
};

void test02()
{
	Son2<int, char>s2;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//总结
//如果父类是一个类模板，子类需要指定父类中T的数据类型