//#include<iostream>
//using namespace std;
//
//int main()
//{
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
#include<string>

//��ģ���׼�﷨
template<class NameType,class AgeType>

class Person
{
public:
	Person(NameType name,AgeType age)
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

void test01()
{
	Person<string, int>p1("����", 999);//��ģ������﷨��ʵ������
	p1.showPerson();
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ�
//��ģ��ͺ���ģ���﷨���ƣ�������ģ��template������࣬�����Ϊ��ģ��