#include<iostream>
using namespace std;
#include<set>


//set��multiset����ѧϰĿ��
//����set��multiset������

//����
//set�����Բ����ظ������ݣ���multiset����
//set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
//multiset���������ݣ���˿��Բ����ظ�����

//set������multiset����������
void test01()
{
	set<int>s;

	pair<set<int>::iterator,bool> ret=s.insert(10);//����Ƿ����ɹ�

	if (ret.second)//���ص���bool����
	{
		cout << " ��һ�β���ɹ�" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��" << endl;
	}

	ret = s.insert(10);
	if (ret.second)
	{
		cout << " ��2�β���ɹ�" << endl;
	}
	else
	{
		cout << "��2�β���ʧ��" << endl;
	}

	multiset<int>s1;
	
	s1.insert(200);
	s1.insert(200);
	for (multiset<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	

}


int main()
{
	test01();

	system("pause");
	return 0;
}
//����set�������᷵���Ƿ����ɹ������Կ���Ӧ��insert���鿴��Ӧ��Դ������֪����
//����multiset���������᷵���Ƿ����ɹ������ǻ��е���������


//�ܽ�
//�������������ظ����ݣ����Բ���set��
//�����Ҫ�����ظ����ݣ���������multiset