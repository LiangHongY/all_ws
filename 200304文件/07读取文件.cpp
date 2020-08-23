#include  <iostream>
#include  <fstream>
#include  < string >
using   namespace  std;

void  OutPutAnEmptyLine()//�������
{
    cout << "\n";
}

//��ȡ��ʽ: ��ʶ�ȡ, ��֮���ÿո�����
void  ReadDataFromFileWBW()
{
    cout << "��ʶ�ȡ, ��֮���ÿո�����" << endl; 
    ifstream fin("a.yaml.txt");  
    string  s;  while (fin >> s)
    {
        cout << "Read from file: " << s << endl;
    }
}

//��ȡ��ʽ: ���ж�ȡ, ���ж����ַ�����, ��֮���ûس���������

void  ReadDataFromFileLBLIntoCharArray()
{
    cout << "���ж�ȡ, ���ж����ַ�����, ��֮���ûس���������" << endl;
    ifstream fin("a.txt");
    const   int  LINE_LENGTH = 2 ; 
    char  str[LINE_LENGTH]; 
    while (fin.getline(str, LINE_LENGTH)) 
    { 
        cout << "Read from file: " << str << endl;
    }
}

//��ȡ��ʽ: ���ж�ȡ, ���ж����ַ���, ��֮���ûس���������
//��Ƚ����ַ��������ַ����Ƚ����Ƽ�ʹ��

void  ReadDataFromFileLBLIntoString()
{
    cout << "���ж�ȡ, ���ж����ַ���, ��֮���ûس���������" << endl;
    ifstream fin("a.txt");  
    string  s[100][100];  //����100Ϊ�˲��Զ����� 20200529
    while (getline(fin, s)) //�����׵��׳����������� 20200529
    { 
        cout << "Read from file: " << s << endl; 
    }
}

//��������Ķ�ȡ��ʽ
void  ReadDataWithErrChecking()
{
    string  filename = "dataFUNNY.t  xt";
    ifstream fin(filename.c_str());
    if (!fin)
    {
        cout << "Error opening " << filename << " for input" << endl;   exit(-1);
    }
}

int  main()
{
   // ReadDataFromFileWBW();  //��ʶ����ַ���

    //OutPutAnEmptyLine();  //�������

   //ReadDataFromFileLBLIntoCharArray(); //��ʶ����ַ�����

    //OutPutAnEmptyLine();  //�������

    ReadDataFromFileLBLIntoString(); //��ʶ����ַ���
    //
    //OutPutAnEmptyLine();  //�������

    //ReadDataWithErrChecking();  //�����Ķ�ȡ
    
    return   0 ;
}
//�����쳣