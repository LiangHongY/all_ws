#include"addPerson.h"


void addPerson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if(abs->m_Size==MAX)
	{
		cout<<"ͨѶ¼�������޷���ӣ�"<<endl;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout<<"������������  "<<endl;
		cin>>name;
		abs->personArray[abs->m_Size].m_Name=name;
		
		//�Ա�
		cout<<"�������Ա�  "<<endl;
		cout<<"1  --  ��"<<endl;
		cout<<"2 --  Ů"<<endl;
		int sex =0;
		while(true)
		{
			//����������1����2�����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin>>sex;
		    if(sex==1 || sex==2)//�˴�ֻ�Ǳ�ʾ���ѣ���ʱ�������Ϣ����1��2�ġ�
		   {
			abs->personArray[abs->m_Size].m_Sex=sex;
			break;
		   }
			cout<<"������������������"<<endl;
		}

		//����
		int age=0;
		cout <<"���������䣺  "<<endl;
		cin>>age;
		abs->personArray[abs->m_Size].m_Age=age;
		//�绰
		cout <<"������绰���룺  "<<endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone=phone;
		//��ַ
		cout<<"�������ַ��   "<<endl;
		string address;
		cin>>address;
		abs->personArray[abs->m_Size].m_Addr=address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout<<"��ӳɹ�"<<endl;
		system("pause");//�밴���������
		system("cls");//��������
	}
}