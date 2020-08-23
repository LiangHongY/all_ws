//常用集合算法   学习目标
//掌握常用的集合算法

//算法简介：
//set_intersection        //求两个容器的交集
//set_union               //求两个容器的并集
//set_difference          //求两个容器的差集


#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

// set_interesction   功能描述：
//求两个容器的交集

//函数原型
//set_interesction(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//求两个集合的交集

//注意：两个集合必须时有序序序列

//beg1  容器1开始迭代器
//end1  容器1结束迭代器
//beg2  容器2开始迭代器
//end2  容器2结束迭代器
//dest  目标容器开始迭代器

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
		v1.push_back(i);//0-9
		v2.push_back(i + 3);//3-12
	}
	vector<int>vTarget;
	//目标容器需要提前开辟空间
	//最特殊清空，大容器包含小容器   开辟空间   取小容器的size即可
	vTarget.resize(min(v1.size(), v2.size()));

	//获取交集
	//返回目标容器最后一个元素的迭代器地址
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), vTarget.end(), myprint);//容器不满地方自动填写0    vTarget.end()
	cout << endl;
	for_each(vTarget.begin(), itEnd, myprint);//只是输出重复部分
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：
//求交集的两个集合必须是有序序列
//目标容i去开辟空间需要从两个容器中取小值
//set_intersection   返回值既是交集中最后一个元素的位置