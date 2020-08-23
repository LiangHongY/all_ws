#include<iostream>
using namespace std;
#include<string>

//模板的局限性
//模板并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

//对比两个数据是否相等
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//利用具体会Person的版本实现代码，具体化优先调用(就是上面函数重载，不过要具体化）
template<> bool myCompare(Person& a, Person& b)//这是一个针对特定类型的模板函数处理语法方式
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);

	if (ret)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	bool ret = myCompare(p1, p2);//直接引用（没写35具体化时，系统选择的是22定义的），
	                        //不会报语法错误，但是，运行出错，因为类型上面出错了

	if (ret)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}
	
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
//总结
//利用具体化的模板，可以解决自定义类型的通用化
//学习模板并不是为了写模板，而是在stl能够运用系统提供的模板