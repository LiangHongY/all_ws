#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>//标准算法头文件,本案例调用sort函数需要该头文件

//deque容器排序，功能描述：
//利用算法实现对deque容器进行排序

//算法：
//sort(iterator beg,iterator end) //对beg和end区间内元素进行排序

void printDuque(deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d;
	
	d.push_back(1000);
	d.push_back(20);
	d.push_back(30);
	d.push_back(110);
	d.push_back(120);
	d.push_back(150);

	printDuque(d);

	//排序，sort默认排序规则是，从小到大 升序
	//对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
	//vector容器也可以利用sort进行排序
	sort(d.begin(),d.end());
	cout << "排序后：" << endl;
	printDuque(d);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//总结：sort算法非常使用，使用时包含头文件algorithm即可