#include<iostream>
using namespace std;

//���룺
//����ģ�������̳�ʱ����Ҫע�����¼���
//������̳еĸ�����һ����ģ��ʱ��������������ʱ����Ҫָ����������T������
//�����ָ�����������޷�����������ڴ�
//��������ָ������T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��

//��ģ����̳�

template<class T>
class Base
{
public:
	T m;
};

//class Son :public Base//����ģ�����֪�������е�T�����ͣ����ܼ̳и�����
class Son:public Base<int>//ָ�������;Ϳ��������̳���
{

};

void test01()
{
	Son s1;
}

//��������ָ��������T���ͣ�����Ҳ��Ҫ��Ϊ��ģ��
template<class T1,class T2>//T2�Ǵ�������ģ�T1�Ǵ��������
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1����������Ϊ��" << typeid(T1).name() << endl;
		cout << "T2����������Ϊ��" << typeid(T2).name() << endl;
	}
	T1 obj;
};

void test02()
{
	Son2<int, char>s2;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
//�ܽ�
//���������һ����ģ�壬������Ҫָ��������T����������