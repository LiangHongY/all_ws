#include<iostream>
#include<map>

using namespace std;

//map容器的默认排序规则为，按照key值进行从小到大排序，掌握如何改变排序规则

//主要技术点：
//利用仿函数，可以改变排序规则

class Mycompare
{
public:
	bool operator()(int v1, int v2) {
		//降序
		return v1 > v2;
	}
};


void test01()
{
	map<int, int>m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(3, 20));
	m.insert(make_pair(2, 40));
	m.insert(make_pair(4, 90));
	m.insert(make_pair(6, 190));

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << " value= " << it->second << endl;
	}
	cout << endl;

	map<int, int,Mycompare>m1;

	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(3, 20));
	m1.insert(make_pair(2, 40));
	m1.insert(make_pair(4, 90));
	m1.insert(make_pair(6, 190));

	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "key= " << it->first << " value= " << it->second << endl;
	}
	cout << endl;
	//改变排序规则，出现错误和set等等容器改变排序规则出现的错误一样200626

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：
//利用仿函数可以指定map容器的排序规则    //这里出错，原因未知200626
//对于自定义数据类型，map必须要指定排序规则，这点和set容器相同