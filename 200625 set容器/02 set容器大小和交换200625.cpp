#include<iostream>
using namespace std;
#include<set>

//set��С�ͽ���������������
//ͳ��set������С�ͽ���set����

//����ԭ�ͣ�
//size();     //����������Ԫ�ص���Ŀ
//empty();    //�ж������Ƿ�Ϊ��
//swap(st);   //����������������

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test01()
{
	set<int>s;

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(6);

	printSet(s);

	if(s.empty())
	{
		cout << "����������Ϊ��" << endl;
	}
	else
	{
		cout << "���������ݲ�Ϊ�գ�������СΪ��" << s.size() << endl;
	}

	set<int>s1;
	s1.insert(21);
	s1.insert(32);
	s1.insert(12);
	
	cout << "����ǰs1��" << endl;
	printSet(s1);

	cout << "�������s1:" << endl;
	s1.swap(s);
	printSet(s1);
}

int main()
{
	test01();

	system("pause");
	return 0;
}

//set��������ָ����С
//�ܽ᣺
//ͳ�ƴ�С  --size
//�ж��Ƿ�Ϊ��  --empty
//��������     --swap

