#include<iostream>
using namespace std;

//重载递增运算符

//自定义整型
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符,返回引用（指的是17行的&）为了一直对同一个数据进行递增操作

	MyInteger& operator++()
	{
		//先进行++运算
		m_Num++;

		//再做自身返回
		return *this;
	}

	//重载后置++运算符
	//void operator++(int)  int表示占位参数，可以用于区分前置和后置递增
	MyInteger operator++(int)//注意这里没有加 & 号，表示返回的是值而非引用
	{
		//先记录当时结果
		MyInteger temp = *this;
		//后递增
		m_Num++;
		//最后记录结果做返回
		return temp;

	}


private:
	int m_Num;
};

//重载 << 运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}

void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test02()
{
	MyInteger myint;
	cout << (myint++)++ << endl;//这里这写两次++是没有意义的，因为上面采用的是值返回，不是对
	//同一个myint进行操作的，相当于每次myint传进去重置为原始的0了。
	cout << myint << endl;
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
//小结：前置递增返回的是引用，后置递增返回值