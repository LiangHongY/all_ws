#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//���ñ����㷨  transform ��������:
//������������һ��������

//����ԭ�ͣ�
//tranform(iterator beg1,iterator end1,iterator beg2,_func);

//beg1  Դ������ʼ������
//end1  Դ��������������
//beg2  Ŀ��������ʼ������
//_func �������ߺ�������

class Tranform
{
public:
	int operator()(int v)
	{
		return v+100;
	}
};

//��ӡ����º���
class myPrint
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

	vector<int>vTarget;
	vTarget.resize(v.size());//�����ٿռ�Ļ����﷨����û�б������ǻ����б���
	                         //���ԣ�Ŀ����������Ҫ��ǰ���ٿռ�
	transform(v.begin(), v.end(),vTarget.begin(), Tranform());

	//��ӡ���
	for_each(vTarget.begin(), vTarget.end(), myPrint());
	cout << endl;

}


int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺���˵�Ŀ������������ǰ���ٿռ䣬�����޷���������