//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

//����Ĭ�ϲ���

//������Ǵ������ݣ�ʹ���Լ����ݣ����û�У���ôʹ��Ĭ��ֵ
//�﷨��  ����ֵ����   ������   ���β�=Ĭ��ֵ��{ }
int func(int a,int b=20,int c=30)//b,c��Ĭ��ֵ
{
	return a+b+c;
}

//ע������
//1�����ĳ��λ������Ĭ�ϲ�������ô�����λ�����󣬴����Ҷ�������Ĭ��ֵ
//int func2(int a,int b=20,int c)//�����cû��Ĭ�ϲ������Ǳ���
//{
//	return a+b+c;
//}

//2���������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ���
//������ʵ��ֻ����һ��Ĭ�ϲ���
int func2(int a=10,int b=10);

//int func2(int a=10,int b=10)//�ض����ˣ���Ȼû��ʾ���ߣ���������ʱ�ᱨ�ض������
	int func2(int a,int b)
{
	return a+b;
}


int main()
{
	//cout<<func(10,30)<<endl;//���βδ�û��Ĭ��ֵ����£�ʵ�ε�����=�β���������Ĭ������£�ʵ��>=�β�������
	cout<<func2()<<endl;
	system("pause");
	return 0;
}