#include<iostream>
#include<map>

using namespace std;

//map���Һ�ͳ�ƣ�����������
//��map�������в��������Լ�ͳ������

//����ԭ�ͣ�
//find(key);  //����key�Ƿ���ڣ������ڣ����ظ�key��Ԫ�صĵ��������������ڣ���
              //����set.end();

//count(key);  //ͳ��key��Ԫ�ظ���


void test01()
{
	map<int, int> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(2, 50));
	m.insert(make_pair(4, 40));

	//����
	map<int, int>::iterator pos = m.find(4);
	
	if (pos != m.end())
	{
		cout << "���ڣ�" << pos->first <<" " <<pos->second<< endl;

		//map��������������ظ���keyԪ�ص����ݣ�����countͳ�ƶ��ԣ����Ҫô0��Ҫô1
		//����multimap������count�Ľ�����п��ܴ���1
		cout << "����Ϊ��" << m.count(4) << endl;
	}
	else
	{
		cout << "������" << endl;
	}

}



int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺
//����  --find  (���ص��ǵ�����)
//ͳ��  --count  ������map���ԣ����0��1��