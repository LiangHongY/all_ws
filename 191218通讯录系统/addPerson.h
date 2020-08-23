#include<iostream>
#include<string>
using namespace std;

#define MAX 1000   //注意不能写=号

  //联系人结构体
struct Person   
{
	string m_Name;
	int m_Sex;       //1 男 2女
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};
void addPerson(Addressbooks *abs)