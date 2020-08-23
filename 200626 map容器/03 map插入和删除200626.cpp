#include<iostream>
#include<map>

using namespace std;

//map�����ɾ������������
//map�������в������ݺ�ɾ������

//����ԭ�ͣ�
//insert(elem);     //�������в���Ԫ��
//clear();          //�������Ԫ��

//erase(pos);       //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����
//erase(beg,end);   //ɾ������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�����
//erase(key);       //ɾ��������ֵΪkey��Ԫ��

void printMap(map<int,int>&m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "keyֵΪ��" << it->first << " valueֵ��" << it->second << endl;
	}
	cout << endl;
}


void test01()
{
	map<int, int>m;
	
	//����
	//��һ�ַ�ʽ
	m.insert(pair<int, int>(1, 20));

	//�ڶ��ַ�ʽ
	m.insert(make_pair(2, 10));//��ʦ�Ƽ���ʽ

	//������
	m.insert(map<int, int>::value_type(3, 33));

	//������
	m[4] = 99;

	//[]��������롣��[]��;����������key���ʵ�valueֵ
	//cout << m[5] << endl;//û�����ֵȴ�Զ�����һ��0��valueֵ���������Բ�����ʹ��

	printMap(m);

	//ɾ��
	m.erase(m.begin());
	printMap(m);

	m.erase(3);//����key��ʽɾ��
	printMap(m);

	m.erase(m.begin(), m.end());
	printMap(m);


}

int main()
{
	test01();

	system("pause");
	return 0;
}