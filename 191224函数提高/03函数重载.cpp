#include<iostream>
using namespace std;

//��������
//�����ú�������ͬ����߸�����

//�������ص���������
//1��ͬһ��������
//2������������ͬ
//3�������������Ͳ�ͬ�����߸�����ͬ������˳��ͬ

//���¶���ͬ������ȫ����������
void func()
{
	cout<<"func �ĵ���"<<endl;
}

void func(int a)//���Ͳ�ͬ����ǰ�����¾�ͬ��
{
	cout<<"func (int a)�ĵ���"<<endl;
}

void func(double a)//���Ͳ�ͬ
{
	cout<<"func (double a)�ĵ���"<<endl;
}

void func(int a,double b)//������ͬ
{
	cout<<"func (int a,double b)�ĵ���"<<endl;
}

void func(double a,int b)//˳��ͬ
{
	cout<<"func (double a,int b)�ĵ���"<<endl;
}

//ע������
//�����ķ���ֵ��������Ϊ�������ص�����
//int func(double a,int b)//����ֵ��Ȼ����int���������void�����𣬵��ǲ�����Ϊ�������ص�����
//{
//	cout<<"func (double a,int b)�ĵ���"<<endl;
//}



int main()
{
	func();
	func(10);
	func(3.14);
	func(10,3.14);
	func(3.14,10);

	system("pause");
	return 0;
}