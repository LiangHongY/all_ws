#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//binary_search  ����������
//����ָ��Ԫ���Ƿ����

//����ԭ�ͣ�
//bool binary_search(iterator beg,iterator end,value);
//����ָ����Ԫ�� �� �鵽  ����  true   ����  false

//ע�⣺  ������������  ������
//beg   ��ʼ������
//end   ����������
//value  ���ҵ�Ԫ��

void test01()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//v.push_back(2);//���������������ˣ�ʵ�ʴ���ȴ��ʾû�У���
	   //��֤��������Ҫʱ����ſ�������ʹ�øò����㷨

	//�����������Ƿ���9Ԫ��
	//ע�⣬�������������������
	bool gg=binary_search(v.begin(), v.end(), 9);

	if (gg == true)
	{
		cout << "���ڸ�Ԫ��" << endl;
	}
	else
	{
		cout << "�����ڸ�Ԫ��" << endl;
	}

}


int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺
//���ַ�����Ч�ʺܸߣ�ֵ��ע����ǣ����ҵ�����Ԫ�ر�������������