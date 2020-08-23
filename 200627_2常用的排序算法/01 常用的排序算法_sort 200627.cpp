//常用的排序算法   学习目标：
//掌握常用的排序算法

//算法简介：

//sort              //对容器内的元素进行排序
//random_shuffle    //洗牌  指定范围内的元素随机调整次序
//merge             //容器元素整合，并存储到另一个容器中
//reverse           //反转指定范围的元素



#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

//sort  功能描述：
//对容器内元素进行排序

//函数模型：
//sort(iterator beg,iterator end,_Pred);

//按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
//beg     开始迭代器
//end     结束迭代器
//_Pred   谓词


void print01(int val)
{
	cout << val << " ";
}


void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(130); 
	v.push_back(110);
	v.push_back(30);
	v.push_back(140);
	v.push_back(70);

	//利用sort进行升序
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	//改变为  降序
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), print01);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

//总结：sort属于开发中最常用的算法之一，需要熟练掌握
