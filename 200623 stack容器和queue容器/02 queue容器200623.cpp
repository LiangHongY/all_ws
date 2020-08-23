#include<iostream>
using namespace std;
#include<queue>
#include<string>

//queue��������������
//���queue������һ���Ƚ��ȳ���First int First Out,FIFO)�����ݽṹ��������������

//��βback()    --push()ֻ������   ; ��ͷfront()    --pop()ֻ������;

//�������������һ������Ԫ�أ�����һ���Ƴ�Ԫ��
//������ֻ�ж�ͷ�Ͷ�β�ſ��Ա����ʹ�ã���˶��в������б�����Ϊ
//�����н����ݳ�Ϊ   -- ���   push
//�����г����ݳ�Ϊ   -- ����  pop

//�ж϶����Ƿ�Ϊ��  empty
//���ض��д�С      size

//queue���õĽӿڣ�����������ջ�������õĶ���ӿ�

//���캯����
//queue<T> que;   //queue����ģ����ʵ�֣�queue�����Ĭ�Ϲ�����ʽ
//queue(const queue &que)��     //�������캯��

//��ֵ����
//queue& operator=��const queue &que��;    //���صȺŲ�����

//���ݴ�ȡ
//push(elem);        //����β���Ԫ��
//pop();             //�Ӷ�ͷ�Ƴ���һ��Ԫ��
//back();           //�������һ��Ԫ��
//front();          //���ص�һ��Ԫ��


//��С����
//empty();      //�ж϶�ջ�Ƿ�Ϊ��
//size();       //����ջ�Ĵ�С

//���� queue
class Person 
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;

};


void test01()
{
	//��������
	queue<Person>q;

	//׼������
	Person p1("��ɮ",28);
	Person p2("�����", 1028);
	Person p3("��˽�", 998);
	Person p4("ɳɮ", 628);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "����ǰ���д�СΪ�� " << q.size() << endl;
	//�ж϶��в�Ϊ�գ��鿴��ͷ���鿴��β������
	while (!q.empty())
	{
		//�鿴��ͷԪ��
		cout << "��ͷԪ��-������" << q.front().m_Name << " ���䣺" << q.front().m_Age << endl;

		//�鿴��βԪ��
		cout << "��βԪ��-������" << q.back().m_Name << " ���䣺" << q.back().m_Age << endl;

		//����
		q.pop();
	}
	cout << "���Ӻ���д�СΪ�� " << q.size() << endl;

}

int main()
{
	test01();

	system("pause");
	return 0;
}