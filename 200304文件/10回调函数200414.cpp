#include<iostream>

using namespace std;

//����ص�����
void printftext()
{
	cout << "Hello world!"<<endl;
}


//����ʵ�ֻص�������   ���ú���
void callprintftext(void (*callfunt)())
{
	callfunt();
}

//��main����ʵ�ֺ����ص�
int main(int argc, char* argv[])
{
	callprintftext(printftext);
	
	system("pause");
	return 0;
}