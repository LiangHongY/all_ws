#include"workerManager.h"

WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNun = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ����¼����
		this->m_EmpNun = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ����Ҽ�¼����200323
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ�� " << num << endl;
	this->m_EmpNun = num;   

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNun];
	//���ļ�������浽������
	this->init_Emp();

	////���Դ���200323
	//for (int i = 0; i < this->m_EmpNun; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
	//		<< "������ " << this->m_EmpArray[i]->m_Name
	//		<< "���ű�ţ� " << this->m_EmpArray[i]->m_DepthId << endl;
	//}
}


//չʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "**********************" << endl;
	cout << "***��ӭʹ��ְ��ϵͳ***" << endl;
	cout << "***0���˳��������***" << endl;
	cout << "***1������ְ����Ϣ***" << endl;
	cout << "***2����ʾְ����Ϣ***" << endl;
	cout << "***3��ɾ����ְְ��***" << endl;
	cout << "***4���޸�ְ����Ϣ***" << endl;
	cout << "***5������ְ����Ϣ***" << endl;
	cout << "***6�����ձ������***" << endl;
	cout << "***7����������ĵ�***" << endl;
	cout << "*********************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����(����һ���˳�ϵͳ������������������ö����˳���ǰ����)
}

//���ְ��

//�û����������ʱ�򣬿��ܻᴴ����ͬ�����ְ��
//����뽫���в�ͬ�����Ա����ָ��ά����һ��������
//������ڳ�����ά������������ȵ����飬���Խ����鴴���ڶ�����������Worker **��ָ��ά��//20200422
void WorkerManager::Add_Emp()
{
	cout << "���������ְ�������� " << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNun + addNum;//�¿ռ�����=ԭ����¼����+��������//����
		//this���汨�﷨����ԭ���ǣ����->�����ý�ȥ�ģ�������ʹ��  .  ���������Զ�װ����

		//cout << newSize << endl;

		//�����¿ռ�
		Worker ** newSpace = new Worker * [newSize];

		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNun; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		int b[1000];
		for (int i = 0; i < 1000; i++)
		{
			b[i] = 0;
		}//���ڼ�¼������ӵ�id����ֹ���������ͬ��ID  20200423

		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			while (1) 
			{
				cout << "�������" << i + 1 << " ��Ա�����:" << endl;
				cin >> id;
				int ret = this->IsExist(id);
				int c = 1;

				for (int i = 0; i < 1000; i++)
				{
					if (b[i] == id)
					{
						c = 0;
					}
				}

				//cout << id;
				if ((ret != -1)||(c==0))
				{
					cout << "����Ѵ��ڣ�����������" << endl;
				}
				else
					break;
			}//��������ѭ����û�����b[]����ʱ�����Ա���ԭ���ĵ��д��ڱ�ų�Ա���ٴ��ظ������������������ͬһ�ζ�������ͬ��ų�Ա��û�а취ʶ��ġ�20200423
			b[i] = id;//��¼����ӵ�ID�����151�е�bug��20200423



			cout << "�������" << i + 1 << " ��Ա������:" << endl;
			cin >> name;
			
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ܲ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1://��ְͨ��
				worker = new Employee(id, name, 1);
				break;
			case 2://����
				worker = new Manager(id, name, 2);
				break;
			case 3://�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNun + i] = worker;
			//cout <<"aaaaaa" << endl;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNun = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//��������
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	//��������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//������ķ�ʽ���ļ�---д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNun; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id<< " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DepthId << endl;//¼�빤����Ա������ԭ��δ֪��20200319//��103����˸ò��Ե�󣬷��ֿ���д���ݽ��ļ������ˣ�����ע�͵�������Ե㣬
		                                              //����Ҳ�ǿ���д���ݽ�ȥ�ˣ�û�г���¼��ʧ�ܱ��������20200422
	}

	//�ر��ļ�
	ofs.close();
}
//ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�����

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs>>id&&ifs>>name&&ifs>>dId)
	{
		//ͳ����������
		num++;
	}
	return num;
	cout << num << endl;
}

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//��ͨԱ��
		{
			worker = new Employee(id ,name,dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();//�ر��ļ�

}

//չʾְ��200326
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ�գ�" << endl;
	}
	else
	{
		for( int i=0;i < m_EmpNun; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�������������
	system("pause");
	system("cls");
}//�����쳣����һ����if����쳣

//ɾ��ְ��200326
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��
		cout << "������Ҫɾ��ְ����ţ� " << endl;
		int id = 0;
		cin >> id;

		int index=this->IsExist(id);

		if (index != -1)//˵��ְ�����ڣ�����ɾ��indexλ�õ�Ա��
		{
			for (int i = index; i < this->m_EmpNun - 1; i++)
			{
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNun--;//���������м�¼��Ա����
			//ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ���" << endl;

		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	//���������������
	system("pause");
	system("cls");
}//�����쳣��ÿ�ζ��Զ�ɾ��һ���ˣ�Ȼ��Ҳû����ʾɾ���ɹ�����ʾ���ݲ���Ҳ���쳣��
//��ʹ�ļ�Ϊ��Ҳû���κ���ʾ���Ʋ��ǵ���save����Ҳ�������Ա���Ǹ����ർ�µġ���202003xx��
//������������������ʹ���ˣ�save�����߼���û�д���

//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1   200326
int WorkerManager::IsExist(int id)
{
	int index = -1;
	//cout << id << endl;
	//cout << this->m_EmpNun;

	for (int i = 0; i < this->m_EmpNun; i++)
	{
		if ((this->m_EmpArray[i]->m_Id )== id)
		{
			//�ҵ�ְ��
			index =i;
			//cout << this->m_EmpArray[i]->m_Id << endl;
			//cout << index << endl;
			//cout << i << endl;
			break;
		}
		//cout << this->m_EmpNun << endl;//���������������������ڲ��ұ��������ˣ��������й��ܶ���������ʹ���ˡ�����ԭ��δ֪��
		//���ҵĸо��ǣ��������û�ӹ���仰֮ǰ����û���������������������ġ�20200423
	}
	return index;
}

//�޸�ְ��200327
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ұ�ŵ�ְ��
			delete this->m_EmpArray[ret];
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "���ң�" << id << "��Ա������������ְ�����" << endl;
			cin >> newId;

			cout << "��������������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1. ��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;

			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
				
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//����ְ��200327
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//�ҵ���ְ��
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else 
			{
				cout << "��Ա��������" << endl;
			}//����619�е�bug
		}
		else if (select == 2)
		{
			//����ְ��������
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			//�����ж��Ƿ���ҵ���־
			bool flag = false;//Ĭ��δ�ҵ�ְ��

			for (int i = 0; i < m_EmpNun; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" 
						<< this->m_EmpArray[i]->m_Id 
						<< "����Ϣ���£�" << endl;

					flag = true;

					//��ʾ��Ϣ
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;
			}

		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");

}//���ֲ�����ʾ�쳣��

//����ְ���������200328
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		
		for (int i = 0; i < m_EmpNun; i++)
		{
			int minOrMax = i;//������Сֵ�����ֵ�±�

			for (int j = i + 1; j < this->m_EmpNun; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id <this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

          //�ж�һ��ʼ�϶���Сֵ�����ֵ���ǲ��Ǽ�����Сֵ�����ֵ��������ǣ��ͽ�������
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
	}
	cout << "����ɹ���������Ϊ��" << endl;
	this->save();//����������浽�ļ���
	this->Show_Emp();//չʾ����ְ��
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		//��ģʽ ios::trunc ������ڣ�ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNun; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
           //ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;

			this->m_EmpNun = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;

	}
}

//��bug����ʹ�ñ�Ų���Ա����������ʱ��û����ʾ�����ڸ��ˣ����������һ���ʾ20200601   �ѽ��
//��bug������Ҫ������ʱ����������ַ����ͻᵼ�³���������ѭ��200602  ������id����int���ͣ�����д�ַ���������˵��Ӧ�����ַ����Զ�ת��Ϊint�������ѭ����ֱ��������int���͵�id
