#include<iostream>
using namespace std;

//�������������

class Person
{
	friend ostream& operator<<(ostream& cout, Person &p);
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:

	//���ó�Ա��������  ���������  p.operator<<(cout)  �򻯰汾 p<< cout
	//�������ó�Ա��������<<���������Ϊ�޷�ʵ��  cout �����
	//void operator<<(cout)
	//{

	//}

	int m_A;
	int m_B;
};

//ֻ������ȫ�ֺ����������������
//void operator<<(ostream &cout, Person p)//����  operator<<(cout,p)  ��  cout<<p
ostream & operator<<(ostream& cout, Person &p)//����  operator<<(cout,p)  ��  cout<<p
{
	cout << "m_A=" << p.m_A << "  m_B=" << p.m_B;
	return cout;
}

void test01()
{
	Person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;

	cout << p <<"why"<<endl;//���治��д  <<endl  ,����ᱨ�������ʽ�ǰѽ�void�޸�Ϊostream,������return cout
}

int main()
{
	test01();

	system("pause");
	return 0;
}

//��������������ص���˵��ô���p���Ͱ�p�����ڳ�Ա���Զ������