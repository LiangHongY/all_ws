#include<iostream>
using namespace std;

#include<string>

//string�Ӵ�
//����������
//���ַ����л�ȡ��Ҫ���Ӵ�

//����ԭ�ͣ�
//string substr(int pos=0,int n=npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���

//string ���Ӵ�

void test01()
{
	string str = "abcdef";
	string subStr = str.substr(1, 3);
	cout << "subStr= " << subStr << endl;
}

//ʵ�ò���
void test02()
{
	string email = "zhangsan@sina.com";

	//�������ַ�л�ȡ�û���Ϣ

	int pos = email.find("@");

	string userName = email.substr(0, pos);
	cout << "�û���Ϣ��" << userName << endl;
}

int main()
{
	test01();

	test02();
	system("pause");
	return 0;
}
//�ܽ᣺�����������Ӵ����ܣ�������ʵ�ʿ����л�ȡ��Ч����Ϣ