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

//�����������ķ���ֵ
//1����Ҫ���ؾֲ�����������
int & test01()
{
	int a=10;//�ֲ������洢�������е�   ջ����������ɾͻ��ͷţ����ǳ�������ͷţ�
	return a;
}

//2�������ĵ��ÿ�����Ϊ��ֵ
int & test02()
{
	static int a=10;//��̬�����������ȫ�����������������ϵͳ�ͷ�
	return a;
}

int main()
{
	int &ref=test01();
	cout<<"ref="<<ref<<endl;//��һ�ν����ȷ������Ϊ���������˱���
	cout<<"ref="<<ref<<endl;//�ڶ��δ�����Ϊ�ڴ��Ѿ��ͷ�

	int &ref2=test02();
	cout<<"ref2="<<ref2<<endl;
	cout<<"ref2="<<ref2<<endl;

	test02()=1000;//��������ķ���ֵ��  ���ã��������������Ϊ��ֵ
	cout<<"ref2="<<ref2<<endl;//1000//ref2����a�ı��� 
	cout<<"ref2="<<ref2<<endl;//1000
	system("pause");
	return 0;
}