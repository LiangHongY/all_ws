//����
//string ��������

//1�����ʣ�
//string��C++�����ַ�������string��������һ����

//2��string��char*����
//char*��һ��ָ��
//string��һ���࣬�ڲ���װ��char*������������ַ�������һ��char*�͵�����

//3���ص㣺
//string���ڲ���װ�˺ܶ��Ա����
//���磬����find������copy��ɾ��delete���滻replace������insert
//string����char*��������ڴ棬���õ��ĸ���Խ���ȡֵԽ��ȣ������ڲ����и���

//string���캯��
//���캯��ԭ�ͣ�
//string();//����һ���յ��ַ��������磺string str;
//string(const char* s); //ʹ���ַ���s��ʼ��

//string(const string& str);//���������죩ʹ��һ��string�����ʼ����һ��string����
//string(int n,char c);//ʹ��n���ַ�c��ʼ��


#include<iostream>
using namespace std;

#include<string>

void test01()
{
	string s1;//Ĭ�Ϲ���

	const char* str = "hello world";
	string s2(str);

	cout << "s2= " << s2 << endl;

	string s3(s2);
	cout << "s3= " << s3 << endl;

	string s4(10,'a');
	cout << "s4= " << s4 << endl;//���ĸ���Ӧ����string���캯������
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺string�Ķ��ֹ��췽ʽû�пɱ��ԣ����ʹ�ü���