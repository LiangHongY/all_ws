#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>

//案例描述：实现一个通用的数组类，要求如下：
//可以对内置数据类以及自定义数据类型的数据进行存储
//将数组中的数据存储到堆区
//构造函数中可以传入数组的容量
//提供对应的拷贝构造函数以及operator=防止浅拷贝问题    貌似这里面并没有深拷贝案例--200702
//提供尾插法和尾删法对数据进行增加和删除
//可以通过下标方式访问数组中的元素
//可以获取数组中当前元素的容量

void printInArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i]<<endl;//由于重载了所以可以直接访问该数组
	}
}

void test01()
{
	MyArray<int>arr1(5);

	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.Push_back(i);
	}
	cout << "arr1的打印输出为：" << endl;
	printInArray(arr1);

	cout << "arr1的容量：" << arr1.getCapacity() << endl;
	cout << "arr1的大小：" << arr1.getSize() << endl;

	MyArray<int>arr2(arr1);
	cout << "arr2的打印输出为：" << endl;
	printInArray(arr2);

	//尾删
	arr2.Pop_Back();
	cout << "arr2尾删后：" << endl;
	cout << "arr2的容量：" << arr2.getCapacity() << endl;
	cout << "arr2的大小：" << arr2.getSize() << endl;

	

	//上节课测试
	//MyArray<int>arr2(arr1);
	//MyArray<int>arr3(100);
	//arr3 = arr1;


}//总结：17节的拷贝构造啥的不明白，主要是为啥两处有深拷贝操作不懂，需要反复看200510


//测试自定义数据类型
class Person
{
public:
	Person() {};//这到底什么原理呢？200511  这是默认构造，但是可以起到什么作用？200512
	Person(string name, int age)//有参构造
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名： " << arr[i].m_Name << " 年龄：" << arr[i].m_Age << endl;
	}
}//这段代码需要放在class Person类后面才行，否则编译器找不到Person这个元素，直接报一大堆语法错误


void test02()
{
	MyArray<Person>arr(10);
	Person p1("猴子", 999);
	Person p2("韩信", 30);
	Person p3("妲己", 20);
	Person p4("赵云", 25);
	Person p5("安琪拉", 23);

	//将数据插入数组中
	arr.Push_back(p1);
	arr.Push_back(p2);
	arr.Push_back(p3);
	arr.Push_back(p4);
	arr.Push_back(p5);

	//打印数组
	printPersonArray(arr);
	cout << "arr的容量：" << arr.getCapacity() << endl;
	cout << "arr的大小：" << arr.getSize() << endl;


}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//这个案例也出现了深拷贝开辟堆区数据时，如this->pAddress[i] = arr.pAddress[i];语句，会提示
//数据溢出的警告。虽然可以正常运行，但是，这个问题目前还没找到解决方式。200511
//重载知识点、类模板知识点都没有没有过关。
//这个案例深拷贝在哪里？？？？ 200701