#include<iostream>
using namespace std;

//案例描述
//利用函数模板封装一个排序函数，可以对不同数据类型数组进行排序
//排序规则从大到小，排序算法为选择排序
//分别利用char数组和int数组进行测试

//实现通过  对数组进行排序的函数
//规则，从大到小
//算法，选择
//测试  char数组  int 数组

//交换函数模板
template<class T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
	
}

//排序算法
template<class T>
void mySort(T arr[],int len) {
	for (int i = 0; i < len; i++) {
		int max = i;//假设最大值下标
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]) {
				max = j;//更新最大值下标
				//char temp = arr[max];
				//arr[max] = arr[i];
				//arr[j] = temp;
			}
		}
		if (max != i) {
			//交换max和i元素
			mySwap(arr[max], arr[i]);

		}
	}
}

//提供打印数组模板
template<class T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}

//测试案例1
void test01() {
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);//因为放在排序函数之后，所以，打印的是排序后的数组
	cout << endl;
}

//测试案例2
void test02() {
	//测试int数组
	int intArr[] = { 3,23,45,6,7,5 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);//因为放在排序函数之后，所以，打印的是排序后的数组
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;
}