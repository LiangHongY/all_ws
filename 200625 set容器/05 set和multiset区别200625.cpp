#include<iostream>
using namespace std;
#include<set>


//set和multiset区别，学习目标
//掌握set和multiset的区别

//区别：
//set不可以插入重复的数据，而multiset可以
//set插入数据的同时会返回插入结果，表示插入是否成功
//multiset不会检测数据，因此可以插入重复数据

//set容器和multiset容器的区别
void test01()
{
	set<int>s;

	pair<set<int>::iterator,bool> ret=s.insert(10);//检查是否插入成功

	if (ret.second)//返回的是bool类型
	{
		cout << " 第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}

	ret = s.insert(10);
	if (ret.second)
	{
		cout << " 第2次插入成功" << endl;
	}
	else
	{
		cout << "第2次插入失败" << endl;
	}

	multiset<int>s1;
	
	s1.insert(200);
	s1.insert(200);
	for (multiset<int>::iterator it = s1.begin(); it != s1.end(); it++)
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
//对于set容器，会返回是否插入成功，可以看对应的insert来查看对应的源码性质知道的
//对于multiset容器，不会返回是否插入成功，但是会有迭代器返回


//总结
//如果不允许插入重复数据，可以插入set，
//如果需要插入重复数据，可以利用multiset