#include"stdafx.h"
#include<iostream>
using namespace std;

int main()
{

	int a=10;
	int b=10;
	
	//const int * p    常量指针：指针的指向可改，但指向的值不可改   ； 
	//巧记：const 表示常量  * 理解为指针意识，那么合并就是常量指针；  
	//const修饰的是  * p，而其 表示的是一个值，const修饰这个值，那么该指针指向的值是不可改的。
	
	//1、const修饰指针   常量指针
	
	const int * p=&a;
	//* p=20;错误    
	 p=&b;

	//int * const p   指针常量：指针的指向不可改。但指向的值可改
	// 巧记： * 表示指针，const表示常量，那么合并就是指针常量   ；
	//  const修饰的是  p,而其是指针英文意思指针，而指针就是地址，那么，它表示的指针的指向是不可改的。
	  //2、const修饰常量   指针常量
	 int * const p2=&a;
	// p2=&b   错误，指向不可改
	 * p2=20;

	 //3、
	//const int * const p  ：指针的指向与指向的值都可不可改
	 const int * const p3=&a;
	// *p3=20;错误
	 //p3=&b; 错误

	system("pause");
	return 0;
}