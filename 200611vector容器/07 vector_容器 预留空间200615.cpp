#include<iostream>
using namespace std;
#include<vector>

//vectorԤ���ռ书������
//����vector�ڶ�̬��չ����ʱ����չ����

//����ԭ�ͣ�
//reserve(int len);   //����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
//resize�Ļ����������Զ���ֵ0����ʼ��λ��

void test01()
{
	vector<int>v;

	//����reserveԤ���ռ�
	v.reserve(100000);

	int num = 0;//ͳ�ƿ��ټ���
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num=" <<num<< endl;//ûд17��ʱ�����Ϊ30��д�ˣ����Ϊ1.
}



int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺����������Ƚϴ󣬿���һ��ʼ����reserveԤ���ռ�