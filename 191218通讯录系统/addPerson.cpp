#include"addPerson.h"


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