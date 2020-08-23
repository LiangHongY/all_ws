#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//find_if  ����������
//����������Ԫ��

//����ԭ�ͣ�
//find_if(iterator beg,iterator end,_Pred);
//��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������

//beg ��ʼ������
//end ����������
//_Pred ��������ν�ʣ�����bool���͵ķº���)

//1������������ ��������
class greaterFive
{
public:
	bool operator ()(int val)
	{
		return val > 5;
	}
};


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos= find_if(v.begin(), v.end(), greaterFive());
	if (pos != v.end())
	{
		cout << "�ҵ������ݣ�" << *pos << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}

//2�������Զ��� ��������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

class greater20
{
public:
	bool operator()(Person &p)
	{
		return p.m_Age > 20;
	}
};

void test02()
{
	vector<Person>v;

	//��������
	Person p1("a", 10);
	Person p2("b", 60);
	Person p3("c", 30);
	Person p4("g", 4);
	Person p5("e", 12);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//���������20����
	vector<Person>::iterator pos= find_if(v.begin(), v.end(), greater20());
	
	if (pos != v.end())
	{
		cout << "�ҵ��ó�Ա��" << pos->m_Name << " ���䣺" << pos->m_Age << endl;
	}
	else
	{
		cout << "δ�ҵ��ó�Ա" << endl;
	}
	//���������������������������������ݣ�����ô����
	//��Ҫ�ҵ�һ��ɾһ������浽һ�����������棿
}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}