#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>

using namespace std;

//fill   ����������
//�����������ָ����Ԫ��

//����ԭ��
//fill(iterator beg,iterator end,value);
//�����������Ԫ��
//beg   ��ʼ������
//end   ����������
//value ����ֵ

void myprint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v;

	v.resize(10);

	//�����������
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺����fill ���Խ�������������Ԫ�����Ϊָ����ֵ