#include<iostream>
using namespace std;
#include<fstream>
#include<string>

//�������ļ�  ���ļ�

//�����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
//����ԭ�ͣ�  istream& read(char *buffer,int len);
//��������:�ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���

class Person
{
public:
	char m_Name[64];//����
	int m_Age;//����
};
void test01()
{
	//1.����ͷ�ļ�

	//2���������������
	ifstream ifs;
	//3�����ļ�
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}


		//4.д�ļ�
	Person p ;
	ifs.read((char*)&p, sizeof(Person));
	cout << "����: " << p.m_Name << "����: " << p.m_Age << endl;


//5.�ر��ļ�
	ifs.close();
}



int main()
{
	test01();
	system("pause");
	return 0;
}
//�ļ��������������ͨ��read�������Զ����Ʒ�ʽ��ȡ����