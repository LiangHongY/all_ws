#include<iostream>
using namespace std;

//��һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
//#include"person.cpp"

//�ڶ��ֽ����ʽ����.h��.cpp�е�����д��һ�𣬽���׺����дΪ.hpp�ļ���������ʵ�ַ���ͬһ�ļ��У�
#include"person.hpp"//.hpp��ʾ����һ�����ļ��������ģ�壬��������ô������������Լ���׳�

//����
//Ŀ�꣺������ģ���Ա�������ļ���д�����������Լ������ʽ

//���⣺��ģ���г�Ա��������ʱ��ʵ�ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���
//�����
//�����ʽ1��ֱ�Ӱ���.cppԴ�ļ�
//�����ʽ2����������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ�Ƶ�

//��ʼ
//��ģ����ļ���д�����Լ����
//#include<string>
//template<class T1,class T2>
//class Person
//{
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};
//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age)
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1,T2>::showPerson()
//{
//	cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
//}

void test01()
{
	Person<string, int>p("Tom", 19);
	p.showPerson();//���ͷ�ļ���person.h,��ô�������ᱨ���޸�Ϊperson.cpp�Ϳ������������
	               //ԭ���ǣ�дperson.hʱ�����������������person.cpp�ļ��������������޷���
	               //�ú����������޷����������ֱ��дperson.cpp,������ֱ�ӱ�����ļ�������
	               //�ҵ���Щ���������б���
}
int main()
{
	test01();
	system("pause");
	return 0;
}

//�ܽ᣺��ʽ�����ص���������Ͷ��嶼д��ͬһ���ļ��С���ǰ�����ģ����ļ���д��������
//���õķ�ʽ�ǵڶ��֣�����ģ���Ա����д��һ�𣬲�����׺����Ϊ.hpp