#include<iostream>

using namespace std;

//���֣����ã�����ת��Ϊ int* const ref=&a;
void func(int& ref)
{
	ref=100;//ref�����ã�ת��Ϊ*ref=100
}

int main()
{
	int a=10;

	//�Զ�ת��Ϊint* const ref =&a��ָ�볣����ָ�򲻿ɸ��ģ������õı�����ָ�볣������Ҳ����˵�����ò��ɸ���ԭ��
	int& ref=a;
	ref=20;//�ڲ�����ref�����ã��������Զ�������ת��Ϊ*ref=20��

	cout<<"a="<<a<<endl;//20
	cout<<"ref="<<ref<<endl;//20

	func(a);
	cout << "a=" << a << endl;//100
	system("pause");
	return 0;
}

//���õı��ʾ���ָ�볣����ָ�򲻿ɱ䣩