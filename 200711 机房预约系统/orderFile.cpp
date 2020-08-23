#include"orderFile.h"

//--200715
//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILe, ios::in);

	string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //机房编号
	string status;    //预约状态

	this->m_size = 0;  //预约记录个数

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs 
		>> stuName && ifs >> roomId && ifs >> status)
	{
		////测试代码
		//cout << date << endl;
		//cout << interval << endl;
		//cout << stuId << endl;
		//cout << stuName << endl;
		//cout << roomId << endl;
		//cout << status << endl;

		string key;
		string value;
		map<string, string> m;
		
		//date:1  截取日期
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);//表示从0号d位置开始截取，截到pos也就是：位置
			value = date.substr(pos + 1, date.size() - pos);//同上
			m.insert(make_pair(key, value));
		}

		//截取时间段
		 pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);   //截取字符的关键字substr
			value = interval.substr(pos + 1, interval.size() - pos);
			m.insert(make_pair(key, value));
		}

		//截取学号
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos);
			m.insert(make_pair(key, value));
		}

		//截取姓名
		 pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos);
			m.insert(make_pair(key, value));
		}

		//截取机房号
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m.insert(make_pair(key, value));
		}

		//截取预约状态
		 pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m.insert(make_pair(key, value));

			//cout << key << endl;
			//cout << value << endl;
		}

		//将小map容器放入大的map容器中
		this->m_orderDate.insert(make_pair(this->m_size, m));
		this->m_size++;

	}
	////测试最大map容器   测试代码  --200715
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

//更新预约记录
void OrderFile::updateOrder()
{
	//  --200716
	if (this->m_size == 0)
	{
		return;  //预约记录为0条，直接退出
	}

	ofstream ofs(ORDER_FILe, ios::out | ios::trunc);
	for (int i = 0; i < m_size; i++)
	{
		ofs << "date:" << this->m_orderDate[i]["date"] << " ";//this...表示访问的是第i条记录下面的date
		ofs << "interval:" << this->m_orderDate[i]["interval"] << " ";//同上
		ofs << "stuId:" << this->m_orderDate[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderDate[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderDate[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderDate[i]["status"] << endl;
	}
	ofs.close();
}