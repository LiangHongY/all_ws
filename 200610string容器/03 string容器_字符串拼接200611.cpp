#include<iostream>
using namespace std;
#include<string>

//string�ַ���ƴ��
//����������
//ʵ�����ַ���ĩβƴ���ַ���

//����ԭ��
//string& operator+=(const char* str);   //����+=������
//string& operator+=(const char c);     //����+=������
//string& operator+=(const string& str);//����+=������

//string& append(const char *s);   //���ַ���s���ӵ���ǰ�ַ�����β
//string& append(const char *s,int n);//���ַ���s��n���ַ������ӵ��ַ�����β
//string& append(const string &s);  //ͬoperator+=��const string& str��
//string& append(const string &s,int pos,int n);//���ַ���s��pos��ʼ��n���ַ�������
                                                 //���ַ�����β
void test01()
{
	string str1 = "��";
	str1 += "������Ϸ";
	cout << "str1= " << str1 << endl;

	str1 += ':';
	cout << "str1= " << str1 << endl;

	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1= " << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	cout << "str3= " << str3 << endl;

	str3.append("game abcd", 4);
	cout << "str3= " << str3 << endl;

	str3.append(str2);
	cout << "str3= " << str3 << endl;
	
	str3.append(str2,3,4);//ֻ�ǽ�ȡDNF������2���Ǹ�λ�ÿ�ʼ��ȡ������3��ȡ����
	cout << "str3= " << str3 << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}