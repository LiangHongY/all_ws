#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;
//�ṹ��Ƕ�׽ṹ��
//���ã��ṹ���еĳ�Ա������һ���ṹ��
//����ѧ���ṹ��,�ȶ���ѧ�����ܶ�����ʦ�����ݽṹ�壬���򣬱���ʱ��ᱨ��
struct student
{
	string name;
	int age;
	int score;
};
//������ʦ�ṹ��
struct teacher
{
	int id;
	string name;
	int age;
	struct student stu;//������ѧ��
};
int main()
{
	//�ṹ��Ƕ�׽ṹ��
	//������ʦ
	teacher t;
	t.id=1000;
	t.name="����";
	t.age=50;
	t.stu.name="С��";
	t.stu.age=20;
	t.stu.score=60;

	cout<<"��ʦ������   "<<t.name<<"  ��ʦ�ı�ţ�   "<<t.id<<"   ��ʦ�����䣺  "<<t.age
		<<"  ��ʦ����ѧ�������� "<<t.stu.name<<"  ��ʦ����ѧ�����䣺  "<<t.stu.age
		<<"  ��ʦ����ѧ��������  "<<t.stu.score<<endl;

	system("pause");
	return 0;
}