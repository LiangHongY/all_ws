#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//adjacent_find   功能描述
//查找相邻重复元素

//函数原型：
//adjacent_find(iterator beg,iterator end);
//查找相似重复元素，返回相邻元素的第一个位置的迭代器
//beg  开始迭代器
//end  结束迭代器



void test01()
{
	vector<int>v;
	
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	vector<int>::iterator pos= adjacent_find(v.begin(), v.end());

	if (pos != v.end())
	{
		cout << "找到相邻重复数据，且第一个该数据：" << *pos << endl;
	}
	else
	{
		cout << "未找到相邻重复数据" << endl;
	}

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：面试中，如果出现相邻重复元素，记得用STL中的adjacent_fing算法