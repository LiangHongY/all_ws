#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		//thisָ��ָ����Ǳ����õĳ�Ա���������Ķ���
		this->age = age;
	}

	Person& PersonAddAge(Person& p)//&��ʾ����
		//���õķ�ʽ���أ�һֱ���ֵ���p2
		//������õ���û��&���ᴴ���µĶ��󣬷��ص��Ƿ�p2��
	{
		this->age += p.age;

		//thisָ��p2��ָ�룬��*thisָ��ľ���p2���������
		return *this;//�����Ǻű���ԭ���ǣ�ǰ�淵�����Ͳ�Ӧ��Ϊvoid
	}

	int age;
};


//1��������Ƴ�ͻ
void test01()
{
	Person p1(18);
	cout << "p1������Ϊ��  " << p1.age << endl;
}

//2�����ض�������*this

void test02()
{
	Person p1(10);

	Person p2(10);


	//��ʽ���˼��
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "p2������Ϊ���٣�  " << p2.age << endl;
}

int main()
{
	//test01();

	test02();

	system("pause");
	return 0;
}