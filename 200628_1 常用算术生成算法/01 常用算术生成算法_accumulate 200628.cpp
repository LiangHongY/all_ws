//�������������㷨    ѧϰĿ�꣺
//���ճ��õ��㷨�����㷨

//ע�⣺ ���������㷨����С���㷨��ʹ��ʱ����ͷ�ļ�Ϊ�� #include<numeric>

//�㷨��飺
//accumulate      //��������Ԫ���ۼ��ܺ�
//fill            //�����������Ԫ��

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

//accumulate    ����������
//��������������Ԫ���ۼ��ܺ�

//����ԭ�ͣ�
//accumulate(iterator beg,iterator end ,value);
//��������Ԫ���ۼ��ܺ�
//��������Ԫ���ۼ��ܺ�
//beg   ��ʼ������
//end   ����������
//value ��ʼֵ

void test01()
{
	vector<int>v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}
	//����3  ��ʼ�ۼ�ֵ
	int total=accumulate(v.begin(),v.end(),1000);//���0����1000����ô�������6050
	cout << "total=" << total << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺accumulateʹ��ʱ  ͷ�ļ�ʱ  numeric������㷨��ʵ�á�