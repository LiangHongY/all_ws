#include<iostream>
using namespace std;
#include<string.h>

//类做友元

class Building;

class GoodGay
{
public:

	GoodGay();

	void visit();//参观函数访问Building中的属性

	Building* building;
};

class Building
{
	//GoodGay类是本类的好朋友，可以访问本类中私有成员
	friend class GoodGay;

public:
	Building();//声明一个成员函数

public:
	string m_SittingRoom;//客厅

private:
	string m_BedRoom;//卧室
};

//类外写成员函数，注意这里的编写规则，需要带类名加::
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;
}

void GoodGay::visit()
{
	cout << "好基友类正在访问：  " << building->m_SittingRoom << endl;

	cout << "好基友类正在访问：  " << building->m_BedRoom << endl;
}

void test01()
{
	GoodGay gg;
	gg.visit();
}

int main()
{
	test01();

	system("pause");
	return 0;
}