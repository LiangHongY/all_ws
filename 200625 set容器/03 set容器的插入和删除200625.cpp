#include<iostream>
using namespace std;
#include<set>

//set�����ɾ��������������
//set�������в������ݺ�ɾ������

//����ԭ�ͣ�
//insert(elem);     //�������в���Ԫ��
//clear();          //�������Ԫ��
//erase(pos);       //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�����

//erase(beg,end);   //ɾ������[beg,end)����Ԫ�أ�������һ��Ԫ�صĵ�����
//erase(elem);      //ɾ��������ֵΪelem��Ԫ��

void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int>s;

	s.insert(29);
	s.insert(3);
	s.insert(40);
	s.insert(37);

	printSet(s);

	//ɾ��
	s.erase(s.begin());
	printSet(s);

	//ɾ�����ذ汾
	s.erase(29);
	printSet(s);

	//���
	s.erase(s.begin(), s.end());
	printSet(s);

	s.insert(12);
	printSet(s);
	s.clear();
	printSet(s);


	////ɾ��ָ��λ�õ�Ԫ����ôʵ�֣���֪�����ǲ���set�����ǲ�֧����ô���ʵģ�200625
	//for (set<int>::iterator it = s.begin(),int i=0; it != s.end(),i!=100; it++,i++)
	//{
	//	if (i== 2)
	//	{
	//		s.erase(40);
	//	}
	//}
	//printSet(s);


}


int main()
{
	test01();
	system("pause");
	return 0;
}
//�ܽ᣺
//���� --insert
//ɾ��  --erase
//���  --clear