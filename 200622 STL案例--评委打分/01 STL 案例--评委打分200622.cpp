#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>


//����������
//��5��ѡ�֣�ABCDE��10����ί�ֱ��ÿһ��ѡ�ֽ��д�֣�ȥ����߷֣�
//ȥ����ί��ͷ֣�ȡƽ����

//ʵ�ֲ���
//1������5��ѡ�֣��ŵ�vector�����У�
//2������������ȥ��ÿһ��ѡ�֣�ִ��forѭ�������԰�10����ί��ֱ��浽deque������
//3��sort�㷨��deque �����з�������ȥ����߷ֺ���ͷ�

//4��deque��������һ�飬�ۼ��ܷ�
//5����ȡƽ����

//������Ա��
class Person 
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;//����
	int m_Score;//ƽ����
};

//������Ա
void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";//ѡ�ֵ�����
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);
		//cout << p.m_Name << " " << p.m_Score << endl;

		//cout << name<< " "<<score<<endl;//��֤p�������Ƿ�ֵ
		//��������person����ŵ�������

		v.push_back(p);
		//cout << v[i].m_Name << " " << v[i].m_Score << endl;

	}

}//��������д���û���ҳ�ԭ��200622      //ò��û�������ˣ�����200706

//���
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί�ķ���������deque������
		deque<int>d;

		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//40~100
			d.push_back(score);
		}

		//cout << "ѡ�֣� " << it->m_Name << "��֣�" << it->m_Score << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit<<" ";
		//}

		//����
		sort(d.begin(), d.end());

		//ȥ����ߺ���ͷ�
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;//�ۼ�ÿ����ί�ķ���
		}
		int avg = sum / d.size();

		//��ƽ���ָ�ֵ��ѡ������
		it->m_Score = avg;
		
	}
}

//��ʾ����
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << it->m_Name << " ������" << it->m_Score << endl;
	}
}

int main()
{
	//���������,����ʹ��ÿ�����г������ɵ�ѧ����ֶ���һ����
	srand((unsigned int)time(NULL));

	//1������5��ѡ��
	vector<Person>v;//���ѡ�������

	createPerson(v);

	//����
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "������"<<(*it).m_Name << " ������" << (*it).m_Score<< endl;
	//}//����Ǵ����200622  ԭ����Person������Ĺ��캯����Ա�����ˣ���ѷ�����ֵ�������ˡ�200623

	//2����5��ѡ�ִ��
	setScore(v);



	//3����ʾ���÷�
	showScore(v);

	system("pause");
	return 0;
}