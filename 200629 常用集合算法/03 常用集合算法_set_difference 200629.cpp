#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

//set_difference    功能描述：
//求两个集合的差集

//函数原型：
//set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)
//求两个集合的差集
//注意两个集合必须是有序序列

//beg1   容器1开始迭代器
//end1   容器1结束迭代器
//beg2   容器2 开始迭代器
//end2   容器2结束迭代器
//dest   目标容器的开始迭代器 

void myprint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	//创建目标容器
	vector<int>vTarget;
	//提前给目标容器开辟空间
	vTarget.resize(max(v1.size(), v2.size()));

	cout << "输出v1和v2的差集：" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myprint);
	cout << endl;

	cout << "输出v2和v1的差集：" << endl;
	 itEnd = set_difference( v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myprint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

//总结
//求差集的两个集合必须是有序序列
//目标容器开辟空间需要从两个容器取较大值
//set_difference返回值是集合既是最后一个元素的位置