#include<iostream>
using namespace std;
#include<string>

//��ģ��ͺ���ģ������
template<class NameType, class AgeType=int>//6,7�в��ܸ���д�����򱨴�         ����01 ���Ǹ���д�ģ��������С����Կ�����Ϊ��˵���Ǵ���ġ�200630
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "������ " << this->m_Name << endl;
		cout << "���䣺 " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

//1����ģ��û���Զ��Ƶ�����
void test01()
{
	//Person p1("����",999)��//������ģ��û���Զ��Ƶ����͹���
	Person<string,int>p("����", 999);//��ȷ��ֻ��ָ������
	p.showPerson();
}
//2����ģ����ģ������б��п�����Ĭ�ϲ���
void test02()
{
	Person<string>p1("����", 990);//���ﲻ��������Ϊ��ģ��������������Ĭ��Ϊint������
	p1.showPerson();
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
//�ܽ�
//��ģ��ʹ��ֻ������ʾָ�����ͷ�ʽ
//��ģ���е�ģ������б������Ĭ�ϲ���