//ν�ʸ��
//����bool���͵ķº�����Ϊν��
//���operator()����һ����������ô��һԪν��
//���operator()����������������ô������Ԫν��



#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>//��׼�㷨ͷ�ļ�

//һԪν��
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};


void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//���������У���û�д���5������
	//GreaterFive() ������������
	vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());//��׼������ʽ���������Ѱ��������������
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ�����5����Ϊ��" << *it << endl;
	}
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺����ֻ��һ����ν�ʣ���ΪһԪν��
//һ���ɻ���ô������������5�����ݣ��Ҹ���ô��ȡ�أ��ǲ���ʹ��һ��ѭ��������أ�����
//���С����廹��û��������ʽ���������200626