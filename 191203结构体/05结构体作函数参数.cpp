#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

//����ѧ���ṹ��
struct student
{
	string name;
	int age;
	int score;
};
//��ӡѧ����Ϣ����
//1.ֵ���ݷ�ʽ
void printStudent1(struct student s)
{
	s.age=100;
	cout<<"   �Ӻ���1��  ������   "<<s.name<<"  ���� ��  "<<s.age<<"  ������  "<<s.score<<endl;
}

//2.��ַ����
void printStudent2(struct student *p)
{
	p->age=200;
	cout<<"   �Ӻ���2��  ������   "<<p->name<<"  ���� ��  "<<p->age<<"  ������  "<<p->score<<endl;
}

//�ܽ᣺ֵ�����ββ�Ӱ��main������ʵ�Σ�����ַ���ݻ�ı�main�����е�ʵ��


int main()
{
	//�ṹ������������
	//��ѧ������һ�������У���ӡѧ������������Ϣ

	//�����ṹ�����

	struct student s;
	s.name="����";
	s.age=20;
	s.score=85;

	//printStudent1(s);
	printStudent2(&s);
	cout<<"main�����д�ӡ   ������   "<<s.name<<"  ���� ��  "<<s.age<<"  ������  "<<s.score<<endl;

	system("pause");
	return 0;
}