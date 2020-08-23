#include"teacher.h"

//--201012
//Ĭ�Ϲ���     
Teacher::Teacher()
{

}

//�вι��죨ְ����š����������룩
Teacher::Teacher(int empId, string name, string pwd)
{
	//  -200716
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

//�˵�����
void Teacher::operMeun()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      1���鿴����ԤԼ     |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      2�����ԤԼ         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t|      0��ע����¼         |\n";
	cout << "\t\t|                          |\n";
	cout << "\t\t----------------------------\n";
	cout << "��ѡ�����Ĳ�����" << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	//--200716
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "��";

		cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"];
		cout << "ʱ�Σ�" << (of.m_orderDate[i]["intercal"] == "1" ? "����" : "����");
		cout << "ѧ�ţ�" << of.m_orderDate[i]["stuId"];
		cout << "������" << of.m_orderDate[i]["stuName"];
		cout << "������" << of.m_orderDate[i]["roomId"];
		string status = "״̬";//0  ȡ��ԤԼ��1  ����� ��2  ��ԤԼ��-1  ԤԼʧ�� 

		if (of.m_orderDate[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderDate[i]["status"] == "2")
		{
			status += "�Ѿ��ɹ�ԤԼ";
		}
		else if (of.m_orderDate[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ�Ѿ�ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;

	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�ȴ���˵�ԤԼ��¼���£�" << endl;

	vector<int>v;
	int index = 0;

	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderDate[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";

			cout << "ԤԼ���ڣ���" << of.m_orderDate[i]["date"];
			cout << "ʱ�Σ�" << (of.m_orderDate[i]["intercal"] == "1" ? "����" : "����");
			cout << "ѧ�����:" << of.m_orderDate[i]["stuId"];
			cout << "ѧ������" << of.m_orderDate[i]["stuName"];
			cout << "������" << of.m_orderDate[i]["roomId"];
			string status = "״̬";//0ȡ��ԤԼ��1����У�2�Ѿ�ԤԼ��-1ԤԼʧ��
			if (of.m_orderDate[i]["status"] == "1")
			{
				status += "״̬�������";
			}
			cout << status << endl;
		}
	}

	cout << "��������˵�ԤԼ��¼��0��ʾ����" << endl;
	int select = 0;   //�û�ѡ��
	int ret = 0;  //����ԤԼ�����¼
	while (true)
	{
		cin >> select;
		if (select == 0)
		{
			break;
		}
		else
		{
			cout << "��������˽��" << endl;
			cout << "1��ͨ��" << endl;
			cout << "2����ͨ��" << endl;
			cin >> ret;

			if (ret == 1)
			{
				//ͨ��
				of.m_orderDate[v[select - 1]]["status"] = "2";
			}
			else
			{
				//��ͨ��
				of.m_orderDate[v[select - 1]]["status"] = "-1";
			}
			of.updateOrder();//���¼�¼
			cout << "�����ϣ�" << endl;
			break;
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
	
}