#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//count_if   ��������
//������ͳ��Ԫ�ظ���

//����ԭ�ͣ�
//count_if(iterator beg,iterator end,_Pred);
//��������ͳ��Ԫ�س��ֵĴ���
//beg   ��ʼ������
//end   ����������
//_Pred  ν��


//1��������������
class Greater20
{
public:
	bool operator()(int v1)
	{
		return v1 > 20;
	}
};

void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(13);
	v.push_back(40);
	v.push_back(30);
	v.push_back(100);
	v.push_back(90);
	v.push_back(80);

	int num=count_if(v.begin(), v.end(), Greater20());

	cout << "����20��Ԫ�ظ�����" << num << endl;

}



//2���Զ�����������
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
class greater40
{
public:
	bool operator()(Person p)
	{
		return p.m_Age > 40;
	}
};


void test02()
{
	vector<Person>v;

	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 25);
	Person p5("�ܲ�", 45);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num = count_if(v.begin(), v.end(),greater40());

	cout << "����40������Ϊ��" << num << endl;

}



int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
