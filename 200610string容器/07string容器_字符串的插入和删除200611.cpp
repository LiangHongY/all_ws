#include<iostream>
using namespace std;

//string�ַ��������ɾ��
//��������
//��string�ַ������в����ɾ���ַ�������

//����ԭ�ͣ�
//string& insert(int pos,const char* s);  //�����ַ���
//string& insert(int pos,const string& str);//�����ַ���
//string& insert(int pos,int n,char c);  //��ָ��λ�ò���n���ַ�c
//string& erase(int pos,int n=npos);  //ɾ��pos��ʼ��n���ַ�

//�ַ�����  �����ɾ��

void test01()
{
	string str = "hello";

	//����
	//str.insert(1, "222");
	//cout << "str= " << str << endl;

	//str.insert(1, str);
	//cout << "str= " << str << endl;

	str.insert(1, 3,'2');
	cout << "str= " << str << endl;

	//ɾ��
	str.erase(1, 3);
	cout << "str= " << str << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺
//�����ɾ������ʼ�±궼�Ǵ�0��ʼ