#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>

using namespace std;

//random_shuffle    ����������
//ϴ�ƣ�ָ����Χ�ڵ�Ԫ�������������

//����ԭ�ͣ�
//random_shuffle(iterator beg,iterator end);
//ָ����Χ��Ԫ�������������
//beg   ��ʼ������
//end   ����������


void myPrint(int val)
	{
		cout << val << " ";
	}

void test01()
{
	srand((unsigned int)time(NULL));//ע����������˫�����ŵģ�����ʱд�ڵ��õĺ�����
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//����ϴ���㷨  ������˳��
	random_shuffle(v.begin(), v.end());

	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}


int main()
{

	test01();
	system("pause");
	return 0;
}
//�ܽ᣺random_shuffleϴ���㷨�Ƚ�ʵ�ã�ʹ��ʱ�ǵü����������