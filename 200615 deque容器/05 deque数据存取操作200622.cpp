#include<iostream>
using namespace std;

#include<deque>
//deque���ݴ�ȡ����������
//��deque�е����ݴ�ȡ����

//����ԭ�ͣ�
//at(int idx);   //��������idx��ָ������
//operator[];    //��������idx��ָ������
//front();       //���������е�һ������Ԫ��
//back();        //�������������һ������Ԫ��


//���ݴ�ȡ

void printDeque(deque<int>&d)
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

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);

	d.push_front(100);
	d.push_front(203);
	d.push_front(204);
	d.push_front(205);

	//ͨ��[]��ʽ����Ԫ��
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;

	//ͨ��at��ʽ����Ԫ��
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ���ǣ� " << d.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << d.back() << endl;
}


int main()
{
	test01();
	system("pause");
	return 0;
}

//�ܽ᣺
//�����õ�������ȡdeque������Ԫ�أ�[]��atҲ����
//front����������һ��Ԫ��
//back�����������һ��Ԫ��