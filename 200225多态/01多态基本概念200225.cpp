//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}

//��̬��C++���������������֮һ
//��̬��Ϊ����
//��̬��̬���������غ�������������ھ�̬��̬�����ú�����
//��̬��̬����������麯��ʵ������ʱ��̬

//��̬��̬�Ͷ�̬��̬����
//��̬��̬�ĺ�����ַ��󶨣�����׶�ȷ��������ַ
//��̬��̬�ĺ�����ַ��󶨣����н׶�ȷ��������ַ


#include<iostream>
using namespace std;

//��̬

//������
class Animal
{
public:
	//��󶨲��������virtual
	//�麯��
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}
};

//è��
class Cat :public Animal
{
public:
	//��д  ָ����  ��������ֵ����   ������  �����б�   ��ȫ��ͬ
	//��дʱ��������virtual�ؼ��ֱ���д�������п�д�ɲ�д
	//����������д�������麯��ʱ�������е��麯��  �б��ڲ�(ԭ���Ǹ����)��
	//�滻�������麯����ַ
	virtual void speak()
	{
		cout << "Сè��˵��" << endl;

	}
};

//����
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "С����˵��" << endl;

	}
};

//ִ��˵������
//��ַ��󶨣��ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�
//Ҳ���ǵ�ַ���

//��̬��̬��������
//1���м̳й�ϵ
//2������Ҫ��д�����麯��

//��̬��̬ʹ��
//�����ָ��������� ָ���������

void doSpeak(Animal& animal)//Animal &animal=cat;
{
	animal.speak();//������̬
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test02()
{
	cout << "sizeof Animal=" << sizeof(Animal) << endl;
}

int main()
{
	//test01();//��δ������󶨲���ʱ���������  ������˵��
	test02();
	system("pause");
	return 0;
}