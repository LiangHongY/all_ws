//�ڽ�������������

//���
//STL�ڽ���һЩ��������

//���ࣺ
//�����º���
//��ϵ�º���
//�߼��º���

//�÷���
//��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
//ʹ���ڽ�����������Ҫ����ͷ�ļ�   #include<functional>



#include<iostream>
#include<functional>
using namespace std;

//�����º���������������
//ʵ����������
//����negate��һԪ���㣬�������Ƕ�Ԫ����

//�º���ԭ�ͣ�
//template<class T> T plus<T>       //�ӷ��º���
//template<class T> T minus<T>      //�����º���
//template<class T> T multiplies<T>  //�˷��º���

//template<class T> T divides<T>     //�����º���
//template<class T> T modulus<T>     //ȡģ�º���
//template<class T> T negate<T>      //ȡ���º���


//�ڽ���������   �����º���


//negate һԪ�º���   ȡ���º���
void test01()
{
	negate<int>n;
	cout << n(50) << endl;
}


//plus ��Ԫ�º���      �ӷ�
void test02()
{
	plus<int>p;     //�ú���Ĭ��ȡ����ͬ���͵����ݣ����Ҳ����Զ������͵�

	cout << p(10, 2) << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}

//�ܽ᣺ʹ���ڽ���������ʱ����Ҫ����ͷ�ļ�    #include<functional>
