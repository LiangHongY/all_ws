#include<iostream>
using namespace std;
#include<list>
#include<algorithm>//sort函数需要使用标准算法头文件

//list 反转和排序，功能描述
//将容器中的元素反转，以及将容器中的数据进行排序

//函数原型：
//reverse();     //反转链表
//sort();        //链表排序

void printList(const list<int>&L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";

	}
	cout << endl;
}

bool myCompare(int v1, int v2)
{
	//降序，就让第一个数>第二个数
	return v1 > v2;
}

void test01()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(4);
	L.push_back(7);
	L.push_back(50);

	printList(L);

	//反转后
	L.reverse();
	printList(L);

	////使用sort()函数排序;
	//cout << "sort函数排序：" << endl;
	//sort(L.begin(), L.end());//所有不支持随机访问迭代器的容器，不可以用标准算法
	//						//不支持随机访问迭代器的容器，内部会提供一些对应算法
	//printList(L);//这一节加入报错


	L.push_back(-10);
	//排序后
	L.sort();//默认的排序规则，从小到大， 升序
	cout << "使用L.sort()默认方式排序:" << endl;
	printList(L);

	L.sort(myCompare);
	cout << "使用降序方式来排序：" << endl;
	printList(L);
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：
//反转  --reverse
//排序  --sort(成员函数）