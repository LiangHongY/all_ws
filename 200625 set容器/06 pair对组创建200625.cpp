#include<iostream>
using namespace std;
#include<string>

//pair���鴴��������������
//�ɶԳ��ֵ����ݣ����ö�����Է�����������

//���ִ�����ʽ��
//pair<type,type> p (value1,value2);
//pair<type,type> p = make_pair(value1,value2);

//pair����Ĵ���
void test01()
{
	//��һ�ַ�ʽ
	pair<string, int> p("TOM",33);

	cout << "������" << p.first << "  ���䣺" << p.second << endl;

	//�ڶ��ַ�ʽ
	pair<string, int> p1=make_pair("Li��", 99);//�������
	cout << " ������" << p1.first << " ���䣺" << p1.second << endl;
}


int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺���ֶ����Դ������飬��סһ�ּ���