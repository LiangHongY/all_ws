#include<iostream>
using namespace std;

//构造函数分类
//按参数分：有参构造和无参构造
//按类型分：普通构造和拷贝构造

//三种调用方式
//括号法；显示法；隐式转换法


//1.构造函数的分类及调用
//分类
class Person
{
public:
	//构造函数
	Person()//无参构造又称默认构造函数
	{
		cout<<"Person的无参构造函数调用"<<endl;
	}
	Person(int a)//有参构造
	{
		age=a;
		cout<<"Person的有参构造函数调用"<<endl;
	}
	//拷贝构造函数
		Person (const Person &p)//注意语法规范
	{
		//将传入的人身上所有属性复制到到新人身上
		age=p.age;
		cout<<"Person的拷贝构造函数调用"<<endl;
	}
	//析构函数
	~Person()
	{
		cout<<"Person的析构函数调用"<<endl;
	}
	int age;
};

//调用
void test01()
{
	//括号法
 //   Person p1;//默认构造函数调用(如果上面没写public的话，这里p会报错说重定义)
	//Person p2(10);//有参构造函数调用
	//Person p3(p2);//拷贝构造函数调用

	//注意事项
	//调用默认构造函数时，不要加（）
	//加了括号的话，下面这行代码，编译器认为是一个函数的声明,而不会认为在创建对象如：void func();
	/*Person p1();*/

	//cout<<"p2的年龄："<<p2.age<<endl;
	//cout<<"p3的年龄："<<p3.age<<endl;

	//显示法
	//Person p1;
	//Person p2=Person(10);//有参构造
	//Person p3=Person(p2);//拷贝构造

	//Person(10);//匿名对象    特点：当前行执行结束后，系统会立即回收掉匿名对象
	//cout<<"aaa"<<endl;

	//注意事项2，
	//不要利用拷贝构造函数，初始化匿名对象（接下行例子）
	//Person(p3);//编译器会认为Person(p3)等价于Person p3；类似函数声明，运行时系统会认为重定义的


	//隐式转换法
	Person p4=10;//相当于写了  Person p4 =Person(10);   有参构造
	Person p5=p4;//拷贝构造

}

int main()
{
	test01();

	system("pause");
	return 0;
}