//vector������������
//���ܣ�
//vector���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������

//vector����ͨ��������
//��֮ͬ�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ

//��̬��չ��
//��������ԭ�ռ�֮��Ӻ����¿ռ䣬�����Ҹ����ڴ�ռ䣬Ȼ��Ԫ���ݿ����¿ռ䣬�ͷ�ԭ�ռ�
//vector�����ĵ�������֧��������ʵĵ�����
//v.begin() ��ʾ������һ��Ԫ�أ�λ�ã�
//v.rbegin() ��ʾ�����������һ��Ԫ�أ�λ�ã�
//v.insert() ��ʾ�����ڲ���Ԫ��
//v.end() ��ʾ�������һ��Ԫ�صĺ���һ����λ�ã�

//vector���캯��

//����������
//����vector����

//����ԭ��
//vector<T> v;  //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
//vector��v.begin(),v.end()��;//��v[begin(),end())�����е�Ԫ�ؿ���������(ע������������
                              //ǰ�պ󿪵ģ�ǰ�����ȡ�õ��������ȡ����)
//vector(n,elem);      //���캯����n��elem����������
//vector(const vector &vec);//�������캯��

#include<iostream>
#include<vector>
using namespace std;

//�������
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector��������
void test01()
{
	//Ĭ�Ϲ���  �޲ι���
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//ͨ�����䷽ʽ���й���
	vector<int>v2(v1.begin(), v1.end());
	printVector(v2);

	//n��elem��ʽ����
	vector<int>v3(10, 100);
	printVector(v3);

	//��������
	vector<int>v4(v3);
	printVector(v4);
}


int main()
{
	test01();

	system("pause");
	return 0;
}
//vector�Ķ��ֹ��췽ʽû�пɱ��ԣ����ʹ�ü���
//��ʦ��ᣬ�������췽ʽ���ã�������Բ���