#include<iostream>
using namespace std;
#include<string.h>

//��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������
//������
//�����ʽ���������е�����������Ϊ���������ߴ�������

//�������ʹ�����������
//���Խ������ָ���ͷ��������
//����Ҫ�о����ʵ�ֺ���

//�������ʹ�����������
//����Ǵ����������������ڳ����࣬�޷�ʵ��������

//�������﷨
//virtual ~����(){}

//���������﷨
//virtual ~����()=0;
//����::~��������{}

//�������ʹ�������
class Animal
{
public:
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}

	////�������������Խ������ָ���ͷ���������ͷŲ��ɾ�����
	//virtual ~Animal()//������
	//{
	//	cout << "Animal������������" << endl;
	//}

	//������������Ҫ����Ҳ��Ҫʵ��
	//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;//�����ʾ����������Ҫ����ʵ�ֲ���ʹ��

	//���麯��
	virtual void speak() = 0;
};

Animal::~Animal()//���������ľ���ʵ��
{
	cout << "������������~Animal�ĵ���" << endl;
}

class Cat :public Animal
{
public:
	Cat(string name)
	{
		cout << "cat�Ĺ��캯������" << endl;
		m_Name = new string(name);
	}
	virtual void speak()
	{
		cout <<*m_Name<< "Сè��˵��" << endl;
	}

	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "cat��������������" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}


	string* m_Name;
};

void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//����ָ��������ʱ�򣬲�������������������������������鹵�ж������ԣ������ڴ�
	//й¶�������ʽ���virtual��ʹ��������virtual ~Animal
	delete animal;
}


int main()
{
	test01();

	system("pause");
	return 0;
}

//�ܽ�
//�������������������������ͨ������ָ���ͷ��������
//ͨ��������û�ж������ݣ����Բ�д��������������
//ӵ�д���������������Ҳ���ڳ�����