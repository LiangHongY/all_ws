#include<iostream>
using namespace std;

//�̳��﷨��class ���� �� �̳з�ʽ ����

//�̳з�ʽ�������̳С������̳С�˽�м̳�

//���ͣ����ȣ���������  public  a  ��protected  b  ��private  c
//�����̳У�  ���ࣺ  public  a   ��protected  b
//�����̳У�  ���ࣺ  protected  a�� protected  b
//˽�м̳У�  ���ࣺ  private    a��private   b

//�̳з�ʽ

//�����̳�
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//�������ʾ�������еĹ���Ȩ�޳�Ա������������Ȼ�ǹ���Ȩ��
		m_B = 10;//��������ʾ�����б���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
		//m_C = 10;//������ʾ�����е�˽��Ȩ�޳�Ա�������Ƿ��ʲ��˵�
	}
};

void test01()
{
	Son1 s1;
	s1.m_A = 100;//�������ʾ����Ȩ�޳�Ա����Ҳ���Է���
	//s1.m_B = 100;//������ʾ����Ȩ�������ⲻ���Է���
}

//�����̳�
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 :protected Base2
{
public:
	void func()
	{
		m_A = 100;//�����й�����Ա���������б�Ϊ����Ȩ��
		m_B = 100;//�����б�����Ա����������Ҳ�Ǳ���Ȩ��
		//m_C = 100;//���������޷���Ȩ��
	}
};

void test02()
{
	Son2 s1;
	//s1.m_A = 100;//������Son2��m_AΪ����Ȩ�ޣ����������ʲ�����
	//s1.m_B = 100;//������Son2��m_BΪ����Ȩ�ޣ����ɷ���
}

//˽�м̳�
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 100;//�����й�����Ա���������б�Ϊ˽��Ȩ��
		m_B = 100;//�����б�����Ա����������Ҳ��˽��Ȩ��
		//m_C = 100;//���������޷���Ȩ��
	}
};

void test03()
{
	Son3 s1;
	//s1.m_A = 100;//������Son2��m_AΪ˽��Ȩ�ޣ����������ʲ�����
	//s1.m_B = 100;//������Son2��m_BΪ˽��Ȩ�ޣ����ⲻ�ɷ���
}

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 100;//������˽�г�Ա��������Ȩ����
		//m_B = 100;//������˽�г�Ա��������Ȩ����
	}
};

int main()
{

	system("pause");
	return 0;
}