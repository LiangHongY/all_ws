//����������
//���غ������ò��������࣬����󳣱���Ϊ  ��������
//��������ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ��  �º���

//�����ǣ�
//�������󣨷º�������һ���࣬����һ������

//��������ʹ��
//�ص㣺
//����������ʹ��ʱ����������ͨ�����������ã������в��������Է���ֵ
//�������󳬳���ͨ�����ĸ����������������Լ���״̬
//�������������Ϊ��������

//�������󣨷º�����
#include<iostream>
using namespace std;
#include<string>


class MyAdd
{
public:
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};

//1������������ʹ��ʱ����������ͨ�����������ã������в��������Է���ֵ
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 10) << endl;
}

//2���������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}

	int count;//�ڲ��Լ�״̬,���ó�Ա���Զ��������״̬��¼
};

void test02()
{
	MyPrint myprint;
	 myprint("С����") ;
	 myprint("С����");
	 myprint("С����");

	 cout << "myprint���ô�����" << myprint.count << endl;
}

//3���������������Ϊ��������
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}

void test03()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}


int main()
{
	//test01();
	//test02();
	test03();

	system("pause");
	return 0;
}

//�ܽ᣺�º���д���ǳ���������Ϊ�������д���