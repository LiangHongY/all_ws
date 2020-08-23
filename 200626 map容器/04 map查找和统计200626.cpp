#include<iostream>
#include<map>

using namespace std;

//map查找和统计，功能描述：
//对map容器进行查找数据以及统计数据

//函数原型：
//find(key);  //查找key是否存在，若存在，返回该key的元素的迭代器；若不存在，则
              //返回set.end();

//count(key);  //统计key的元素个数


void test01()
{
	map<int, int> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(2, 50));
	m.insert(make_pair(4, 40));

	//查找
	map<int, int>::iterator pos = m.find(4);
	
	if (pos != m.end())
	{
		cout << "存在：" << pos->first <<" " <<pos->second<< endl;

		//map容器不允许插入重复的key元素的数据，对于count统计而言，结果要么0，要么1
		//对于multimap容器，count的结果才有可能大于1
		cout << "个数为：" << m.count(4) << endl;
	}
	else
	{
		cout << "不存在" << endl;
	}

}



int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：
//查找  --find  (返回的是迭代器)
//统计  --count  （对于map而言，结果0或1）