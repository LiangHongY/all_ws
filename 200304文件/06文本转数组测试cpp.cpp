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
    infile.open("a.txt");   //���ļ����������ļ��������� 
    assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 

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
        lines += 1;//��ȡ�ļ�������
    }
    in.close();
    cout << lines<<endl; 

    int N = 2;//��������ά��
    int M = 2;
    vector<vector<int>>B(N, vector<int>(M));//����һ����ά��̬����B[N][M]

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
                    Sleep(3000);//��ȡ����ֵͣ��3�룬�Լ�������ȡֵ�Ľ��
                }
            }
            std::cout << "B[" << m << "][" << n << "] :    " << B[m][n] << endl;//�������
        }
    }
    return 0;
}
//�쳣��200402�������ԭ��Ҳ�ǿ�������