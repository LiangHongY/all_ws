#include<iostream>
using namespace std;

//���ص��������

//�Զ�������
class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����ǰ��++�����,�������ã�ָ����17�е�&��Ϊ��һֱ��ͬһ�����ݽ��е�������

	MyInteger& operator++()
	{
		//�Ƚ���++����
		m_Num++;

		//����������
		return *this;
	}

	//���غ���++�����
	//void operator++(int)  int��ʾռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int)//ע������û�м� & �ţ���ʾ���ص���ֵ��������
	{
		//�ȼ�¼��ʱ���
		MyInteger temp = *this;
		//�����
		m_Num++;
		//����¼���������
		return temp;

	}


private:
	int m_Num;
};

//���� << �����
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num;
	return cout;
}

void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test02()
{
	MyInteger myint;
	cout << (myint++)++ << endl;//������д����++��û������ģ���Ϊ������õ���ֵ���أ����Ƕ�
	//ͬһ��myint���в����ģ��൱��ÿ��myint����ȥ����Ϊԭʼ��0�ˡ�
	cout << myint << endl;
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}
//С�᣺ǰ�õ������ص������ã����õ�������ֵ