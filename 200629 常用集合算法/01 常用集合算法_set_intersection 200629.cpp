//���ü����㷨   ѧϰĿ��
//���ճ��õļ����㷨

//�㷨��飺
//set_intersection        //�����������Ľ���
//set_union               //�����������Ĳ���
//set_difference          //�����������Ĳ


#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

// set_interesction   ����������
//�����������Ľ���

//����ԭ��
//set_interesction(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);
//���������ϵĽ���

//ע�⣺�������ϱ���ʱ����������

//beg1  ����1��ʼ������
//end1  ����1����������
//beg2  ����2��ʼ������
//end2  ����2����������
//dest  Ŀ��������ʼ������

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
		v1.push_back(i);//0-9
		v2.push_back(i + 3);//3-12
	}
	vector<int>vTarget;
	//Ŀ��������Ҫ��ǰ���ٿռ�
	//��������գ�����������С����   ���ٿռ�   ȡС������size����
	vTarget.resize(min(v1.size(), v2.size()));

	//��ȡ����
	//����Ŀ���������һ��Ԫ�صĵ�������ַ
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), vTarget.end(), myprint);//���������ط��Զ���д0    vTarget.end()
	cout << endl;
	for_each(vTarget.begin(), itEnd, myprint);//ֻ������ظ�����
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺
//�󽻼����������ϱ�������������
//Ŀ����iȥ���ٿռ���Ҫ������������ȡСֵ
//set_intersection   ����ֵ���ǽ��������һ��Ԫ�ص�λ��