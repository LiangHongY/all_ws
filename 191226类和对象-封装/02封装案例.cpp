#include<iostream>
#include<string>
using namespace std;
//���һ��ѧ���࣬������������ѧ��
//���Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��

//���ѧ����
class Student
{
public://����Ȩ��
	//һЩרҵ���
	//���е����Ժ���Ϊ  ͳһ��Ϊ   ��Ա
	//����    ��Ա����   ��Ա����   ������ һ����˼��
	//��Ϊ    ��Ա����   ��Ա����    ��ͬ�ϣ�

	//����
	string m_Name;
	int m_Id;
	//��Ϊ
	//��ʾ������ѧ��
	void showPrint()
	{
		cout<<"ѧ����������"<<m_Name<<"   ѧ����ID��"<<m_Id<<endl;
	}

	//��������ֵ��������Ϊ�����Ը�ֵ��
	void setName(string name)
	{
		m_Name=name;
	}
	//��id��ֵ
	void setId(int id)
	{
		m_Id=id;
	}
};

int main()
{
	//����һ�������ѧ����ʵ��������
	Student s1;
	//s1.m_Name="����";
	s1.setName("����");
	//s1.m_Id=01;
	s1.setId(2);
	//��ʾѧ������Ϣ
	s1.showPrint();//���ﲻ��Ҫ��дcout����ʾ���������ֱ�ӵ��þ�OK��

	system("pause");
	return 0;
}