#include"speechManager.h"
//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������  --200705
	this->initSpeech();

	//����ѡ��  --200705
	this->createSpeaker();

	//��ȡ�����¼  --200708
	this->loadRecord();


}

//��ʾ�˵�  --200705
void SpeechManager::show_Menu()
{
	cout << "*************************************" << endl;
	cout << "************��ӭ�μ�����*************" << endl;
	cout << "*********1����ʼ�ݽ�����*************" << endl;
	cout << "*********2���鿴�����¼*************" << endl;
	cout << "*********3����ձ�����¼*************" << endl;
	cout << "*********0���˳�����ϵͳ*************" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	
}

//�˳�����  --200705
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//ʹ�øú���ʵ���˳�����
}

//��ʼ�����ĳ�Ա���� --200705
void SpeechManager::initSpeech()
{
	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;

	//��ʼ����¼����  ���û�г�ʼ��������bug  --200709
	this->m_Record.clear();
}

//����������Ա   --200705
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ�ţ����ŵ�v1������
		//12��ѡ��
		this->v1.push_back(i + 10001);

		//ѡ�ֱ��  �Լ���Ӧ��ѡ��  ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));//��������ź�������ϵ����
	}
}

//��ʼ����  --200705
void SpeechManager::startspeech()
{
	//��һ�ֱ���
	//1����ǩ
	this->speechDraw();    //--200705

	//2������
	this->speechContest();   //--200706

	//3����ʾ�������
	this->showScore();     //--200707

	//�ڶ��ֱ���
	this->m_Index++;     //--200707

	//1����ǩ
	this->speechDraw();    //--200707

	//2������
	this->speechContest();   //--200707

	//3����ʾ���ս��
	this->showScore();      //--200707

	//4���������
	this->saveRecord();     //--200707

	//���ñ�������ȡ��¼  �Խ������δʵʱ���µ�bug   --200709  
	//��ʼ������  
	this->initSpeech();
	//����ѡ�� 
	this->createSpeaker();
	//��ȡ�����¼  
	this->loadRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::speechDraw()
{
	cout<<"��<<"<<this->m_Index<<">>�ֱ���ѡ�����ڳ�ǩ"<<endl;//!!!!!!!!!!!!!!һ���µ�������ʽ
	cout << "-----------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->m_Index == 1)
	{
		//��һ�ֱ���
		random_shuffle(v1.begin(), v1.end());//���ұ���ѡ�ֱ�ŵ�����
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";

		}
		cout << endl;
		
	}
	else
	{
		//�ڶ��ֱ���
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";

		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	system("pause");
	cout << endl;
}

//����  --200706
void SpeechManager::speechContest()
{
	cout << "-------------��" << this->m_Index << "����ʽ������----------------" << endl;
	multimap<double,int,greater<double>> groupScore;   //��ʱ����������key������valueѡ�ֱ��

	int num = 0;           //��¼��Ա����6��Ϊһ��

	vector<int>v_Src;     //��������Ա����
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end();it++)
	{
		num++;

		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//600~1000
			//cout<<score<<" ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());      //����
		d.pop_front();         //ȥ����߷�
		d.pop_back();          //ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);     //��ȡ�ܷ�
		double avg = sum / (double)d.size();                   //��ȡƽ����


		//cout << "��ţ�" << *it << "ѡ�֣�" << this->m_Speaker[*it].m_Name << "��ȡƽ����Ϊ��" 
		//	<< avg << endl;//��ӡ����

		//ÿ����ƽ����,��ƽ���ַŵ�map������/��������ݷ��뵽��ʱС��������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//6��Ϊһ�飬����ʱ��������
		groupScore.insert(make_pair(avg, *it));//key�ǵ÷֣�value�Ǿ���ѡ�ֱ��

		//ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������" << endl;

			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); 
				it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << "������" << this->m_Speaker[it->second].m_Name
					<< "�ɼ���" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}
			int count = 0;

			//ȡ��ǰ�������ŵ����������汣��
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();
			cout << endl;

		}

	}
	cout << "---------��" << this->m_Index << "�ֱ������-----------" << endl;
	system("pause");
}

//��ʾ�������  --200707
void SpeechManager::showScore()
{
	cout << "----------��" << this->m_Index << "�ֽ�������ѡ����Ϣ���£�-------------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << "������" << m_Speaker[*it].m_Name 
			<< " �÷֣�" << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

//��������    --200707
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out|ios::app);//������ķ�ʽ���ļ�,�´�ʹ��׷�ӷ�ʽ�������    
											  //Ҳ����ʹ��׷�ӷ�ʽд�ļ�

	//��ÿ��������д���ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ�����" << endl;

	//�м�¼�ˣ��ļ���Ϊ�� ������������ļ�������ʾ�ļ�Ϊ�յ�bug  --200709
	this->fileIsEmpty = false;

}

//�鿴��¼   --200708
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);     //���������󣬶�ȡ�ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())//�ж��Ƿ�����ļ�β��
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch);//�ѸղŶ�ȡ�ĵ����ַ�   �Ż�ȥ

	string data;

	int index = 0;

	while (ifs >> data)
	{
		//cout<<data<<endl;
		vector<string>v;

		int pos = -1;//����","λ�õı���
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);    //��0��ʼ����  ","
			if (pos == -1)
			{
				break;//�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ��ˣ����зָ
														  //����1 ��ʼλ�ã�����2  ��ȡ����

			v.push_back(tmp);
			start = pos + 1;

		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	//{
	//	cout << it->first << "�ھ���ţ�" << it->second[0] << " ������" << it->second[1] << endl;
	//}

}

//�鿴��¼����   --200708
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����¼Ϊ�գ�" << endl;
	}//����鿴ʱ�ļ�Ϊ�ջ��߲�����û����ʾ��bug   --200709
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��" <<
				" �ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
				<< "�Ǿ����:" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
				<< " ������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}

//��ռ�¼   --200710
void SpeechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ��  ios::trunc  ��������ļ�����ɾ���ļ������´����������ļ��򿪷�ʽ���ﵽɾ����¼Ŀ�ģ�
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->initSpeech();

		//����ѡ��
		this->createSpeaker();

		//��ȡ�����¼
		this->loadRecord();

		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}


//��������   --200705
SpeechManager::~SpeechManager()
{

}