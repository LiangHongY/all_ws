//���õ������㷨   ѧϰĿ�꣺
//���ճ��õ������㷨

//�㷨��飺

//sort              //�������ڵ�Ԫ�ؽ�������
//random_shuffle    //ϴ��  ָ����Χ�ڵ�Ԫ�������������
//merge             //����Ԫ�����ϣ����洢����һ��������
//reverse           //��תָ����Χ��Ԫ��



#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

//sort  ����������
//��������Ԫ�ؽ�������

//����ģ�ͣ�
//sort(iterator beg,iterator end,_Pred);

//��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
//beg     ��ʼ������
//end     ����������
//_Pred   ν��


void print01(int val)
{
	cout << val << " ";
}


void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(130); 
	v.push_back(110);
	v.push_back(30);
	v.push_back(140);
	v.push_back(70);

	//����sort��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	//�ı�Ϊ  ����
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), print01);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}

//�ܽ᣺sort���ڿ�������õ��㷨֮һ����Ҫ��������
