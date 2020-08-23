#include<iostream>
using namespace std;

class C1
{
	int m_A;//默认权限     私有
};
struct C2
{
	int m_A;
};

int main()
{
	//struct和class的区别
	//struct 默认权限是  公共  public
	//class  默认权限是   私有  private
	C1 c1;
	//c1.m_A=100;//会报错，class默认权限为私有，类外不能访问

	C2 c2;
	c2.m_A=100;//不会报错，struct默认权限为公共，类外可以访问

	system("pause");
	return 0;
}