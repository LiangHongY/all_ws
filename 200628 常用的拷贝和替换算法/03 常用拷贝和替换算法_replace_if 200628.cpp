#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

//replace_if     功能描述：
//将区间内的满足条件的元素，替换成指定元素

//函数原型：
//replace_if(iterator beg,iterator end,_Pred,newvalue);
//按条件替换元素，满足条件的替换成指定元素
//beg   开始迭代器
//end   结束迭代器
//_Pred   谓词
//newvalue   替换的新元素

void myprint(int val)
{
	cout << val << " ";
}

class Greater30
{
public:
	bool operator()(int val)
	{
		return val >=30;
	}
};


void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);
	v.push_back(10);
	v.push_back(100);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

	replace_if(v.begin(), v.end(), Greater30(), 3000);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：replace_if 按条件查找，可以利用仿函数灵活筛选满足的条件