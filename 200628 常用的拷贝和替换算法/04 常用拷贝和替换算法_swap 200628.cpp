#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//swap    ����������
//��������������Ԫ��

//����ԭ�ͣ�
//swap(container c1,container c2);
//��������������Ԫ��
//c1  ����1
//c2  ����2

class myprint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void myprint1(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int>v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(10);
	v.push_back(4);

	vector<int>v1;

	v1.push_back(100);
	v1.push_back(130);
	v1.push_back(410);
	v1.push_back(210);
	v1.push_back(30);

	cout << "����ǰv  v1��" << endl;
	for_each(v.begin(), v.end(), myprint());
	cout << endl;
	for_each(v1.begin(), v1.end(), myprint());
	cout << endl;

	cout << "������v  v1��" << endl;
	swap(v, v1);
	for_each(v.begin(), v.end(), myprint1);
	cout << endl;
	for_each(v1.begin(), v1.end(), myprint1);
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//ע�⣬����ͬ�����͵��������ܽ���
//�ܽ᣺swap��������ʱ��ע�⽻��������Ҫͬ����