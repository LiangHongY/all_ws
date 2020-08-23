#include<iostream>
using namespace std;

//空指针调用成员函数

class Person
{
public:
	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		//1.报错原因是因为传入的指针为NULL

		//2.解决方式是：添加如下if语句

		if (this == NULL)
		{
			return;
		}


		cout << "age= "<<this->m_Age<<endl;
	}
	int m_Age;
};

void test01()
{
	Person* p = NULL;
	
	p->showClassName();

	p->showPersonAge();
}

int main()
{
	test01();

	system("pause");
	return 0;
}