#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>//��׼�㷨ͷ�ļ�,����������sort������Ҫ��ͷ�ļ�

//deque�������򣬹���������
//�����㷨ʵ�ֶ�deque������������

//�㷨��
//sort(iterator beg,iterator end) //��beg��end������Ԫ�ؽ�������

void printDuque(deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d;
	
	d.push_back(1000);
	d.push_back(20);
	d.push_back(30);
	d.push_back(110);
	d.push_back(120);
	d.push_back(150);

	printDuque(d);

	//����sortĬ����������ǣ���С���� ����
	//����֧��������ʵĵ�����������������������sort�㷨ֱ�Ӷ����������
	//vector����Ҳ��������sort��������
	sort(d.begin(),d.end());
	cout << "�����" << endl;
	printDuque(d);
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺sort�㷨�ǳ�ʹ�ã�ʹ��ʱ����ͷ�ļ�algorithm����