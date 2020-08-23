#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>

using namespace std;

//fill   功能描述：
//向容器中填充指定的元素

//函数原型
//fill(iterator beg,iterator end,value);
//向容器中填充元素
//beg   开始迭代器
//end   结束迭代器
//value 填充的值

void myprint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v;

	v.resize(10);

	//后期重新填充
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：利用fill 可以将容器内区间内元素填充为指定的值