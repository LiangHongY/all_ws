#include<iostream>

using namespace std;
 
//1����������
void mySwap01(int a,int b)
{
	int temp=a;
	a=b;
	b=temp;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}

//2.��ַ����
void mySwap02(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
	cout<<"a="<<*a<<endl;
	cout<<"b="<<*b<<endl;
}

//3�����ô���
void mySwap03(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}

int main()
{
	int a=10;
	int b=20;

	//mySwap01(a,b);//ֵ���ݣ��ββ���ı�ʵ��
	//mySwap02(&a,&b);//��ַ���ݣ��βλ�����ʵ�ε�
	mySwap03(a,b);//���ô��ݣ��βλ�����ʵ�ε�
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;

	system("pause");
	return 0;
}
//�ܽ�
//��������������
//���ã���������ʱ�������������õļ������β�����ʵ��
//�ŵ㣺���Լ�ָ������ʵ��
//ͨ��Ӧ�ò���������Ч���͵�ַ����ʱһ���ģ����õ��﷨�������