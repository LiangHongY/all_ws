#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//reverse  ����������
//�������ڵ�Ԫ�ؽ��з�ת

//����ԭ�ͣ�
//reverse(iterator beg,iterator end);

//��תָ����Χ��Ԫ��
//beg   ��ʼ������
//end   ����������

void myprint(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(50);
	v.push_back(60);
	v.push_back(30);
	v.push_back(20);

	cout << "��תǰ��" << endl;
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

	cout << "��ת��" << endl;
	reverse(v.begin(),v.end());
	for_each(v.begin(), v.end(), myprint);
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺reverse ��������Ԫ�أ����Կ��ܻ��漰��