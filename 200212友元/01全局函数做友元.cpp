//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
#include<string.h>

//��������
class Building
{
	friend void goodGay(Building* building);//��Ϊ��Ԫ��ʹ�ÿ��Է���Building˽�г�Ա
public:
	Building()
	{
		m_SittingRoom = "����";
		m_BedRoom = "����";
			
	}
	
public:
	string m_SittingRoom;//����

private:
	string m_BedRoom;//����
};

//ȫ�ֺ���
void goodGay(Building* building)
{
	cout << "�û��ѵ�ȫ�ֺ������ڷ��ʣ�  " << building->m_SittingRoom << endl;
	cout << "�û��ѵ�ȫ�ֺ������ڷ��ʣ�  " << building->m_BedRoom << endl;//����
	//����ԭ���ǣ�һ���ⲿ�������ܷ�������˽�г�Ա����
}

void test01()
{
	Building building;
	goodGay(&building);
}



int main()
{
	test01();

	system("pause");
	return 0;
}

//��Ԫ
//Ŀ������һ��������������Է�����һ������˽�г�Ա
//��Ԫ�Ĺؼ���Ϊ  friend
//��Ԫ������ʵ�֣�
//ȫ�ֺ�������Ԫ��������Ԫ����Ա��������Ԫ