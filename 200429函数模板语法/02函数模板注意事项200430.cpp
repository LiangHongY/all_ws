//#include<iostream>
//using namespace std;
//
//int main() {
//
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

//����ģ��ע������
template<class T>//typename�����滻Ϊclass
                 //����ѡ�������ӷ����ģ��ʹ��class������ģ��ѡ��typename
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1���Զ������Ƶ������뵼��һ�µ���������T����ʹ��
void test01() {
	int a = 10;
	int b = 20;
	//mySwap(a, b);//��ȷ

	//����չʾ
	char c = 'c';
	//mySwap(a, c);//������ֱ�ӱ���;���ڱ������Ʋ�����������

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

//2��ģ�����ȷ��T���������Ͳ���ʹ��
template<class T>
void func() {
	cout << "func ��������" << endl;
}

void test02() {
	//func();//ֱ�����ûᱨ����������֪����������

	func<int>();//����һ��int���ͣ���������ͨ����
}

int main() {
	test01();

	test02();
	system("pause");
	return 0;
}
//�ܽ᣺
//ʹ��ģ��ʱ������ȷ����ͨ����������T�������ܹ��Ƶ���һ�µ�����