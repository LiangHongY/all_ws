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

//函数模板注意事项
template<class T>//typename可以替换为class
                 //可以选择这样子风格，类模板使用class，函数模板选择typename
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//1、自动类型推导，必须导出一致的数据类型T才能使用
void test01() {
	int a = 10;
	int b = 20;
	//mySwap(a, b);//正确

	//错误展示
	char c = 'c';
	//mySwap(a, c);//编译器直接报错;由于编译器推不出数据类型

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

//2、模板必须确定T的数据类型才能使用
template<class T>
void func() {
	cout << "func 函数调用" << endl;
}

void test02() {
	//func();//直接引用会报错，编译器不知道数据类型

	func<int>();//随便给一个int类型，编译器就通过了
}

int main() {
	test01();

	test02();
	system("pause");
	return 0;
}
//总结：
//使用模板时，必须确定出通用数据类型T，并且能够推导出一致的类型