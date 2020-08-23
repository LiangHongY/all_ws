#include<iostream>
using namespace std;

//C++��һ�ֱ��˼���Ϊ��ʽ��̣���Ҫ���õļ�������ģ��
//C++�ṩ����ģ����ƣ�����ģ�����ģ��

//����ģ������ã�����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ����嶨�ƣ�
//��һ�����������������

//����ģ��

//�������ͽ�������

void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//��������������
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ��(�﷨)
template<typename T>//����һ��ģ�壬���߱����������������ŵ�T��Ҫ����T��һ��ͨ����������
void mySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;

	//swapInt(a, b);
	//���ú���ģ�彻��
	//���ַ�ʽʹ�ú���ģ��

	////1���Զ������Ƶ�
	//mySwap(a, b);

	//2����ʾָ������
	mySwap<int>(a, b);//��<>��ָ��T���������

	cout << "a= " << a << endl;
	cout << "b= " << b<<endl;

	double c = 1.1;
	double d = 2.2;
	//swapDouble(c, d);
	mySwap<double>(c, d);
	cout << "c= " << c << endl;
	cout << "d= " << d << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺
//����ģ���ʹ�������ַ�ʽ���Զ������Ƶ�����ʾָ������
//ģ���Ŀ����Ϊ����߸����ԣ������Ͳ�����

//ģ����ص㣺
//ģ�岻����ֱ��ʹ�ã���ֻ��һ�����
//ģ���ͨ�ò��������ܵ�