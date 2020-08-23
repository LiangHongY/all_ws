//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
//运算符重载概念：对已有的运算符重新进行定义，赋予另一种功能，以适应不同的数据类型

//加号运算符重载作用：实现两个自定义数据类型相加的运算

//加号运算符重载
class Person
{
public:

	////1.成员函数重载  +  号
	//Person operator+(Person& p)
	//{
	//	Person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}


	int m_A;
	int m_B;
};

//2.全局函数重载  +  号
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

//函数重载的版本
Person operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}


void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;

	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//下面的代码成员函数重载本质是：Person p3=p1.operator+(p2);
	//下面的代码全局函数重载本质是：Person p3=operator+(p1,p2);
	Person p3 = p1 + p2;
	//运算符重载，也可以发生函数重载
	Person p4 = p1 + 10;//Person+int

	cout << "p3.m_A= " << p3.m_A << "  p3.m_B= " << p3.m_B << endl;

	cout << "p4.m_A= " << p4.m_A << "  p4.m_B= " << p4.m_B << endl;


}
//1.成员函数重载  +  号


int main()
{
	test01();


	system("pause");
	return 0;
}

//注意点
//对于内置的数据类型的表达式的运算符是不可能改变的。指的是重载类型函数的+号在调用时不能更改
//不要滥用运算符重载。重载函数标题写了 + 号，而里面却是 - 号，着就是滥用

//个人感觉，这个加号运算符重载产生意义在于对于类的成员的＋属性的服务的。