#include<iostream>
using namespace std;


int a = 10;

void test01()
{
	cout << a << endl;
	a = 20;
	cout << "test01: "<<a << endl;
}

void test02()
{
	cout << "test02 1:" << a << endl; 
	a = 99;
	cout << a << endl;;
}

int main()
{
	test01();

	test02();

	cout << a << endl;
	system("pause");
	return 0;
}