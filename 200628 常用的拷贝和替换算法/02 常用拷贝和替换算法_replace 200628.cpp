#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//replace    功能描述：
//将容器内指定范围的旧元素修改为新元素

//函数原型：
//replace(iterator beg,iterator end,oldvalue,newvalue);
//将区间内旧元素替换成新元素

//beg     开始迭代器
//end     结束迭代器
//oldvalue    //旧元素
//newvalue    //新元素

void myprint1(int val)
{
	cout << val << " ";
}

class myprint2
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

	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(30);
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(),myprint1);
	cout << endl;

	replace(v.begin(), v.end(), 20, 99);

	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), myprint2());
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

//总结：replace会替换区间内满足条件的元素