//vector容器基本概念
//功能：
//vector数据结构和数组非常相似，也称为单端数组

//vector和普通数组区别：
//不同之处在于数组是静态空间，而vector可以动态拓展

//动态拓展：
//并不是在原空间之后接后续新空间，而是找更大内存空间，然后将元数据拷贝新空间，释放原空间
//vector容器的迭代器是支持随机访问的迭代器
//v.begin() 表示容器第一个元素（位置）
//v.rbegin() 表示容器容器最后一个元素（位置）
//v.insert() 表示容器内插入元素
//v.end() 表示容器最后一个元素的后面一个（位置）

//vector构造函数

//功能描述：
//创建vector容器

//函数原型
//vector<T> v;  //采用模板实现类实现，默认构造函数
//vector（v.begin(),v.end()）;//将v[begin(),end())区间中的元素拷贝给本身(注意这里区间是
                              //前闭后开的，前面可以取得到，后面的取不到)
//vector(n,elem);      //构造函数将n个elem拷贝给本身
//vector(const vector &vec);//拷贝构造函数

#include<iostream>
#include<vector>
using namespace std;

//输出函数
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector容器构造
void test01()
{
	//默认构造  无参构造
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	//n个elem方式构造
	vector<int>v3(10, 100);
	printVector(v3);

	//拷贝构造
	vector<int>v4(v3);
	printVector(v4);
}


int main()
{
	test01();

	system("pause");
	return 0;
}
//vector的多种构造方式没有可比性，灵活使用即可
//老师体会，拷贝构造方式常用，其他相对不多