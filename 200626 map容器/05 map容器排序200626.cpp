#include<iostream>
#include<map>

using namespace std;

//map������Ĭ���������Ϊ������keyֵ���д�С��������������θı��������

//��Ҫ�����㣺
//���÷º��������Ըı��������

class Mycompare
{
public:
	bool operator()(int v1, int v2) {
		//����
		return v1 > v2;
	}
};


void test01()
{
	map<int, int>m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(3, 20));
	m.insert(make_pair(2, 40));
	m.insert(make_pair(4, 90));
	m.insert(make_pair(6, 190));

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << " value= " << it->second << endl;
	}
	cout << endl;

	map<int, int,Mycompare>m1;

	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(3, 20));
	m1.insert(make_pair(2, 40));
	m1.insert(make_pair(4, 90));
	m1.insert(make_pair(6, 190));

	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << "key= " << it->first << " value= " << it->second << endl;
	}
	cout << endl;
	//�ı�������򣬳��ִ����set�ȵ������ı����������ֵĴ���һ��200626

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺
//���÷º�������ָ��map�������������    //�������ԭ��δ֪200626
//�����Զ����������ͣ�map����Ҫָ�������������set������ͬ