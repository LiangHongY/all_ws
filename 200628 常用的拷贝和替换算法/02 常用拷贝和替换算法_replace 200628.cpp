#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//replace    ����������
//��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��

//����ԭ�ͣ�
//replace(iterator beg,iterator end,oldvalue,newvalue);
//�������ھ�Ԫ���滻����Ԫ��

//beg     ��ʼ������
//end     ����������
//oldvalue    //��Ԫ��
//newvalue    //��Ԫ��

void myprint1(int val)
{
	cout << val << " ";
}

class myprint2
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(30);
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(),myprint1);
	cout << endl;

	replace(v.begin(), v.end(), 20, 99);

	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), myprint2());
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

//�ܽ᣺replace���滻����������������Ԫ��