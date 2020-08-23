#include<iostream>
using namespace std;
#include<queue>
#include<string>

//queue容器，基本概念
//概念：queue容器是一种先进先出（First int First Out,FIFO)的数据结构，它有两个出口

//队尾back()    --push()只进数据   ; 队头front()    --pop()只出数据;

//队列容器允许从一端新增元素，从另一端移除元素
//队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
//队列中进数据称为   -- 入队   push
//队列中出数据称为   -- 出队  pop

//判断队列是否为空  empty
//返回队列大小      size

//queue常用的接口，功能描述：栈容器常用的对外接口

//构造函数：
//queue<T> que;   //queue采用模板类实现，queue对象的默认构造形式
//queue(const queue &que)；     //拷贝构造函数

//赋值操作
//queue& operator=（const queue &que）;    //重载等号操作符

//数据存取
//push(elem);        //往队尾添加元素
//pop();             //从队头移除第一个元素
//back();           //返回最后一个元素
//front();          //返回第一个元素


//大小操作
//empty();      //判断堆栈是否为空
//size();       //返回栈的大小

//队列 queue
class Person 
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;

};


void test01()
{
	//创建队列
	queue<Person>q;

	//准备数据
	Person p1("唐僧",28);
	Person p2("孙悟空", 1028);
	Person p3("猪八戒", 998);
	Person p4("沙僧", 628);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "出队前队列大小为： " << q.size() << endl;
	//判断队列不为空，查看队头，查看队尾，出队
	while (!q.empty())
	{
		//查看队头元素
		cout << "队头元素-姓名：" << q.front().m_Name << " 年龄：" << q.front().m_Age << endl;

		//查看队尾元素
		cout << "队尾元素-姓名：" << q.back().m_Name << " 年龄：" << q.back().m_Age << endl;

		//出队
		q.pop();
	}
	cout << "出队后队列大小为： " << q.size() << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}