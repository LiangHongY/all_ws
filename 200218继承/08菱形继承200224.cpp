#include<iostream>
using namespace std;

//������

class Animal
{
public:
	int m_Age;
};
//������̳�  ���Խ�����μ̳�����
//�̳�֮ǰ  ���Ϲؼ��� virtual  ��Ϊ��̳�
//Animal���Ϊ�����

//����
class Sheep :virtual public Animal{};

//����
class Tuo:virtual public Animal{};

//������
class SheepTuo:public Sheep,public Tuo{};

void test01()
{
	SheepTuo st;
	st.Tuo::m_Age = 28;
	st.Sheep::m_Age = 18;
	
	//�����μ̳У���������ӵ����ͬ���ݣ���Ҫ��������������
	cout << "st.Sheep::m_Age=" << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age=" << st.Tuo::m_Age << endl;

	cout << "st.m_Age=" << st.m_Age << endl;//�����������̳йؼ���virtual�����ʹ�õ�

	//����������ݣ�ֻ��һ�ݾͿ����ˣ����μ̳лᵼ�����������ݣ���Դ�˷�
	//ָ��ֻ�Ǳ������һ������Ĳ���ֵ200525
}


int main()
{
	test01();

	system("pause");
	return 0;
}

//�����ݽṹ��ѯ����������ֵ�vbptrָ����һ��ָ��

//�ܽ�
//���μ̳д�������Ҫ����������̳�������ͬ�����ݣ�������Դ�˷��Լ���������
//������̳п��Խ�����μ̳�����

//������������̳����⣬�����virtual�ؼ��ֺ�Sheep�Լ�Tuo���������඼�Ǽ̳�һ����ָ���ˣ�
//����ָ��ͬһ��������Ȼ������Son�̳������������࣬Ȼ����ָ��ͬһ�����������Ա����Ͼ���
//ָ����ͬһ���������Ӷ���������Դ���ظ�ռ�ô������˷ѡ�