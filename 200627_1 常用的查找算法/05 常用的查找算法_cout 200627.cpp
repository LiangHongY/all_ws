#include<iostream>
#include<vector>
#include<string>

using namespace std;

//count   ����������
//ͳ��Ԫ�ظ���

//����ԭ�ͣ�
//count(iterator beg,iterator end,value);
//ͳ��Ԫ�س��ֵĴ���
//beg    ��ʼ������
//end    ����������
//value  ͳ�Ƶ�Ԫ��


//1��ͳ��  ������������
void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(10);
	v.push_back(3);
	v.push_back(10);

	int num=count(v.begin(), v.end(), 10);

	cout << "���ҵ����ݸ���Ϊ��" << num << endl;

}

//2��ͳ��  �Զ�����������
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	//����== �Ը��߸��㷨 �ײ�ıȶԹ���
	bool operator==(const Person& p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	string m_Name;
	int m_Age;
};
//class mycompare {
//public:
//	bool operator()(Person& p1, Person& p2)
//	{
//		return p1.m_Age == p2.m_Age;
//	}
//};

void test02()
{
	vector<Person>v;

	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 30);
	Person p5("�ܲ�", 40);

	Person p("�����", 35);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	int num=count(v.begin(), v.end(), p);

	cout << "�����ڣ��������ͬ���������У�" << num << endl;
}



int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//�ܽ᣺
//ͳ���Զ�����������ʱ����Ҫ�������  operator==