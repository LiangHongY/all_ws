#include<iostream>
using namespace std;
#include<set>

//set插入和删除，功能描述：
//set容器进行插入数据和删除数据

//函数原型：
//insert(elem);     //在容器中插入元素
//clear();          //清除所有元素
//erase(pos);       //删除pos迭代器所指的元素，返回下一个元素的迭代器

//erase(beg,end);   //删除区间[beg,end)所有元素，返回下一个元素的迭代器
//erase(elem);      //删除容器中值为elem的元素

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s;

	s.insert(29);
	s.insert(3);
	s.insert(40);
	s.insert(37);

	printSet(s);

	//删除
	s.erase(s.begin());
	printSet(s);

	//删除重载版本
	s.erase(29);
	printSet(s);

	//清空
	s.erase(s.begin(), s.end());
	printSet(s);

	s.insert(12);
	printSet(s);
	s.clear();
	printSet(s);


	////删除指定位置的元素怎么实现，还知道。是不是set容器是不支持这么访问的？200625
	//for (set<int>::iterator it = s.begin(),int i=0; it != s.end(),i!=100; it++,i++)
	//{
	//	if (i== 2)
	//	{
	//		s.erase(40);
	//	}
	//}
	//printSet(s);


}


int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：
//插入 --insert
//删除  --erase
//清空  --clear