#include<iostream>
using namespace std;

//���麯���ͳ�����
class Base
{
public:
	//���麯��
	//ֻҪ��һ�����麯����������Ϊ������
	//�������ص㣺
	//1���޷�ʵ��������
	//2.����������࣬����Ҫ��д�����еĴ��麯��������Ҳ���ڳ�����
	//���麯���﷨��virtual ����ֵ����  ������ �������б�=0;
	virtual void func() = 0;
};

class Son :public Base
{
public:
	virtual void func()//��д�����еĴ��麯��
	{
		cout << "func�����ĵ���" << endl;
	}
};

void test01()
{
	//Base b;//���������޷�ʵ��������
	//new Base;//���������޷�ʵ��������
	//Son s;//���������д�����еĴ��麯���������޷�ʵ��������

	Base* base = new Son;
	base->func();
}

int main()
{
	test01();
	system("pause");
	return 0;
}