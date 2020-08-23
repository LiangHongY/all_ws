//-封装函数显示该界面，如 void showMenu（）
//-在main函数中调用封装好的函数
#include<iostream>
#include<string>


using namespace std;

#define MAX 1000   //注意不能写=号


//菜单界面
void showMenu()
{
	cout<<"***********************"<<endl;
	cout<<"*****1、添加联系人*****"<<endl;
	cout<<"*****2、显示联系人*****"<<endl;
	cout<<"*****3、删除联系人*****"<<endl;
	cout<<"*****4、查找联系人*****"<<endl;
	cout<<"*****5、修改联系人*****"<<endl;
	cout<<"*****6、清空联系人*****"<<endl;
	cout<<"*****0、退出通讯录*****"<<endl;
	cout<<"***********************"<<endl;
}

//1、添加联系人实现步骤
//设计联系人结构体
//main函数中创建通讯录
//封装添加联系人函数
//测试添加联系人功能

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
{
	//判断通讯录是否已满，如果满了就不再添加
	if(abs->m_Size==MAX)
	{
		cout<<"通讯录已满，无法添加！"<<endl;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout<<"请输入姓名：  "<<endl;
		cin>>name;
		abs->personArray[abs->m_Size].m_Name=name;
		
		//性别
		cout<<"请输入性别：  "<<endl;
		cout<<"1  --  男"<<endl;
		cout<<"2 --  女"<<endl;
		int sex =0;
		while(true)
		{
			//如果输入的是1或者2可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			cin>>sex;
		    if(sex==1 || sex==2)//此处只是表示而已，到时候输出信息还是1，2的。
		   {
			abs->personArray[abs->m_Size].m_Sex=sex;
			break;
		   }
			cout<<"输入有误，请重新输入"<<endl;
		}

		//年龄
		int age=0;
		cout <<"请输入年龄：  "<<endl;
		cin>>age;
		abs->personArray[abs->m_Size].m_Age=age;
		//电话
		cout <<"请输入电话号码：  "<<endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone=phone;
		//地址
		cout<<"请输入地址：   "<<endl;
		string address;
		cin>>address;
		abs->personArray[abs->m_Size].m_Addr=address;

		//更新通讯录人数
		abs->m_Size++;
		cout<<"添加成功"<<endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//2、显示联系人实现步骤
//封装显示联系人函数
//测试显示联系人功能
void showPerson(Addressbooks *abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为0为空
	//如果不为0，显示记录的联系人信息
	if(abs->m_Size==0)
	{
		cout<<"当前记录为空"<<endl;
	}
	else
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			cout<<"姓名：  "<<abs->personArray[i].m_Name<<"\t";
			cout<<"性别：  "<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";
			cout<<"年龄：  "<<abs->personArray[i].m_Age<<"\t";
			cout<<"电话：  "<<abs->personArray[i].m_Phone<<"\t";
			cout<<"地址：  "<<abs->personArray[i].m_Addr<<endl;
		}
	}
	system("pause");
	system("cls");

}

//3、删除联系人实现步骤（按照姓名进行的）
//封装检测联系人是否存在
//        设计思路：删除联系人前判断该联系人是否存在，存在就进行删除；不存在就提示用户不存在要删除的联系人。因此，我们可以把
//                           检测联系人是否存在封装成一个函数，如果存在就返回联系人在通讯录中的位置，不存在就返回-1
//封装删除联系人函数
//测试删除联系人功能

//检测联系人是否存在，如果存在，返回联系人所在数组的具体位置，不存在返回-1
//3.1查找联系人：    参数1   通讯录     参数2  对比姓名
int isExist(Addressbooks *abs,string name)
{
	for(int i=0;i<abs->m_Size;i++)
	{
		if(abs->personArray[i].m_Name==name)
		{
			return i;//找到了就返回联系人的下标
		}
	}
	return -1;//表示遍历找不到该联系人
}

//删除联系人函数设计思路
//根据用户输入联系人判断通讯录中是否存在此人
//查找到，就删除，并提示删除成功
//查不到就提示查无此人

//3.2删除指定的联系人
void deletePerson(Addressbooks *abs)
{
	cout<<"请输入需要删除联系人的姓名： "<<endl;
	string name;
	cin>>name;

	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		//查到此人，进行删除操作
		for(int i=ret;i<abs->m_Size;i++)
		{
			//简单点理解就是把后面的数据往前移动达到删除目的
			abs->personArray[i]=abs->personArray[i+1];
		}
		abs->m_Size--;//更新通讯录中的人员数
		cout<<"删除成功"<<endl;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	system("pause");
	system("cls");
}

//4查找联系人
void findPerson(Addressbooks *abs)
{
	cout<<"请输入查找联系人的姓名"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		cout<<"姓名： "<<abs->personArray[ret].m_Name<<"  性别：  "<<abs->personArray[ret].m_Sex
		<<"  年龄：  "<<abs->personArray[ret].m_Age<<"  电话号码：  "<<abs->personArray[ret].m_Phone
		<<"  地址：  "<<abs->personArray [ret].m_Addr<<endl;
		cout<<"性别1表示男，性别2表示女"<<endl;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	system("pause");
	system("cls");
}

//5修改指定联系人
void editPerson(Addressbooks *abs)
{
	cout<<"请输入需要修改的联系人的姓名"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		cout<<"请输入联系人姓名： "<<endl;
		string name;
		cin>>name;
		abs->personArray[ret].m_Name=name;
		
		cout<<"请输入联系人的性别"<<endl;
		cout<<"1--男"<<endl;
		cout<<"2--女"<<endl;
		int sex=0;
		cin>>sex;
		while(true)
		{
			if(sex==1 || sex==2)
			{
				abs->personArray[ret].m_Sex=sex;
			}
			else
			{
				cout<<"输入有误，请重新输入"<<endl;
			}
			break;
		}
		
		cout<<"请输入联系人的年龄："<<endl;
		int age;
		cin>>age;
		abs->personArray[ret].m_Age=age;

		cout<<"请输入联系人的电话号码"<<endl;
		string number;
		cin>>number;
		abs->personArray[ret].m_Phone=number;

		cout<<"请输入联系人的地址"<<endl;
		string address;
		cin>>address;
		abs->personArray[ret].m_Addr=address;
		
		cout<<"修改成功"<<endl;
	}
	else
	{
		cout<<"查无此人"<<endl;
	}
	system("pause");
	system("cls");
}
//6清空所有联系人信息
//实现思路：把通讯录人数置为0，做逻辑清空即可。
void clearPerson(Addressbooks *abs)
{
	abs->m_Size=0;
	cout<<"通讯录已清空！"<<endl;
	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size=0;

	int select=0;//创建用户选择输入的变量
	while(true)
	{
			//菜单调用
	showMenu();

	cin>>select;

	switch(select)
	{
	case 1://1、添加联系人
		addPerson(&abs);//利用地址传递，可以修饰实参
		break;
	case 2://2、显示联系人
		showPerson(&abs);
		break;
	case 3://3、删除联系人
	deletePerson(&abs);

	//if(isExist(&abs,name)==-1)
	//{
	//	cout<<"没有该联系人"<<endl;
	//}
	//else
	//{
	//	cout<<"该联系人存在"<<endl;
	//}
		break;
	case 4://4、查找联系人
			findPerson(&abs);
		break;
	case 5://5、修改联系人
		editPerson(&abs);
		break;
	case 6://6、清空联系人
		clearPerson(&abs);
		break;
	case 0://0、退出通讯录
		cout<<"欢迎下次使用"<<endl;
		system("pause");
		return 0;
		break;
	default:
		break;
	}
	}
	system("pause");
	return 0;
}