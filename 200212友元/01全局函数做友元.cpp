//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
#include<string.h>

//建筑物类
class Building
{
	friend void goodGay(Building* building);//作为友元，使得可以访问Building私有成员
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
			
	}
	
public:
	string m_SittingRoom;//客厅

private:
	string m_BedRoom;//卧室
};

//全局函数
void goodGay(Building* building)
{
	cout << "好基友的全局函数正在访问：  " << building->m_SittingRoom << endl;
	cout << "好基友的全局函数正在访问：  " << building->m_BedRoom << endl;//这里
	//报错原因是，一般外部函数不能访问类内私有成员属性
}

void test01()
{
	Building building;
	goodGay(&building);
}



int main()
{
	test01();

	system("pause");
	return 0;
}

//友元
//目的是让一个函数或者类可以访问另一个类中私有成员
//友元的关键字为  friend
//友元的三种实现：
//全局函数做友元、类做友元、成员函数做友元