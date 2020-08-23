//���ò����㷨��ѧϰĿ�꣺
//���ճ��õĲ����㷨

//�㷨��飺
//find          //����Ԫ��
//find_if       //����������Ԫ��
//adjacent_find   //���������ظ�Ԫ��

//binary_search    //���ֲ��ҷ�,�еĻ��ͷ����棬���򷵻ؼ�
//count            //ͳ��Ԫ�ظ���
//count_if         //������ͳ��Ԫ�ظ���


#include<iostream>
#include<vector>
#include<string>

using namespace std;

//find  ����������
//����ָ��Ԫ�أ��ҵ�����ָ��Ԫ�صĵ��������Ҳ������ؽ���������end()

//����ԭ�ͣ�
//find(iterator beg,iterator end,value);
//��ֵ����Ԫ�أ��򷵻�ָ��λ�õ��������Ҳ����ͷ��ؽ���������λ��
//beg��ʼ������
//end����������
//value ���ҵ�Ԫ��


//find

//����  ������������
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//���� ������ �Ƿ���  5 ���Ԫ��
	vector<int>::iterator pos= find(v.begin(), v.end(), 5);

	if (pos != v.end())
	{
		cout << "�ҵ���Ԫ�أ�" << *pos << endl;
	}
	else
	{
		cout << "�����ڸ�Ԫ��" << endl;
	}
}

class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//���� ==  ���õײ�find ֪����ζԱ�  person  ��������

	bool operator==(const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};


//����  �Զ�����������
void test02()
{
	vector<Person>v;

	//��������
	Person p1("aaa", 10);
	Person p2("bbb", 310);
	Person p3("ccc", 30);
	Person p4("ddd", 550);

	//�ŵ�������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("aaa", 10);//�������Ա

	//�����Զ����������ͣ��漰�Ա����ͣ���Ҫ�����Աȹ��򣬷���find�ײ��ǲ�֪����ô�Աȵ�
	vector<Person>::iterator pos = find(v.begin(), v.end(), pp);//������������û�к�pp��Աһ��

	if (pos != v.end())
	{
		cout << "�ҵ��ó�Ա��" << endl;
		cout << "���䣺" << pos->m_Age << " ������" << pos->m_Name << endl;
	}
	else {
		cout << "δ�ҵ��ó�Ա" << endl;
	}
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//�ܽ᣺����find��������������ָ����Ԫ�أ����ص��ǵ�����
//find�����������Զ����������ͣ���Ҫ����  ==  �ţ�����ײ�֪��   �Աȵ�   ����