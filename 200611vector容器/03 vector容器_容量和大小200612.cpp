#include<iostream>
using namespace std;
#include<vector>

//�����ʹ�С��������
//��vector�����������ʹ�С����

//����ԭ�ͣ�
//empty();     //�ж������Ƿ�Ϊ��
//capacity();   //����������
//size();     //����������Ԫ�صĸ���
             
//resize(int num);//�����ƶ������ĳ���Ϊnum���������䳤������Ĭ�������λ�� ��Ĭ����0  
				   //���������̣���ĩβ���������ĳ��ȵ�Ԫ�ر�ɾ��

//resize(int num,elem); //�����ƶ���������Ϊnum���������䳤������elem�����λ��
                       //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

void printVector(vector<int>&v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())//Ϊ�棬��ʾ����Ϊ��
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ�� " << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ" << v1.size() << endl;
	}

	//����ָ����С
	v1.resize(15,100);
	printVector(v1);//��֤Ĭ��ʹ��0����������λ��
	                //�������ָ���ı�ԭ�����ˣ�Ĭ����0�������λ��

	v1.resize(20,50);//�������ذ汾������ָ��Ĭ�����ֵ������2
	printVector(v1);//�������ָ����ԭ�����ˣ�Ĭ����0����µ�λ��

	v1.resize(5);//��������ƶ��ı�ԭ�����ˣ��ͻ�ɾ����������
	printVector(v1);
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺
//�ж��Ƿ�Ϊ��  ---empty
//����Ԫ�ظ���  ---size
//������������  ---capacity
//����ָ����С  ---resize