#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//��Ԫν��
class MyCompare
{
public:
	bool operator()(int val1,int val2)
	{
		return val1 > val2;
	}
};



void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(2);
	v.push_back(13);

	sort(v.begin(), v.end());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//ʹ�ú������󣬸ı��㷨���ԣ���Ϊ�������Ӵ�С
	sort(v.begin(), v.end(), MyCompare());

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