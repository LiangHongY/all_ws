#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//常用遍历算法  transform 功能描述:
//搬运容器到另一个容器中

//函数原型：
//tranform(iterator beg1,iterator end1,iterator beg2,_func);

//beg1  源容器开始迭代器
//end1  源容器结束迭代器
//beg2  目标容器开始迭代器
//_func 函数或者函数对象

class Tranform
{
public:
	int operator()(int v)
	{
		return v+100;
	}
};

//打印输出仿函数
class myPrint
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

	vector<int>vTarget;
	vTarget.resize(v.size());//不开辟空间的话，语法上面没有报错，但是会运行崩溃
	                         //所以，目标容器，需要提前开辟空间
	transform(v.begin(), v.end(),vTarget.begin(), Tranform());

	//打印输出
	for_each(vTarget.begin(), vTarget.end(), myPrint());
	cout << endl;

}


int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：搬运的目标容器必须提前开辟空间，否则无法正常搬运