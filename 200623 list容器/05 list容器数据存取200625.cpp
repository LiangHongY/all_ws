#include<iostream>
using namespace std;
#include<list>

//list���ݴ�ȡ������������
//��list���������ݽ��д�ȡ

//����ԭ�ͣ�
//front();       //���ص�һ��Ԫ��
//back();     //�������һ��Ԫ��


void printList(list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L;

	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);

	printList(L);
	//L[0];//����list�����ײ�û������[]�����Բ���ʹ��[]����������Ԫ��

	//L.at(0);//����������ʹ��at��ʽ����list������Ԫ��

	//ԭ����list�����������������������Կռ�洢���ݣ�������Ҳ�ǲ�֧��������ʵ�

	cout << "��һ��Ԫ��Ϊ��" << L.front() << endl;

	cout << "���һ��Ԫ��Ϊ��" << L.back() << endl;

	//��֤�������ǲ�֧���������
	list<int>::iterator it = L.begin();
	it++;//֧��˫�߷���     //��ʹд��(it++)++,Ҳ������Ӽ�һ�ε�Ч����Ҳ�Ǿ�˵����������ô�Ӽӣ��������20
	cout << *it << endl;
	it--;;//֧��˫�߷��ʡ����ֻ��++����--����ôֻ��֧�ֵ���ġ�
	cout << *it << endl;

	//it = it + 3;//������ʾ������Ծʽ����

}

int main()
{
	test01();
	system("pause");
	return 0;
}