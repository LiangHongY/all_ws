#include<iostream>
#include<map>
using namespace std;

//map�������������飺
//map������Ԫ�ض���pair
//pair�е�һԪ��Ϊkey(��ֵ)�����������ã��ڶ�Ԫ��Ϊvalue��ʵֵ)
//����Ԫ�ض������Ԫ�ص�key��ֵ�Զ�����

//���ʣ�
//map/multimap���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��

//�ŵ㣺
//���Ը���keyֵ�����ҵ�valueֵ
//��keyֵ�������Ϊѧ�ţ�valueֵ���Ϊѧ����ͨ��ѧ�ſ��Կ����ҵ���ѧ����

//map��multimap������
//map���������������ظ���keyֵԪ��
//multimap�������������ظ�keyֵԪ��




//map����͸�ֵ������������
//��map�������й���͸�ֵ����

//����ԭ��

//���죺
//map<T1,T2> mp;       //mapĬ�Ϲ��캯��
//map(const map &mp);  //�������캯��

//��ֵ��
//map& operator=(const map &mp);    //���صȺŲ�����



//map���� ����͸�ֵ

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " " << it->second << endl;
	}
	cout << endl;
}


void test01()
{
	//����map����
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));//ע���������ʱ����ʽ
	m.insert(pair<int, int>(6, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	//����
	printMap(m);

	//��������
	map<int, int>m2(m);
	printMap(m2);

	//��ֵ
	map<int, int> m3;
	m3 = m2;
	printMap(m3);

}


int main()
{
	test01();
	system("pause");
	return 0;
}

//�ܽ᣺map������Ԫ�ض��ǳɶԳ��֣���������ʱ��Ҫʹ�ö���