#include"stdafx.h"
#include<iostream>
#include<string>

using namespace std;

struct Hero
{
	//��������
	string name;
	//����
	int age;
	//�Ա�
	string sex;
};

//ð������ʵ���������������
void bubbleSort(struct Hero heroArray[],int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-1-i;j++)
		{
			//���j С���Ԫ�ش���j+1�±�Ԫ�ص����䣬��������Ԫ��
			if(heroArray[j].age>heroArray[j+1].age)
			{
				struct Hero temp=heroArray[j];
				heroArray[j]=heroArray[j+1];
				heroArray[j+1]=temp;
			}
		}
	}
}
//��ӡ������������Ϣ
void printhero(struct Hero heroArray[ ],int len)
{
	for(int i=0;i<len;i++)
	{
			cout<<"������  "<<heroArray[i].name<<"   ���䣺  "<<heroArray[i].age<<"   �Ա�:   "<<heroArray[i].sex<<endl;
	}
}

int main()
{
	//1�����Ӣ�۵Ľṹ��

	//2������������5��Ӣ����Ϣ
	struct Hero heroArray[5]=
	{
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",21,"��"},
		{"������",20,"��"},
		{"����",19,"Ů"},
	};

	int len=sizeof(heroArray)/sizeof(heroArray[0]);
	for(int i=0;i<len;i++)
	{
		cout<<"������  "<<heroArray[i].name<<"   ���䣺  "<<heroArray[i].age<<"   �Ա�:   "<<heroArray[i].sex<<endl;

	}
	cout << endl;

	//3��������������򣬰������������������
	bubbleSort(heroArray,len);
	//4�������������ӡ���
	printhero(heroArray,len);

	system("pause");
	return 0;
}