#include<iostream>
using namespace std;
#include<set>

//set��������ѧϰĿ�꣺
//set����Ĭ���������Ϊ��С����������θı��������

//��Ҫ�����㣺
//���÷º���������i�ı��������

void printSet(const set<int>& s) 
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)//�º���
	{
		return v1 > v2;
	}
};


void test01()
{
	set<int>s1;

	s1.insert(10);
	s1.insert(14);
	s1.insert(54);
	s1.insert(70);
	s1.insert(190);
	s1.insert(9);

	printSet(s1);//Ĭ�������Ǵ�С����

	//ָ�����й���Ϊ�Ӵ�С

	set<int,MyCompare>s2;   //����ָ�����еĹ���

	s2.insert(10);
	s2.insert(14);
	s2.insert(54);
	s2.insert(70);
	s2.insert(190);
	s2.insert(9);

	//printSet(s2);//����ԭ���ǣ�ÿ��������������ר�õĵ�����
	for (set<int, MyCompare>::iterator it = s2.begin();it != s2.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;//����˵ָ������󣬵ײ�������ԭ��δ֪��200625

}


int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺���÷º�������ָ��set�������������
//�Զ���������򱨴�δ���200625