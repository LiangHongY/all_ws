#include<iostream>
#include<string>
using namespace std;

//����Ȩ��
//����Ȩ��   public            ��Ա     ���ڿ��Է��ʣ�������Է���
//����Ȩ��   protected     ��Ա    ���ڿ��Է��ʣ����ⲻ���Է���     ���̳��ϣ����ӿ��Է��ʸ����б���������
//˽��Ȩ��   private           ��Ա    ���ڿ��Է��ʣ����ⲻ���Է���     ���̳��ϣ����Ӳ����Է��ʸ��׵�˽������

class Person
{
public:
	//����Ȩ��
	string m_Name;
protected:
	//����Ȩ��
	string m_car;
private:
	//˽��Ȩ��
	int m_Password;//��������
public:
	void func()
	{
		m_Name="����";
		m_car="������";
		m_Password=123456;//�������������ڷ���
	}
};

int main()
{
	Person p1;
	//�����������

	p1.m_Name="����";
	//p1.m_car="����";//�ᱨ�����ڱ���Ȩ�����ݣ���������ʲ�����
	//p1.m_Password=123;//�ᱨ������˽��Ȩ�����ݣ�������ʲ��˵�
	p1.func();//����Ȩ�ޣ�������Է���

	system("pause");
	return 0;
}