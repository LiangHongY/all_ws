#include<iostream>
using namespace std;
#include<deque>

//deque容器基本概念
//功能描述：
//双端数组，可以对头端进行删除操作

//deque与vector区别：
//vector对于头部的插入删除效率低，数据量越大，效率越低
//deque相对而言，对于头部的插入删除速度会比vector快
//vector访问元素的速度会比deque快，这和两者内部实现有关

//deque的成员：

//头插 ：  push_front();
//头删  ： pop_front();
//第一个元素：   begin();
//指定位置插入：  insert();
//最后一个元素 ： end();
//尾插  ：  push_back();
//尾删  ：  pop_back();

//deque内部工作原理：

//deque内部有个中控器，维护每段缓冲区的内容，缓冲区存放真实数据（如果缓冲区记录满了，
//容器会开辟新的内存来存放，并把地址保持在中控器上面，访问就通过地址来访问）
//中控器维护的是每个缓冲器的地址，使得使用deque时像一片连续的内存空间

//deque容器的迭代器也是支持随机访问的


//deque构造函数  功能描述：
//函数原型：
//deque<T>deqT;     //默认构造形式
//deque(beg,end);   //构造函数将[beg,end)区间中的元素拷贝给本身
//deque(n,elem);    //拷贝构造函数将n个elem拷贝给本身
//deque(const deque &deq);    //拷贝构造函数


//deque 构造函数
void printDeque(const deque<int>&d)//这里添加const以限制只读状态，下面
                                 //的iterator迭代器书写也要有变化 ：const_iterator 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it=100;     //容器中数据不可以修改了
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 99);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);
}



int main()
{
	test01();

	system("pause");
	return 0;
}
//总结：deque容器和vector容器的构造方式几乎一样，灵活使用即可