#include<iostream>
using namespace std;
#include<string>

//ѧϰĿ�꣺������ģ�������Ԫ���������ں�����ʵ��

//ȫ�ֺ�������ʵ�֣�ֱ��������������Ԫ����
//ȫ�ֺ�������ʵ�֣���Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���


//ͨ��ȫ�ֺ��� ��ӡPerson��Ϣ


//��ǰ�ñ�����֪��Person�����Ĵ���
template<class T1,class T2>
class Person;


//����ʵ��
template<class T1, class T2>
void printPerson2(Person<T1, T2>p)//���ﲻ��Ҫ��������Χ����Ϊ����ȫ�ֺ���
{
	cout << "����---������" << p.m_Name << " ���䣺" << p.m_Age << endl;
}

template<class T1,class T2>
class Person
{
	//ȫ�ֺ���������ʵ��
	friend void printPerson(Person<T1, T2>p)
	{
		cout << "������" << p.m_Name << " ���䣺" << p.m_Age << endl;
	}

	//ȫ�ֺ��� ����ʵ��
	//���һ����ģ������б�Ϳ��Խ���޷������ⲿ���������
	//���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void printPerson2<>(Person<T1, T2>p);

public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};



//1��ȫ�ֺ�������ʵ��
void test01()
{
	Person<string, int>p("Tom", 20);
	printPerson(p);
}
//2��ȫ�ֺ���������ʵ��
void test02()
{
	Person<string, int>p("god", 18);
	printPerson2(p);
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

//����ʵ��ʱ��Ƚ��鷳����������һ���࣬Ȼ��д����ʵ�֣�����ŵ��ඨ��
//�ܽ᣺����ʹ��ȫ�ֺ���������ʵ�ַ�ʽ����Ϊ���÷��򵥣����ұ���������ֱ��ʶ��