#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

//replace_if     ����������
//�������ڵ�����������Ԫ�أ��滻��ָ��Ԫ��

//����ԭ�ͣ�
//replace_if(iterator beg,iterator end,_Pred,newvalue);
//�������滻Ԫ�أ������������滻��ָ��Ԫ��
//beg   ��ʼ������
//end   ����������
//_Pred   ν��
//newvalue   �滻����Ԫ��

void myprint(int val)
{
	cout << val << " ";
}

class Greater30
{
public:
	bool operator()(int val)
	{
		return val >=30;
	}
};


void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);
	v.push_back(10);
	v.push_back(100);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

	replace_if(v.begin(), v.end(), Greater30(), 3000);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺replace_if ���������ң��������÷º������ɸѡ���������