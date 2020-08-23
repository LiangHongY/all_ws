#include"orderFile.h"

//--200715
//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILe, ios::in);

	string date;      //����
	string interval;  //ʱ���
	string stuId;     //ѧ�����
	string stuName;   //ѧ������
	string roomId;    //�������
	string status;    //ԤԼ״̬

	this->m_size = 0;  //ԤԼ��¼����

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs 
		>> stuName && ifs >> roomId && ifs >> status)
	{
		////���Դ���
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;

		string key;
		string value;
		map<string, string> m;
		
		//date:1  ��ȡ����
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);//��ʾ��0��dλ�ÿ�ʼ��ȡ���ص�posҲ���ǣ�λ��
			value = date.substr(pos + 1, date.size() - pos);//ͬ��
			m.insert(make_pair(key, value));
		}

		//��ȡʱ���
		 pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);   //��ȡ�ַ��Ĺؼ���substr
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		//��ȡѧ��
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));
		}

		//��ȡ����
		 pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));
		}

		//��ȡ������
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}

		//��ȡԤԼ״̬
		 pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));

			//cout << key << endl;
			//cout << value << endl;
		}

		//��Сmap����������map������
		this->m_orderDate.insert(make_pair(this->m_size, m));
		this->m_size++;

	}
	////�������map����   ���Դ���  --200715
	//for (map<int, map<string, string>>::iterator it = m_orderDate.begin();
	//	it != m_orderDate.end(); it++)
	//{
	//	cout << "key=" << it->first << "value=" << endl;
	//	for (map<string, string>::iterator mit = it->second.begin();
	//		mit != it->second.end(); mit++)
	//	{
	//		cout << mit->first << " " << mit->second << " ";
	//	}
	//	cout << endl;
	//}


}

//����ԤԼ��¼
void OrderFile::updateOrder()
{
	//  --200716
	if (this->m_size == 0)
	{
		return;  //ԤԼ��¼Ϊ0����ֱ���˳�
	}

	ofstream ofs(ORDER_FILe, ios::out | ios::trunc);
	for (int i = 0; i < m_size; i++)
	{
		ofs << "date:" << this->m_orderDate[i]["date"] << " ";//this...��ʾ���ʵ��ǵ�i����¼�����date
		ofs << "interval:" << this->m_orderDate[i]["interval"] << " ";//ͬ��
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << endl;
	}
	ofs.close();
}