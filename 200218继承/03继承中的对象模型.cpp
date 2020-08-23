#include<iostream>
using namespace std;

//继承中的对象模型

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son :public Base
{
public:
	int m_D;
};
//利用开发人员命令提示工具查看对象模型（Developer Command Prompt for vs 2019）
//跳转盘符，输入  G：  回车
//进入目标文件夹  输入   cd G:\wenjianjia\Cyuyan\c++\200218继承\200218继承  回车
//展示文件目录   输入    dir
//展示对象模型   输入   cl /d1 reportSingleClassLayoutSon 03继承中的对象模型.cpp  回车
//注意上面，第一个为英文L第二个为阿拉伯数字1
//归纳
//跳转盘符
//跳转文件路径 cd 具体路径
//查看命名
//cl /d1 reportSingleClassLayout类名 文件名

void test01()
{
	//父类中所有非静态成员属性都会被子类继承下来
	//父类中私有成员属性是被编译器隐藏了，因此是访问不到，但是确实被继承下来了
	cout << "size of Son= " << sizeof(Son) << endl;//16（父类三个int和自身一个int）
}

int main()
{
	test01();

	system("pause");
	return 0;
}
