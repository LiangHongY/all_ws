#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include <regex>
#include <Windows.h>

using namespace std;
int main()
{
    ifstream infile;
    infile.open("a.txt");   //将文件流对象与文件连接起来 
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

    vector<vector<int>> q;
    vector<int>temp_line;
    string line;
    regex pat_regex("[[:digit:]]+");
    ifstream in("a.txt");
    int lines = 0;
    while (getline(in, line))
    {
        for (sregex_iterator it(line.begin(), line.end(), pat_regex), end_it; it != end_it; ++it)
        {
            temp_line.push_back(stoi(it->str()));
        }
        q.push_back(temp_line);
        temp_line.clear();
        lines += 1;//获取文件总行数
    }
    in.close();
    cout << lines<<endl; 

    int N = 2;//定义数组维度
    int M = 2;
    vector<vector<int>>B(N, vector<int>(M));//定义一个二维动态数组B[N][M]

    for (int m = 0; m < N; m++)
    {
        for (int n = 0; n < M; n++)
        {
            B[m][n] = -1;
            for (int i = 0; i < lines; i++)
            {
                if (q[i][0] == m && q[i][1] == n)
                {
                    B[m][n] = q[i][2];
                    Sleep(3000);//获取正常值停留3秒，以检查数组获取值的结果
                }
            }
            std::cout << "B[" << m << "][" << n << "] :    " << B[m][n] << endl;//输出数组
        }
    }
    return 0;
}
//异常的200402，里面的原理也是看不懂的