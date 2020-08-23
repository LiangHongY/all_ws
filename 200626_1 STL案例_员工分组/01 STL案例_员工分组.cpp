//��������
//��˾��Ƹ��10��Ա����ABCDEFGHI����10��Ա�����빫˾֮����Ҫָ��Ա����
//�Ǹ����Ź���
//Ա����Ϣ�У�����  ������ɣ����ŷ�Ϊ���߻����������з�
//�����10��Ա�����䲿�ź͹���

//ͨ��multimap������Ϣ����   key�����ű�ţ�  value��Ա����
//�ֲ�����ʾԱ����Ϣ


//ʵ�ֲ���
//1������10��Ա�����ŵ�vector������
//2������vector������ȡ��ÿ��Ա�������������
//3������󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue���ŵ�multimap������
//4���ֲ�����ʾԱ����Ϣ






#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>

using namespace std;


#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;//10000~19999

		//��Ա���ŵ�������
		v.push_back(worker);
	}
}

//Ա������
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����������ű��
		int deptId = rand() % 3;//0\1\2

		//��Ա�����������
		//key��ʾ���ű�ţ�value��ʾ����Ա��
		m.insert(make_pair(deptId,*it));
	}
}

//��ʾԱ��
void showWorkerGroup(multimap<int,Worker>&m)
{
	cout << "�߻����ţ�" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
	cout << endl;

	cout << "�������ţ�" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
	cout << endl;

	cout << "�з����ţ�" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
	cout << endl;
}


int main()
{
	//ϵͳʱ����ʵ���
	srand((unsigned int)time(NULL));

	//1������Ա��
	vector<Worker>vWorker;
	createWorker(vWorker);

	////���Դ���Ա��
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	//	cout << "������" << it->m_Name << "  ���ʣ�" << it->m_Salary << endl;
	//}
	
	//2��Ա������
	multimap<int, Worker>mWorker;
	setGroup(vWorker,mWorker);

	//3��������ʾԱ��
	showWorkerGroup(mWorker);

	system("pause");
	return 0;
}


//������᣺
//�������̫�����ˣ�������
//ͨ���궨������Ӧ��������ɵĲ��ű��
//multimap�����������һ��vector������Ա����������Ӧ�ã�
//Ӧ��map�����е�find()  count() ������������������ʾԱ��Ӧ�ã�

//�ص��ǣ���̫���ˣ���Щ�������ʺ�����û�з�Ӧ���Ժ��У�ֻ����ʦ˵��������⵽��Щ����
//200626