#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//adjacent_find   ��������
//���������ظ�Ԫ��

//����ԭ�ͣ�
//adjacent_find(iterator beg,iterator end);
//���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����
//beg  ��ʼ������
//end  ����������



void test01()
{
	vector<int>v;
	
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);

	vector<int>::iterator pos= adjacent_find(v.begin(), v.end());

	if (pos != v.end())
	{
		cout << "�ҵ������ظ����ݣ��ҵ�һ�������ݣ�" << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ������ظ�����" << endl;
	}

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺�����У�������������ظ�Ԫ�أ��ǵ���STL�е�adjacent_fing�㷨