#include<iostream>
using namespace std;

//�������ص�ע������
//1��������Ϊ���ص�����

void func(int & a)//�ɶ���д��int &a=10,���ǲ��Ϸ��ģ�����func��10�����������
{
	cout<<"func(int &a)����"<<endl;
}

void func(const int & a)//ֻ�ǿɶ���const int &a=10,���ǺϷ��ģ�ǰ��̳������н����������˼ϵͳ�Զ�
	                                      //����һ���ڴ�ռ䱣��10���ͺϷ��ˣ�������func��10���������������
{
	cout<<"func(const int &a)����"<<endl;
}
//2��������������Ĭ�ϲ���
void func2(int a)
{
	cout<<"func2(int a)�ĵ���"<<endl;
}

void func2(int a,int b=10)//����Ĭ�ϲ������
{
	cout<<"func2(int a,int b=10)�ĵ���"<<endl;
}

int main()
{
	int a=10;
	func(a);//������const
	func(10);//������const

	//func2(10);//��������������Ĭ�ϲ��������ֶ����ԣ��ᱨ��Ӧ�ñ������������
	//func2(10);//�򵥵���⣬����������ʱ��������д����������Ĭ�ϲ���,�����Ұ�����ĵ�һ��func
	                    //��Ӷ�һ���Ĳ��������ǲ����Ĭ�ϲ���ʱ����ʱ��Ͳ�����������
	func2(10,2);


	system("pause");
	return 0;
}