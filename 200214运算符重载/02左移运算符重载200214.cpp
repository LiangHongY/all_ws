#include<iostream>
using namespace std;

//左移运算符重载

class Person
{
	friend ostream& operator<<(ostream& cout, Person &p);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:

	//利用成员函数重载  左移运算符  p.operator<<(cout)  简化版本 p<< cout
	//不会利用成员函数重载<<运算符，因为无法实现  cout 在左侧
	//void operator<<(cout)
	//{

	//}

	int m_A;
	int m_B;
};

//只能利用全局函数重载左移运算符
//void operator<<(ostream &cout, Person p)//本质  operator<<(cout,p)  简化  cout<<p
ostream & operator<<(ostream& cout, Person &p)//本质  operator<<(cout,p)  简化  cout<<p
{
	cout << "m_A=" << p.m_A << "  m_B=" << p.m_B;
	return cout;
}

void test01()
{
	Person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;

	cout << p <<"why"<<endl;//后面不能写  <<endl  ,否则会报错，解决方式是把将void修改为ostream,并增加return cout
}

int main()
{
	test01();

	system("pause");
	return 0;
}

//左移运算符重载重点是说怎么输出p，就把p的类内成员属性都输出来