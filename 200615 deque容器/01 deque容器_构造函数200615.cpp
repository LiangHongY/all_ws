#include<iostream>
using namespace std;
#include<deque>

//deque������������
//����������
//˫�����飬���Զ�ͷ�˽���ɾ������

//deque��vector����
//vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
//deque��Զ��ԣ�����ͷ���Ĳ���ɾ���ٶȻ��vector��
//vector����Ԫ�ص��ٶȻ��deque�죬��������ڲ�ʵ���й�

//deque�ĳ�Ա��

//ͷ�� ��  push_front();
//ͷɾ  �� pop_front();
//��һ��Ԫ�أ�   begin();
//ָ��λ�ò��룺  insert();
//���һ��Ԫ�� �� end();
//β��  ��  push_back();
//βɾ  ��  pop_back();

//deque�ڲ�����ԭ��

//deque�ڲ��и��п�����ά��ÿ�λ����������ݣ������������ʵ���ݣ������������¼���ˣ�
//�����Ὺ���µ��ڴ�����ţ����ѵ�ַ�������п������棬���ʾ�ͨ����ַ�����ʣ�
//�п���ά������ÿ���������ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�

//deque�����ĵ�����Ҳ��֧��������ʵ�


//deque���캯��  ����������
//����ԭ�ͣ�
//deque<T>deqT;     //Ĭ�Ϲ�����ʽ
//deque(beg,end);   //���캯����[beg,end)�����е�Ԫ�ؿ���������
//deque(n,elem);    //�������캯����n��elem����������
//deque(const deque &deq);    //�������캯��


//deque ���캯��
void printDeque(const deque<int>&d)//�������const������ֻ��״̬������
                                 //��iterator��������дҲҪ�б仯 ��const_iterator 
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it=100;     //���������ݲ������޸���
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 99);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);
}



int main()
{
	test01();

	system("pause");
	return 0;
}
//�ܽ᣺deque������vector�����Ĺ��췽ʽ����һ�������ʹ�ü���