#include<iostream>
#include<string>
using namespace std;

#define MAX 1000   //ע�ⲻ��д=��

  //��ϵ�˽ṹ��
struct Person   
{
	string m_Name;
	int m_Sex;       //1 �� 2Ů
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};
void addPerson(Addressbooks *abs)