//���ļ���������
//1.����ͷ�ļ�   #include<fstream>
//2������������  ifstream ifs;
//3�����ļ����ж��ļ��Ƿ�ɹ���    ifs.open("�ļ�·��",�򿪷�ʽ);
//4.�����ݣ����ַ�ʽ��ȡ 
//5.ofs.close();



#include<iostream>
using namespace std;
#include<fstream>
#include<string>

//�ı��ļ�  ���ļ�

void test01()
{
	//1������ͷ�ļ�fstream

	//2.����������

	ifstream ifs;

	//3.���ļ������ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);//out��ʾд���ļ���in��ʾ��ȡ�ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//4.������

	////��һ��
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	////�ڶ���
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//������
	string buf;
	while (getline(ifs, buf))//���Ա�������ԭ��δ֪20200304;���Ծ�����������20200315
	{
		cout << buf << endl;
	}
	
	////������
	//char c;
	//while ((c = ifs.get()) != EOF)//EOF   ��ʾ   end  of  file
	//{
	//	cout << c ;//���ﲻ��дendl
	//}

	//5.�ر��ļ�
	ifs.close();
}

int main()
{
	test01();
	system("pause");
	return 0;
}

//���ļ���������ifstream,����fstream��
//����is_open���������ж��ļ��Ƿ�򿪳ɹ�
//close�ر��ļ�