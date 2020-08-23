//谓词概念：
//返回bool类型的仿函数称为谓词
//如果operator()接受一个参数，那么叫一元谓词
//如果operator()接受两个参数，那么叫做二元谓词



#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>//标准算法头文件

//一元谓词
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//查找容器中，有没有大于5的数字
	//GreaterFive() 匿名函数对象
	vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());//标准函数公式，在区间內寻找满足条件数据
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到大于5数字为：" << *it << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//总结：参数只有一个的谓词，称为一元谓词
//一个疑惑：那么还有其他大于5的数据，我该怎么读取呢？是不是使用一个循环来输出呢？好像
//可行。具体还有没有其他方式，不清楚。200626