#include<iostream>
using namespace std;
#include<string>

//string�ַ����Ƚ�
//����������
//�ַ���֮��ıȽ�

//�ȽϷ�ʽ��
//�ַ����Ƚ�ʱ�ǰ��ַ���ASCII����бȽ�

// = ����  0
// > ����  1
// < ���� -1

//����ԭ�ͣ�
//int compare(const string &s)const;//���ַ���s�Ƚ�
//int compare(const char *s) const;//���ַ���s�Ƚ�

//�ַ����Ƚ�

void test01()
{
	string str1 = "hello";
	string str2 = "hello";

	if (str1.compare(str2) == 0)
	{
		cout << "�ַ������" << endl;
	}
	else if (str1.compare(str2) == 1)
	{
		cout << "str1����str2" << endl;
	}
	else if (str1.compare(str2) == -1)
	{
		cout << "str1С��str2" << endl;
	}
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺�ַ����Ա���Ҫ���ڱȽ������ַ����Ƿ���ȣ��ж�˭��˭С�����岢���Ǻܴ�
//�жϺ��ֵĶԱ�û�����壬��Ϊ������ÿ�����ֶ���ASCII��