#include<iostream>
using namespace std;
#include<string>

//�������Ϊ���Ա

//�ֻ���
class Phone
{
public:
	Phone(string pName)
	{
		m_PName = pName;
		cout << "Phone���캯������" << endl;
	}
	~Phone()
	{
		cout << "Phone���������ĵ���" << endl;
	}
	//�ֻ�Ʒ������
	string m_PName;
};

//����
class Person
{
public:
	//��ʼ���б�֪ʶ
	//m_PName = pName ��ʽת����
	Person(string name, string pName):m_Name(name),m_Phone(pName)
	{
		cout << "Person���캯���ĵ���" << endl;
	}
	~Person()
	{
		cout << "Person������������" << endl;
	}

	//����
	string m_Name;
	//�ֻ�
	Phone m_Phone;
};
//�������������Ϊ�����Ա������ʱ���ȹ���������ٹ�������
//�籾�����У��ֻ�������Ϊ�����һ����Ա�ģ����ԣ��ȹ���Phone
//���ٹ���Person��

//��������ִ��˳���빹�캯��ִ��˳���෴�ģ���ѭ�Ƚ����ԭ��
//�����У����ͷŵ���Person�����ͷ�Phone��
void test01()
{
	Person p("����","ƻ��max");
	cout << p.m_Name << "�������������" << p.m_Phone.m_PName<<"����Ч��"<< endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
