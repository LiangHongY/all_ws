#include<iostream>
using namespace std;

//�̳���ͬ���ľ�̬��Ա�������������ν��з��ʣ�
//��������ͬ����Ա��ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա����Ҫ���������

//�̳��е�ͬ����̬��Ա����ʽ

class Base
{
public:
	static int m_A;//���ڶ��������������ʼ��

	static void func()
	{
		cout << "Base-func static��Ա��������" << endl;
	}
	static void func(int a)
	{
		cout << "Base-func(int a) static��Ա��������" << endl;
	}
};
int Base::m_A = 100;//��ʼ��

class Son :public Base
{
public:
	static int m_A;
	static void func()
	{
		cout << "Son-func static��Ա��������" << endl;
	}

};
int Son::m_A = 200;

//ͬ����̬��Ա����
void test01()
{
	//1��ͨ���������
	Son s;
	cout << "Son �µ�m_A=" << s.m_A << endl;
	cout << "Base �µ�m_A=" << s.Base::m_A << endl;
	//ͨ����������
	cout << "ͨ���������ʣ�" << endl;
	cout << "Son��m_A= " << Son::m_A << endl;

	//��һ��::����ͨ��������ʽ���ʣ��ڶ���::������ʸ�����������
	cout << "Base��m_A=" << Son::Base::m_A << endl;
}

//ͬ����̬��Ա����
void test02()
{
	//ͨ���������
	cout << "ͨ���������" << endl;
	Son s;
	s.func();
	s.Base::func();

	//ͨ��������ʽ����
	cout << "ͨ���������ʣ�" << endl;
	Son::func();
	Son::Base::func();
	  
	//�����г��ֺ͸���ͬ����̬��Ա������Ҳ�����ظ���������ͬ����Ա����
	//�������ʸ����б�����ͬ����Ա��������Ҫ���������
	Son::Base::func(100);
	
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʷ�ʽ��ͨ�������ͨ��������