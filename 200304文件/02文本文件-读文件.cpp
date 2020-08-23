//读文件操作步骤
//1.包含头文件   #include<fstream>
//2、创建流对象  ifstream ifs;
//3、打开文件并判断文件是否成功打开    ifs.open("文件路径",打开方式);
//4.读数据，四种方式读取 
//5.ofs.close();



#include<iostream>
using namespace std;
#include<fstream>
#include<string>

//文本文件  读文件

void test01()
{
	//1、包含头文件fstream

	//2.创建流对象

	ifstream ifs;

	//3.打开文件并且判断是否打开成功
	ifs.open("test.txt", ios::in);//out表示写进文件，in表示读取文件
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//4.读数据

	////第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	////第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种
	string buf;
	while (getline(ifs, buf))//调试报错，具体原因未知20200304;调试具体是正常的20200315
	{
		cout << buf << endl;
	}
	
	////第四种
	//char c;
	//while ((c = ifs.get()) != EOF)//EOF   表示   end  of  file
	//{
	//	cout << c ;//这里不能写endl
	//}

	//5.关闭文件
	ifs.close();
}

int main()
{
	test01();
	system("pause");
	return 0;
}

//读文件可以利用ifstream,或者fstream类
//利用is_open函数可以判断文件是否打开成功
//close关闭文件