#include<iostream>
#include<map>

using namespace std;

//map插入和删除，功能描述
//map容器进行插入数据和删除数据

//函数原型：
//insert(elem);     //在容器中插入元素
//clear();          //清除所有元素

//erase(pos);       //删除pos迭代器所指的元素，返回下一个元素的迭代器
//erase(beg,end);   //删除区间[beg,end)的所有元素，返回下一个元素的迭代器
//erase(key);       //删除容器中值为key的元素

void printMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key值为：" << it->first << " value值：" << it->second << endl;
	}
	cout << endl;
}


void test01()
{
	map<int, int>m;
	
	//插入
	//第一种方式
	m.insert(pair<int, int>(1, 20));

	//第二种方式
	m.insert(make_pair(2, 10));//老师推荐方式

	//第三种
	m.insert(map<int, int>::value_type(3, 33));

	//第四种
	m[4] = 99;

	//[]不建议插入。但[]用途，可以利用key访问到value值
	//cout << m[5] << endl;//没有这个值却自动创建一个0的value值出来，所以不合适使用

	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);//按照key方式删除
	printMap(m);

	m.erase(m.begin(), m.end());
	printMap(m);


}

int main()
{
	test01();

	system("pause");
	return 0;
}