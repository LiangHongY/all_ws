#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

//const��ʹ�ó���

struct student
{
	string name;
	int age;
	int score;
};
//�������е��βθ�Ϊָ�룬���Լ���ռ�õ��ڴ�ռ䣬���Ҳ��Ḵ��һ���µĸ���������ֵ���ݻḴ���µĸ����ᵼ�´��ռ���ڴ棩
void printStudents(const student *s)//���û��const��ʹ�õ�ַ����ʱ���������д����ʱ���ᵼ��ʵ�α仯��const����Ϊ�˷�ֹ�������ʹ�õ�
{
	//s->age=150;//����const֮��һ�����޸ĵĲ����ͻᱨ�����Է�ֹ���������
	cout<<"ѧ����������   "<<s->name<<"   ѧ�������䣺   "<<s->age<<"   ѧ���ĳɼ���   "<<s->score<<endl;
}

int main()
{
  
	//�����ṹ�����
	struct student s={"����",15,70};

	//ͨ��������ӡ�ṹ�������Ϣ
	printStudents(&s);

	cout<<"main�����е����䣺   "<<s.age<<endl;

	system("pause");
	return 0;
}