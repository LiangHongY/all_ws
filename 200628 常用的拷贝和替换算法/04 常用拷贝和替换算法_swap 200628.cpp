#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//swap    功能描述：
//互换两个容器的元素

//函数原型：
//swap(container c1,container c2);
//互换两个容器的元素
//c1  容器1
//c2  容器2

class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void myprint1(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(10);
	v.push_back(4);

	vector<int>v1;

	v1.push_back(100);
	v1.push_back(130);
	v1.push_back(410);
	v1.push_back(210);
	v1.push_back(30);

	cout << "交换前v  v1：" << endl;
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;

	cout << "交换后v  v1：" << endl;
	swap(v, v1);
	for_each(v.begin(), v.end(), myprint1);
	cout << endl;
	for_each(v1.begin(), v1.end(), myprint1);
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//注意，属于同种类型的容器才能交换
//总结：swap交换容器时，注意交换的容器要同类型