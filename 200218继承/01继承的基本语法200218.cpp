//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

//��ͨʵ��ҳ��

////Javaҳ��
//class Java
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
//	}
//
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++��..�����������б�" << endl;
//	}
//
//	void content()
//	{
//		cout << "Javaѧ����Ƶ" << endl;
//	}
//
//};
//
////Pythonҳ��
//class Python
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
//	}
//
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++��..�����������б�" << endl;
//	}
//
//	void content()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//
//};
//
////C++ҳ��
//class CPP
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
//	}
//
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left()
//	{
//		cout << "Java��Python��C++��..�����������б�" << endl;
//	}
//
//	void content()
//	{
//		cout << "C++ѧ����Ƶ" << endl;
//	}
//
//};

//�̳�ʵ�ֽ���

//����ҳ����
class BasePage
{
public:
	void header()
	{
		cout << "��ҳ�������Ρ���¼��ע��...(����ͷ��)" << endl;
	}

	void footer()
	{
		cout << "�������ġ�����������վ�ڵ�ͼ...�������ײ���" << endl;
	}
	void left()
	{
		cout << "Java��Python��C++��..�����������б�" << endl;
	}

};

//�̳еĺô������Լ����ظ��Ĵ���

//�﷨�� class  ����  :  �̳з�ʽ   ����     �磺class  A��public B
//����  Ҳ��Ϊ  ������
//����  Ҳ��Ϊ   ����        

//�������еĳ�Ա���������󲿷֣�
//һ���Ǵӻ���̳й����ģ�һ�����Լ����ӵĳ�Ա
//�ӻ���̳й��������乲�ԣ��������ĳ�Ա�����˸���


//Javaҳ��
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Javeѧ����Ƶ" << endl;
	}
};

//Pythonҳ��
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Pythonѧ����Ƶ" << endl;
	}
};

//C++ҳ��
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "C++ѧ����Ƶ" << endl;
	}
};


void test01()
{
	cout << "Java������Ƶҳ�����£� " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "---------------------------------------" << endl;
	cout << "Python������Ƶҳ�����£� " << endl;
	 Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << "---------------------------------------" << endl;
	cout << "C++������Ƶҳ�����£� " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();
}

int main()
{
	test01();

	system("pause");
	return 0;
}