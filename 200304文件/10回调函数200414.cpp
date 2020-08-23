#include<iostream>

using namespace std;

//定义回调函数
void printftext()
{
	cout << "Hello world!"<<endl;
}


//定义实现回调函数的   调用函数
void callprintftext(void (*callfunt)())
{
	callfunt();
}

//在main函数实现函数回调
int main(int argc, char* argv[])
{
	callprintftext(printftext);
	
	system("pause");
	return 0;
}