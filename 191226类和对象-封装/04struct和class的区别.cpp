#include<iostream>
using namespace std;

class C1
{
	int m_A;//Ĭ��Ȩ��     ˽��
};
struct C2
{
	int m_A;
};

int main()
{
	//struct��class������
	//struct Ĭ��Ȩ����  ����  public
	//class  Ĭ��Ȩ����   ˽��  private
	C1 c1;
	//c1.m_A=100;//�ᱨ��classĬ��Ȩ��Ϊ˽�У����ⲻ�ܷ���

	C2 c2;
	c2.m_A=100;//���ᱨ��structĬ��Ȩ��Ϊ������������Է���

	system("pause");
	return 0;
}