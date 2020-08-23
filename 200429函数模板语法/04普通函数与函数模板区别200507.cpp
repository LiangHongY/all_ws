#include<iostream>
using namespace std;

//普通函数与函数模板的区别
//1、普通函数调用时可以发生自动类型转换（隐式类型转换）
//2、函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//3、如果函数模板，利用显示指定类型的方式，可以发生隐式类型转换

//普通函数
int myAdd01(int a, int b) {
	return a + b;
}

//函数模板
template<class T>
T myAdd02(T a, T b) {
	return a + b;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';
	//cout << myAdd01(a, b) << endl;
	cout << myAdd01(a, c) << endl;//语法不报错，但是运行结果是109，由于内部自动将字符型转为整型运算

	//自动类型推导
	cout << myAdd02(a, b) << endl;//都是int型，函数模板可以自动推导

	//cout << myAdd02(a, c) << endl;//报错，函数模板不会自动转换类型

	//显示指定类型
	cout << myAdd02<int>(a, c) << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}
//总结：尽量使用显示指定类型的方式，调用函数模板，因为可以自己确定通用类型T