#include<iostream>
using namespace std;

//��������
//���ú���ģ���װһ�������������ԶԲ�ͬ�������������������
//�������Ӵ�С�������㷨Ϊѡ������
//�ֱ�����char�����int������в���

//ʵ��ͨ��  �������������ĺ���
//���򣬴Ӵ�С
//�㷨��ѡ��
//����  char����  int ����

//��������ģ��
template<class T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
	
}

//�����㷨
template<class T>
void mySort(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		int max = i;//�������ֵ�±�
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;//�������ֵ�±�
				//char temp = arr[max];
				//arr[max] = arr[i];
				//arr[j] = temp;
			}
		}
		if (max != i) {
			//����max��iԪ��
			mySwap(arr[max], arr[i]);

		}
	}
}

//�ṩ��ӡ����ģ��
template<class T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}

//���԰���1
void test01() {
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);//��Ϊ����������֮�����ԣ���ӡ��������������
	cout << endl;
}

//���԰���2
void test02() {
	//����int����
	int intArr[] = { 3,23,45,6,7,5 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);//��Ϊ����������֮�����ԣ���ӡ��������������
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;
}