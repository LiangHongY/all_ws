#include<iostream>
#include<functional>//��Ҫд���ͷ�ļ�����Ҫдʹ�ñ�׼��ʽ��ͷ�ļ�����
#include<algorithm>//��׼��ʽͷ�ļ�
#include<vector>

using namespace std;

//��ϵ�º���������������
//ʵ�ֹ�ϵ�Ա�

//�º���ԭ�ͣ�
//template<class T> bool equal_to<T>        //����
//template<class T> bool not_equal_to<T>    //������
//template<class T> bool greater<T>         //����

//template<class T> bool greater_equal<T>   //���ڻ����
//template<class T> bool less<T>            //С��
//template<class T> bool less_equal<T>      //С�ڻ����


//�ڽ���������_��ϵ�º���
//����  greater

//
class Mycompare
{
public:
	bool operator()(int &v1,int &v2)
	{
		return v1 > v2;
	}
};



void test01()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(60);
	v.push_back(30);
	v.push_back(700);
	v.push_back(30);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	//����
	//sort(v.begin(), v.end(),Mycompare());

	//greater<int>()    �ڽ���������int��ʾ���ǱȽ�����ʱint�ͣ�
	sort(v.begin(), v.end(),greater<int>());//ϵͳ�Դ��ķº���

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺��ϵ�º�����õľ���  greater<>   ���� ����