#include<iostream>
using namespace std;
#include<list>
#include<algorithm>//sort������Ҫʹ�ñ�׼�㷨ͷ�ļ�

//list ��ת�����򣬹�������
//�������е�Ԫ�ط�ת���Լ��������е����ݽ�������

//����ԭ�ͣ�
//reverse();     //��ת����
//sort();        //��������

void printList(const list<int>&L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";

	}
	cout << endl;
}

bool myCompare(int v1, int v2)
{
	//���򣬾��õ�һ����>�ڶ�����
	return v1 > v2;
}

void test01()
{
	list<int>L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(4);
	L.push_back(7);
	L.push_back(50);

	printList(L);

	//��ת��
	L.reverse();
	printList(L);

	////ʹ��sort()��������;
	//cout << "sort��������" << endl;
	//sort(L.begin(), L.end());//���в�֧��������ʵ��������������������ñ�׼�㷨
	//						//��֧��������ʵ��������������ڲ����ṩһЩ��Ӧ�㷨
	//printList(L);//��һ�ڼ��뱨��


	L.push_back(-10);
	//�����
	L.sort();//Ĭ�ϵ�������򣬴�С���� ����
	cout << "ʹ��L.sort()Ĭ�Ϸ�ʽ����:" << endl;
	printList(L);

	L.sort(myCompare);
	cout << "ʹ�ý���ʽ������" << endl;
	printList(L);
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺
//��ת  --reverse
//����  --sort(��Ա������