#include<iostream>
#include<string>
using namespace std;
//��Ա��������Ϊ˽��
//1�������Լ����ƶ�дȨ��
//2������д���Լ�����ݵ���Ч��

//�������
class Person
{
public:
	//��������
	void setName(string name)
	{
		m_Name=name;
	}

	//��ȡ����
	string getName()
	{
		return m_Name;
	}
	//��ȡ���䣬ֻ��
	int getAge()
	{
		//m_Age=0;//��ʼ��Ϊ0
		return m_Age;
	}
	void setAge(int age)
	{
		if(age<0||age>150)
		{
			m_Age=0;
			cout<<"��������"<<endl;
			return;
		}
		else
		m_Age=age;
	}

	//������ˣ�ֻд
	void setLover(string lover)
	{
		m_Lover=lover;
	}

private:
	//����   �ɶ���д
	string m_Name;
	//����   ֻ������д��  ������޸����䣬���䷶Χ������0��150֮��
	int m_Age;
	//����   ֻд
	string m_Lover;

};

int main()
{
	Person p;
	p.setName("����");

	cout<<"����Ϊ��  "<<p.getName()<<endl;

	//p.m_Age=18;
	p.setAge(18);//�����ַ�ʽ������䶼�Ǵ�ģ���Ϊû�ж��嵽?//Ϊɶ�Ҳ��Կ������18�ģ�200515
	cout<<"����Ϊ��  "<<p.getAge()<<endl;

	//��������Ϊ�Ծ�
	p.setLover("�Ծ�");
	//��������
	p.setAge(1000);
	system("pause");
	return 0;
}
