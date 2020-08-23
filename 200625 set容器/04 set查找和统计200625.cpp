#include<iostream>
using namespace std;
#include<set>

//set���Һ�ͳ�ƣ�����������
//��set�������в��������Լ�ͳ������

//����ԭ�ͣ�
//find(key);   //����key�Ƿ���ڣ������ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
//count(key);  //ͳ��key��Ԫ�ظ���

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
	set<int> s;

	s.insert(1);
	s.insert(89);
	s.insert(76);
	s.insert(23);

	printSet(s);

	set<int>::iterator pos = s.find(890);
	if (pos != s.end())
	{
		cout << "�ҵ������� " <<*pos<< endl;
	}
	else
	{
		cout << "δ�ҵ�������" << endl;
	}

	//ͳ��Ԫ�ظ���
	int i = s.count(1);

	//����set�������ԣ�setͳ������Ҫô��0��Ҫô��1
	cout << "����Ϊ��" << i << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}