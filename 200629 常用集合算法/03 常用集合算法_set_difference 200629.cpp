#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

//set_difference    ����������
//���������ϵĲ

//����ԭ�ͣ�
//set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)
//���������ϵĲ
//ע���������ϱ�������������

//beg1   ����1��ʼ������
//end1   ����1����������
//beg2   ����2 ��ʼ������
//end2   ����2����������
//dest   Ŀ�������Ŀ�ʼ������ 

void myprint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	//����Ŀ������
	vector<int>vTarget;
	//��ǰ��Ŀ���������ٿռ�
	vTarget.resize(max(v1.size(), v2.size()));

	cout << "���v1��v2�Ĳ��" << endl;
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myprint);
	cout << endl;

	cout << "���v2��v1�Ĳ��" << endl;
	 itEnd = set_difference( v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myprint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

//�ܽ�
//�����������ϱ�������������
//Ŀ���������ٿռ���Ҫ����������ȡ�ϴ�ֵ
//set_difference����ֵ�Ǽ��ϼ������һ��Ԫ�ص�λ��