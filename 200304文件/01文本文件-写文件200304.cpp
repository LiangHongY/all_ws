//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}
//C++�ж��ı��ļ�������Ҫ����ͷ�ļ�<fstream>
//�ļ����ͷ�Ϊ����
//1���ı��ļ����ļ����ı���ASCII����ʽ�洢�ڼ������
//2���������ļ����ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�����

//�����ļ�������
//1��ofstream:д�ļ�
//2��ifstream:���ļ�
//3��fstream:��д�ļ�

//д�ļ���������
//1.����ͷ�ļ�   #include<fstream>
//2������������  ofstream ofs;
//3�����ļ�    ofs.open("�ļ�·��",�򿪷�ʽ)
//4.д����  ofs<<"д�������";
//5.ofs.close();

//ios::in    Ϊ���ļ������ļ�
//ios::out   Ϊд�ļ������ļ�
//ios::ate   ��ʼλ��:�ļ�β
//ios::app   ׷�ӷ�ʽд�ļ�
//ios::trunc ����ļ����ڣ�����ɾ�����ٴ���
//ios::binary �����Ʒ�ʽ
//ע�⣺�ļ��򿪷�ʽ�������ʹ�ã�����  |  ������
//����:�ö����Ʒ�ʽд�ļ�  ios::binary | ios::out

#include<iostream>
using namespace std;
#include<fstream>//ͷ�ļ�����

//�ı��ļ�  д�ļ�
void test01()
{
	//1������ͷ�ļ�fstream

	//2.����������

	ofstream ofs;

	//3.ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);

	//4.д����
	ofs << "����������" << endl;

	//5.�ر��ļ�
	ofs.close();
}


int main()
{
	test01();
	system("pause");
	return 0;
}

//�ܽ�
//�ļ������������ͷ�ļ�fstream��
//���ļ���������ofstream������fstram��
//���ļ�ʱ����Ҫָ�������ļ���·�����Լ��򿪷�ʽ
//���� <<  �������ļ���д����
//������ϣ�Ҫ�ر��ļ�