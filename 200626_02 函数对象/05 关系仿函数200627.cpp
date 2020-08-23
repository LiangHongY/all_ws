#include<iostream>
#include<functional>//想要写这个头文件，需要写使用标准公式库头文件才行
#include<algorithm>//标准公式头文件
#include<vector>

using namespace std;

//关系仿函数，功能描述：
//实现关系对比

//仿函数原型：
//template<class T> bool equal_to<T>        //等于
//template<class T> bool not_equal_to<T>    //不等于
//template<class T> bool greater<T>         //大于

//template<class T> bool greater_equal<T>   //大于或等于
//template<class T> bool less<T>            //小于
//template<class T> bool less_equal<T>      //小于或等于


//内建函数对象_关系仿函数
//大于  greater

//
class Mycompare
{
public:
	bool operator()(int &v1,int &v2)
	{
		return v1 > v2;
	}
};



void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(60);
	v.push_back(30);
	v.push_back(700);
	v.push_back(30);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	//降序
	//sort(v.begin(), v.end(),Mycompare());

	//greater<int>()    内建函数对象（int表示的是比较类型时int型）
	sort(v.begin(), v.end(),greater<int>());//系统自带的仿函数

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
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
//总结：关系仿函数最常用的就是  greater<>   大于 类型