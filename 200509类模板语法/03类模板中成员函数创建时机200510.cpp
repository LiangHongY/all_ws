#include<iostream>
using namespace std;

//类模板中成员函数创建时机
//类模板中成员函数在调用时采取创建

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template <class T>
class MyClass
{
public:
	T obj;

	//类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成的
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

void test01()
{
	MyClass<Person1>m;
	m.func1();
	//m.func2();//编译会出错，说明函数调用时才会创建成员函数
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：类模板中的成员函数并不是一开始就创建的，在调用时才去创建的