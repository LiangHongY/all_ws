#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>

//����������ʵ��һ��ͨ�õ������࣬Ҫ�����£�
//���Զ������������Լ��Զ����������͵����ݽ��д洢
//�������е����ݴ洢������
//���캯���п��Դ������������
//�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������    ò�������沢û���������--200702
//�ṩβ�巨��βɾ�������ݽ������Ӻ�ɾ��
//����ͨ���±귽ʽ���������е�Ԫ��
//���Ի�ȡ�����е�ǰԪ�ص�����

void printInArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i]<<endl;//�������������Կ���ֱ�ӷ��ʸ�����
	}
}

void test01()
{
	MyArray<int>arr1(5);

	for (int i = 0; i < 5; i++)
	{
		//����β�巨�������в�������
		arr1.Push_back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ��" << endl;
	printInArray(arr1);

	cout << "arr1��������" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�С��" << arr1.getSize() << endl;

	MyArray<int>arr2(arr1);
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	printInArray(arr2);

	//βɾ
	arr2.Pop_Back();
	cout << "arr2βɾ��" << endl;
	cout << "arr2��������" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�С��" << arr2.getSize() << endl;

	

	//�Ͻڿβ���
	//MyArray<int>arr2(arr1);
	//MyArray<int>arr3(100);
	//arr3 = arr1;


}//�ܽ᣺17�ڵĿ�������ɶ�Ĳ����ף���Ҫ��Ϊɶ���������������������Ҫ������200510


//�����Զ�����������
class Person
{
public:
	Person() {};//�⵽��ʲôԭ���أ�200511  ����Ĭ�Ϲ��죬���ǿ�����ʲô���ã�200512
	Person(string name, int age)//�вι���
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "������ " << arr[i].m_Name << " ���䣺" << arr[i].m_Age << endl;
	}
}//��δ�����Ҫ����class Person�������У�����������Ҳ���Person���Ԫ�أ�ֱ�ӱ�һ����﷨����


void test02()
{
	MyArray<Person>arr(10);
	Person p1("����", 999);
	Person p2("����", 30);
	Person p3("槼�", 20);
	Person p4("����", 25);
	Person p5("������", 23);

	//�����ݲ���������
	arr.Push_back(p1);
	arr.Push_back(p2);
	arr.Push_back(p3);
	arr.Push_back(p4);
	arr.Push_back(p5);

	//��ӡ����
	printPersonArray(arr);
	cout << "arr��������" << arr.getCapacity() << endl;
	cout << "arr�Ĵ�С��" << arr.getSize() << endl;


}


int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//�������Ҳ������������ٶ�������ʱ����this->pAddress[i] = arr.pAddress[i];��䣬����ʾ
//��������ľ��档��Ȼ�����������У����ǣ��������Ŀǰ��û�ҵ������ʽ��200511
//����֪ʶ�㡢��ģ��֪ʶ�㶼û��û�й��ء�
//��������������������� 200701