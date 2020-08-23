//�Լ���ͨ�õ�������
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//�вι���  ����  ����
	MyArray(int capacity)
	{
		//cout << "Myarray�вι���ĵ���" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//��������T��thisû���Զ�����ѡ�copy��ȥ��
	}

	//��������
	MyArray(const MyArray& arr)
	{
		//cout << "Myarray��������ĵ���" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//this->pAddress = arr.pAddress;//����ǳ����,��������������ظ��ͷ�����

		//���
		this->pAddress=new T[arr.m_Capacity];

		//��arr��������ݿ�������
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}//���TΪ���󣬶��Ұ���ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ���  ����  ���Ǹ�ֵ��
	 //��ͨ���Ϳ���ֱ�� = ����ָ��������Ҫ���

	//operator= ����= ������ ��ֹǳ��������
	MyArray& operator=(const MyArray& arr)//MyArray& ������ ���Խ������Ȳ���a=b=c [���˻��ǲ������������=����]
	{
		//cout << "Myarray��operator=�ĵ���" << endl;
		//���ж�ԭ���Ķ����Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	////����[]�������� arr[0]
	//T& operator [](int index)
	//{
	//	return this->pAddress[index];//������Խ�磬�û��Լ�ȥ����200512
	//}

	//β�巨
	void Push_back(const T& val)
	{
		//�ж������Ƿ���ڴ�С
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//������ĩβ��������
		this->m_Size++;//���������С
	}

	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ�أ���Ϊβɾ���߼�ɾ��
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//ͨ���±귽ʽ����������Ԫ��   ��ֵ����arr[0]=100
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//���������С
	int getSize()
	{
		return this->m_Size;
	}

	//��������
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			//cout << "Myarray�����ĵ���" << endl;
			delete[] this->pAddress;
			this->pAddress=NULL;
		}
	}

private:
	T * pAddress;//ָ��ָ��������ٵ���ʵ����

	int m_Capacity;//��������

	int m_Size;//�����С
};