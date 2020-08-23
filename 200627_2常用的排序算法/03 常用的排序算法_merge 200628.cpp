#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//merge   ����������
//�����������ϲ������洢����һ��������

//����ԭ�ͣ�
//merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);

//����Ԫ�غϲ������洢����һ��������
//ע�⣺������������ʱ�����

//beg1   ����1�Ŀ�ʼ������
//end1   ����1�Ľ���������
//beg2   ����2�Ŀ�ʼ������
//end2   ����2�Ľ���������
//dest   Ŀ��������ʼ������

void myPrint(int val)
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
		v2.push_back(i + 1);
	}

	//Ŀ������
	vector<int>vTarget;

	//��ǰ��Ŀ����������ռ�
	vTarget.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), vTarget.end(),myPrint );
	cout << endl;


}


int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺merge �ϲ�������������������������