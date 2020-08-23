#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//reverse  功能描述：
//将容器内的元素进行反转

//函数原型：
//reverse(iterator beg,iterator end);

//反转指定范围的元素
//beg   开始迭代器
//end   结束迭代器

void myprint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(50);
	v.push_back(60);
	v.push_back(30);
	v.push_back(20);

	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

	cout << "反转后：" << endl;
	reverse(v.begin(),v.end());
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：reverse 反区间内元素，面试可能会涉及到