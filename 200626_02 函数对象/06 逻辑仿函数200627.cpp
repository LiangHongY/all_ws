#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

//逻辑仿函数，功能描述：
//实现逻辑运算

//函数原型：
//template<class T> bool logical_and<T>   //逻辑  与
//template<class T> bool logical_or<T>    //逻辑  或
//template<class T> bool logical_not<T>   //逻辑  非


//内建函数对象  逻辑仿函数
//逻辑非   logical_not

void test01()
{
	vector<bool>v;

	v.push_back(true);
	v.push_back(false);
	v.push_back(false);
	v.push_back(true);
	v.push_back(true);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//利用逻辑 非  将容器 v帮运到容器v2中，并执行取反操作

	vector<bool> v2;
	v2.resize(v.size());//需要提前开辟空间才能进行转换

	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	                                  //逻辑非，里面需要指定类型和加()
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//总结：逻辑仿函数实际应用较少，了解即可