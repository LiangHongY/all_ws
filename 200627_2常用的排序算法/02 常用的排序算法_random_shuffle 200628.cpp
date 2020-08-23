#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>

using namespace std;

//random_shuffle    功能描述：
//洗牌，指定范围内的元素随机调整次序

//函数原型：
//random_shuffle(iterator beg,iterator end);
//指定范围内元素随机调整次序
//beg   开始迭代器
//end   结束迭代器


void myPrint(int val)
	{
		cout << val << " ";
	}

void test01()
{
	srand((unsigned int)time(NULL));//注意这里面有双层括号的，而且时写在调用的函数内
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//利用洗牌算法  ，打乱顺序
	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}


int main()
{

	test01();
	system("pause");
	return 0;
}
//总结：random_shuffle洗牌算法比较实用，使用时记得加随机数种子