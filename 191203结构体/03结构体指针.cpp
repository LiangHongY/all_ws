#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

//�ṹ��ָ��
//���ã�ͨ��ָ����ʽṹ���Ա
//���ò�����    ->   ����ͨ���ṹ��ָ����ʽṹ������

//����ѧ���ṹ��
struct student
{
	string name;
	int age;
	int score;
};

int main()
{
	//1.����ѧ���ṹ�����
	struct student s={"����",18,100};

	//2.ͨ��ָ��ָ��ṹ�����
	struct student * p = &s;//struct����ʡ�ԣ�����ָ��ǰ���student��д  �ṹ�����ᱨ���

	//3.ͨ��ָ����ʽṹ������е�����
	//ͨ���ṹ��ָ�룬���ʽṹ���е����ԣ���Ҫ���� "  ->  "
	cout<<"������  "<<p->name<<"  ���䣺  "<<p->age<<"  ������  "<<p->score<<endl;

	//�ܽ᣺�ṹ��ָ�����ͨ��  -> �����������ʽṹ���еĳ�Ա
	system("pause");
	return 0;
}