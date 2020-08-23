#include"manager.h"

//--200712
//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ  --200714
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������
	this->initVector();

	//��ʼ��������Ϣ  --200715
	ifstream ifs;
	
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;

	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ" << vCom.size() << endl;//--200715

}

//ѡ��˵�
void Manager::operMeun()
{
	//--200714
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|       1 ������˺�          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|       2 ���鿴�˺�          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|       3 ���鿴����          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|       4 �����ԤԼ          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|       0 ��ע����¼          |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "��ѡ�����Ĳ���:" << endl;
}

//����˺�
void Manager::addPerson()
{
	//--200714
	cout << "��������ӵ��˺�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;
	string errorTip;//�ظ�ʱ��������ʾ  --200714

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ������������룡";
	}
	ofs.open(fileName, ios::out | ios::app);//����׷�ӷ�ʽд�ļ�
	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)   //--200714
	{
		cin >> id;
		bool ret=checkRepeat(id, select);
		if (ret)  //���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");

	ofs.close();

	//���ó�ʼ�������ӿڣ����»�ȡ�ļ�������  --200715
	this->initVector();
}

//����������Ϣ��ӡ   --200715
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ����:" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}


//�鿴�˺�
void Manager::showPerson()
{
	//--200715
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;

	cin >> select;//�����û�ѡ��  

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(),vStu.end(),printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");

}

//�鿴������Ϣ
void Manager::showComputer()
{
	//--200715
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " �������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	//--200715
	ofstream ofs(ORDER_FILe, ios::trunc);//����ļ�
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");

}

//��ʼ������
void Manager::initVector()  //--200714
{
	//ȷ���������
	vStu.clear();
	vTea.clear();

	//��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();//ѧ����ʼ��

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}


//����ظ�  ����:(����id,��������) ����ֵ:(true �������ظ���false����û���ظ�)
//--200714
bool Manager::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

