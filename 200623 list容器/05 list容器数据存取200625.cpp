#include<iostream>
using namespace std;
#include<list>

//list数据存取，功能描述：
//对list容器中数据进行存取

//函数原型：
//front();       //返回第一个元素
//back();     //返回最后一个元素


void printList(list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L;

	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);

	printList(L);
	//L[0];//报错，list容器底层没有重载[]，所以不能使用[]访问容器的元素

	//L.at(0);//报错，不可以使用at方式访问list容器的元素

	//原因是list本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的

	cout << "第一个元素为：" << L.front() << endl;

	cout << "最后一个元素为：" << L.back() << endl;

	//验证迭代器是不支持随机访问
	list<int>::iterator it = L.begin();
	it++;//支持双线访问     //即使写成(it++)++,也是输出加加一次的效果，也是就说，后面再怎么加加，还是输出20
	cout << *it << endl;
	it--;;//支持双线访问。如果只能++或者--，那么只是支持单向的。
	cout << *it << endl;

	//it = it + 3;//报错，表示不能跳跃式访问

}

int main()
{
	test01();
	system("pause");
	return 0;
}