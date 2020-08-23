#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		//this指针指向的是被调用的成员函数所属的对象
		this->age = age;
	}

	Person& PersonAddAge(Person& p)//&表示的是
		//引用的方式返回，一直保持的是p2
		//如果采用的是没有&，会创建新的对象，返回的是非p2了
	{
		this->age += p.age;

		//this指向p2的指针，而*this指向的就是p2这个对象本体
		return *this;//这里星号报错原因是，前面返回类型不应该为void
	}

	int age;
};


//1、解决名称冲突
void test01()
{
	Person p1(18);
	cout << "p1的年龄为：  " << p1.age << endl;
}

//2、返回对象本身用*this

void test02()
{
	Person p1(10);

	Person p2(10);


	//链式编程思想
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "p2的年龄为多少：  " << p2.age << endl;
}

int main()
{
	//test01();

	test02();

	system("pause");
	return 0;
}