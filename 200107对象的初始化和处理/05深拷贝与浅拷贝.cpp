#include<iostream>
using namespace std;

//深拷贝与浅拷贝

class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age,int height)
	{
		m_Age = age;
		m_Height=new int(height);//自己手动开辟的内存，需
		//要在析构函数里面手动释放
		cout << "Person的有参构造函数调用" << endl;
	}

	//自己实现拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "Person拷贝函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;//编译器默认实现就是这行代码

		//深拷贝操作
		m_Height = new int(*p.m_Height);
	}

	~Person()
	{
		//下面析构代码，将自己手动在堆区开辟数据做释放操作
		if (m_Height!=NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}
	int m_Age;//年龄
	int* m_Height;//身高
};

void test01()
{
	Person p1(18,160);
	cout << "p1的年龄为：  " << p1.m_Age<<"  p1身高为多少：  "<<*p1.m_Height << endl;

	Person p2(p1);//如果利用编译器提供的拷贝函数，只是做浅拷
	//贝操作,也就是复制操作；
	cout << "p2的年龄为：  " << p2.m_Age << "  p2身高为多少：  " << *p2.m_Height << endl;
}

//浅拷贝带来的问题就是，堆区的内存重复释放导致错误
//解决方式是，利用深拷贝进行解决
int main()
{
	test01();

	system("pause");
	return 0;
}
//浅拷贝，就是系统提供的赋值拷贝操作，拷贝前后内存空间不变；深
//拷贝,就是相当于在堆区申请一块内存，进行拷贝操作,
//拷贝前后的内存空间不同；

//这个例子里面，如果进行深拷贝操作的话，p1和p2进行两个的相同
//内存空间的释放操作，会导致报错的，因为拷贝前后的指针所指向
//的内存地址是相同的，那么就会导致析构函数对两者的释放操作时
//候会导致重复释放问题；所以采用深度拷贝操作，就是将拷贝前后
//指针指向的内存地址不同，然后，释放也是避免重复释放这个问题
//的。