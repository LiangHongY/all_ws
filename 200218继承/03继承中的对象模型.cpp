#include<iostream>
using namespace std;

//�̳��еĶ���ģ��

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};
//���ÿ�����Ա������ʾ���߲鿴����ģ�ͣ�Developer Command Prompt for vs 2019��
//��ת�̷�������  G��  �س�
//����Ŀ���ļ���  ����   cd G:\wenjianjia\Cyuyan\c++\200218�̳�\200218�̳�  �س�
//չʾ�ļ�Ŀ¼   ����    dir
//չʾ����ģ��   ����   cl /d1 reportSingleClassLayoutSon 03�̳��еĶ���ģ��.cpp  �س�
//ע�����棬��һ��ΪӢ��L�ڶ���Ϊ����������1
//����
//��ת�̷�
//��ת�ļ�·�� cd ����·��
//�鿴����
//cl /d1 reportSingleClassLayout���� �ļ���

void test01()
{
	//���������зǾ�̬��Ա���Զ��ᱻ����̳�����
	//������˽�г�Ա�����Ǳ������������ˣ�����Ƿ��ʲ���������ȷʵ���̳�������
	cout << "size of Son= " << sizeof(Son) << endl;//16����������int������һ��int��
}

int main()
{
	test01();

	system("pause");
	return 0;
}
