#include<iostream>
#include<map>
using namespace std;

//map��С�ͽ���������������
//ͳ��map������С�Լ�����map����

//����ԭ�ͣ�
//size();      //����������Ԫ�ص���Ŀ
//empty();     //�ж������Ƿ�Ϊ��
//swap();      //����������������

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "   " << it->second << endl;
	}
	cout << endl;
}


void test01()
{
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 40));
	m.insert(pair<int, int>(9, 30));

	printMap(m);

	//�ж������Ƿ�Ϊ��
	if (m.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		//����������Ŀ
		//int i = m.size();
		cout << "������Ϊ��,��СΪ��" << m.size()<< endl;
		
	}


	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(7, 90));

	cout << "����ǰ��" << endl;
	printMap(m);
	printMap(m1);

	cout << "������ " << endl;
	m1.swap(m);
	printMap(m);
	printMap(m1);
	

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺
//ͳ�ƴ�С   --size
//�ж��Ƿ�Ϊ��  --empty
//��������     --swap