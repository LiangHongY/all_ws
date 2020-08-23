#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//binary_search  功能描述：
//查找指定元素是否存在

//函数原型：
//bool binary_search(iterator beg,iterator end,value);
//查找指定的元素 ， 查到  返回  true   否则  false

//注意：  在无序序列中  不可用
//beg   开始迭代器
//end   结束迭代器
//value  查找的元素

void test01()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//v.push_back(2);//加了这个输出错误了（实际存在却表示没有），
	   //验证了容器需要时有序才可以正常使用该查找算法

	//查找容器中是否有9元素
	//注意，容器必须是有序的序列
	bool gg=binary_search(v.begin(), v.end(), 9);

	if (gg == true)
	{
		cout << "存在该元素" << endl;
	}
	else
	{
		cout << "不存在该元素" << endl;
	}

}


int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：
//二分法查找效率很高，值得注意的是，查找的容器元素必须是有序序列