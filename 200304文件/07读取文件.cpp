#include  <iostream>
#include  <fstream>
#include  < string >
using   namespace  std;

void  OutPutAnEmptyLine()//输出空行
{
    cout << "\n";
}

//读取方式: 逐词读取, 词之间用空格区分
void  ReadDataFromFileWBW()
{
    cout << "逐词读取, 词之间用空格区分" << endl; 
    ifstream fin("a.yaml.txt");  
    string  s;  while (fin >> s)
    {
        cout << "Read from file: " << s << endl;
    }
}

//读取方式: 逐行读取, 将行读入字符数组, 行之间用回车换行区分

void  ReadDataFromFileLBLIntoCharArray()
{
    cout << "逐行读取, 将行读入字符数组, 行之间用回车换行区分" << endl;
    ifstream fin("a.txt");
    const   int  LINE_LENGTH = 2 ; 
    char  str[LINE_LENGTH]; 
    while (fin.getline(str, LINE_LENGTH)) 
    { 
        cout << "Read from file: " << str << endl;
    }
}

//读取方式: 逐行读取, 将行读入字符串, 行之间用回车换行区分
//相比较上种方法，该种方法比较灵活，推荐使用

void  ReadDataFromFileLBLIntoString()
{
    cout << "逐行读取, 将行读入字符串, 行之间用回车换行区分" << endl;
    ifstream fin("a.txt");  
    string  s[100][100];  //两个100为了测试而增加 20200529
    while (getline(fin, s)) //不明白到底出问题在哪里 20200529
    { 
        cout << "Read from file: " << s << endl; 
    }
}

//带错误检测的读取方式
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
   // ReadDataFromFileWBW();  //逐词读入字符串

    //OutPutAnEmptyLine();  //输出空行

   //ReadDataFromFileLBLIntoCharArray(); //逐词读入字符数组

    //OutPutAnEmptyLine();  //输出空行

    ReadDataFromFileLBLIntoString(); //逐词读入字符串
    //
    //OutPutAnEmptyLine();  //输出空行

    //ReadDataWithErrChecking();  //带检测的读取
    
    return   0 ;
}
//运行异常