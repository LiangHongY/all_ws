//�����㷨

//����
//�㷨��Ҫʱ��ͷ�ļ�<algorithm> <functional> <numeric>���
//<algorithm>  ������STLͷ�ļ�������һ������Χ�漰�Ƚϡ����ҡ��������������ơ��޸ĵȵ�
//<functional> ������һЩģ���࣬����������������
//<numeric>  �����С��ֻ��������������������м���ѧ�����ģ�庯��


//���õı����㷨��ѧϰĿ��
//���ճ��õı����㷨

//�㷨��飺
//for_each      //��������
//transform     //������������һ��������

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//���ñ����㷨  for_each
//for_each  ����������
//ʵ�ֱ�������

//����ԭ�ͣ�
//for_each(iterator beg,iterator end, _func);
//�����㷨����������Ԫ��
//beg ��ʼ������
//end  ����������
//_func  �������ߺ�������

//��ͨ����
void print01(int val)
{
	cout << val << " ";
}

//�º���
class print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), print01);//����������Ҫ�Ӻ�������
	cout << endl;

	for_each(v.begin(), v.end(), print02());
	cout << endl;

}


int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺for_each��ʵ�ʿ���������õı����㷨����Ҫ��������