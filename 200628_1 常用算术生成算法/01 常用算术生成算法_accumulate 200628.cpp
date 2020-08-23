//常用算术生成算法    学习目标：
//掌握常用的算法生成算法

//注意： 算术生成算法属于小型算法，使用时包含头文件为： #include<numeric>

//算法简介：
//accumulate      //计算容器元素累计总和
//fill            //向容器中添加元素

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

//accumulate    功能描述：
//计算区间内容器元素累计总和

//函数原型：
//accumulate(iterator beg,iterator end ,value);
//计算容器元素累计总和
//计算容器元素累计总和
//beg   开始迭代器
//end   结束迭代器
//value 起始值

void test01()
{
	vector<int>v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//参数3  起始累加值
	int total=accumulate(v.begin(),v.end(),1000);//如果0换成1000，那么输出就是6050
	cout << "total=" << total << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：accumulate使用时  头文件时  numeric，这个算法很实用。