#include<iostream>
using namespace std;
#include<string>

//����������
//���ң�����ָ���ַ����Ƿ����
//�滻����ָ����λ���滻�ַ���

//����ԭ��
//int find(const string& str,int pos=0)const   //����str��һ�γ���λ�ã���pos��ʼ����
//int find(const char* s,int pos=0)const;   //����s��һ�γ���λ�ã���pos��ʼ����
//int find(const char* s,int pos,int n) const;//��posλ�ò���s��ǰn���ַ�����һ��λ��

//int find(const char c,int pos=0)const;  //�����ַ�c��һ����λ��
//int rfind(const string& str,int pos=npos)const;//����str���һ��λ�ã���pos��ʼ����
//int rfind(const char* s,int pos=npos)const;//����s���һ�γ���λ�ã���pos��ʼ����

//int rfind(const char*s,int pos,int n)const;//��pos����s��ǰn���ַ������һ��λ��
//int rfind(const char c,int pos=0)const;//�����ַ�c���һ�γ���λ��
//string& replace(int pos,int n,const string& str);//�滻��pos��ʼn���ַ�Ϊ�ַ���str
//string& replace(int pos,int n,const char* s);//�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

//�ַ������Һ��滻

//1������
void test01()
{
	string str1 = "abckdefgke";
	int pos = str1.find("k");

	if (pos == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "�ҵ��ַ���,pos= " << pos << endl;
	}
	//cout << "pos= " << pos << endl;//�����ʾ��d����λ�ã���Ϊ�Ǵ�0��ʼ��ǵ�

	//rfind��find������
	//rfind�����������  �� find�������Ҳ���

	//�鵽�ͻ�pos�ͻ᷵��λ��

	pos=str1.rfind("k");
	cout << "rfind��pos= " << pos << endl;//�����������ʱ�򣬷��صĻ��Ǳ���Ĵ洢λ��
	                       //�洢λ��ʱ�������Ҵ�0��ʼ���

}

//2���滻
void test02()
{
	string str1 = "abcdefg";

	//��1��λ����3���ַ������滻Ϊ��1111��
	str1.replace(1, 3, "1111");
	cout << "str1= " << str1 << endl;
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
//�ܽ᣺find���ҵ��Ǵ������ң�rfing��������
//find�ҵ��ַ����󷵻ز��ҵĵ�һ���ַ���λ�ã��Ҳ����ͷ���-1
//replace���滻ʱ��Ҫָ�����ĸ�λ�ÿ�ʼ�����ٸ��ַ����滻��ʲô���ӵ��ַ���