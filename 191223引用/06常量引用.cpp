#include<iostream>

using namespace std;

//����������Ҫ���������βΣ���ֹ�����
//�ں����β��б��У�����ʹ��const�����βΣ���ֹ�βθı�ʵ�Σ�����ǰ��ָ���βμ�const�����ӷ�ֹ�������

//��������
//ʹ�ó��������������βΣ���ֹ�����

//��ӡ��ֵ
void showValue(const int& val)//��const��Ŀ�ģ���ֹ������޸�ʵ��
{
	//val=1000;//����
	cout<<"val="<<val<<endl;
}


int main()
{
   // int a=10;
	//����const֮�󣬱������������޸ģ�int temp =10�� const int& ref =temp����������ж��ԣ�
	//const int& ref=10;//���ñ�����һ��Ϸ����ڴ�ռ䣻�������const�Ļ�������ڴ�ռ䲻�Ϸ���10ֻ�ǳ�������֪�����������ڴ�������
	//ref=20;//����const֮�󣬱��ֻ�������޸��ˣ����const * const p�������

	int a=100;
	showValue(a);
	cout<<"a="<<a<<endl;//���showValue�����βδ�����const�Ļ������������޸Ļ�ı������ʵ��a��ֵ

	system("pause");
	return 0;
}