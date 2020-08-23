#include<iostream>
using namespace std;
#include<list>

//list�����ɾ��������������
//��list�����������ݵĲ����ɾ��

//����ԭ�ͣ�
//push_back(elem);        //������β������һ��Ԫ��
//push_back();          //ɾ�����������һ��Ԫ��
//push_front(elem);     //��������ͷ����һ��Ԫ��
//pop_front();          //��������ͷ�Ƴ�һ����һ��Ԫ��

//insert(pos,elem);     //��posλ�ò���elemԪ�صĿ��������������ݵ�λ��
//insert(pos,n,elem);   //��posλ�ò���n��elem���ݣ��޷���ֵ
//insert(pos,beg,end);  //��posλ�ò���[beg,end)��������ݣ��޷���ֵ

//clear();              //�Ƴ����������е�����
//erase(beg,end);     //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
//erase(pos);         //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
//remove(elem);       //ɾ��������������elemֵƥ���Ԫ��


void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	list<int>L1;

	//β��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	
	//ͷ��
	L1.push_front(34);
	L1.push_front(55);
	L1.push_front(66);

	printList(L1);

	//βɾ
	L1.pop_back();
	printList(L1);

	//ͷɾ
	L1.pop_front();
	printList(L1);

	//insert����
	L1.insert(L1.begin(), 100);
	printList(L1);

	//��������ʽ����
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printList(L1);

	//ɾ��
	it = L1.begin();
	L1.erase(it);
	printList(L1);

	//�Ƴ�
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	printList(L1);
	L1.remove(10000);
	printList(L1);

	//���
	L1.clear();
	printList(L1);
}


int main()
{
	test01();

	system("pause");
	return 0;
}

//�ܽ᣺
//β��   --push_back
//βɾ   --pop_back
//ͷ��   --push_front
//ͷɾ   --pop_front

//����  --insert
//ɾ��  --erase
//�Ƴ�  --remove
//���  --clear