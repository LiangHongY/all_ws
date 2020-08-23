//常用算法

//概述
//算法主要时由头文件<algorithm> <functional> <numeric>组成
//<algorithm>  是所有STL头文件中最大的一个，范围涉及比较、查找、遍历操作、复制、修改等等
//<functional> 定义了一些模板类，用以声明函数对象
//<numeric>  体积很小，只包括几个在序列上面进行简单数学运算的模板函数


//常用的遍历算法，学习目标
//掌握常用的遍历算法

//算法简介：
//for_each      //遍历容器
//transform     //搬运容器到另一个容器中

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//常用遍历算法  for_each
//for_each  功能描述：
//实现遍历容器

//函数原型：
//for_each(iterator beg,iterator end, _func);
//遍历算法，遍历容器元素
//beg 开始迭代器
//end  结束迭代器
//_func  函数或者函数对象

//普通函数
void print01(int val)
{
	cout << val << " ";
}

//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), print01);//常函数不需要加函数对象
	cout << endl;

	for_each(v.begin(), v.end(), print02());
	cout << endl;

}


int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：for_each在实际开发中是最常用的遍历算法，需要熟练掌握