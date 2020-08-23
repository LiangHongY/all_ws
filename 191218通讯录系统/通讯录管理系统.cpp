//-��װ������ʾ�ý��棬�� void showMenu����
//-��main�����е��÷�װ�õĺ���
#include<iostream>
#include<string>


using namespace std;

#define MAX 1000   //ע�ⲻ��д=��


//�˵�����
void showMenu()
{
	cout<<"***********************"<<endl;
	cout<<"*****1�������ϵ��*****"<<endl;
	cout<<"*****2����ʾ��ϵ��*****"<<endl;
	cout<<"*****3��ɾ����ϵ��*****"<<endl;
	cout<<"*****4��������ϵ��*****"<<endl;
	cout<<"*****5���޸���ϵ��*****"<<endl;
	cout<<"*****6�������ϵ��*****"<<endl;
	cout<<"*****0���˳�ͨѶ¼*****"<<endl;
	cout<<"***********************"<<endl;
}

//1�������ϵ��ʵ�ֲ���
//�����ϵ�˽ṹ��
//main�����д���ͨѶ¼
//��װ�����ϵ�˺���
//���������ϵ�˹���

  //��ϵ�˽ṹ��
struct Person   
{
	string m_Name;
	int m_Sex;       //1 �� 2Ů
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};

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

//2����ʾ��ϵ��ʵ�ֲ���
//��װ��ʾ��ϵ�˺���
//������ʾ��ϵ�˹���
void showPerson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ0Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if(abs->m_Size==0)
	{
		cout<<"��ǰ��¼Ϊ��"<<endl;
	}
	else
	{
		for(int i=0;i<abs->m_Size;i++)
		{
			cout<<"������  "<<abs->personArray[i].m_Name<<"\t";
			cout<<"�Ա�  "<<(abs->personArray[i].m_Sex==1?"��":"Ů")<<"\t";
			cout<<"���䣺  "<<abs->personArray[i].m_Age<<"\t";
			cout<<"�绰��  "<<abs->personArray[i].m_Phone<<"\t";
			cout<<"��ַ��  "<<abs->personArray[i].m_Addr<<endl;
		}
	}
	system("pause");
	system("cls");

}

//3��ɾ����ϵ��ʵ�ֲ��裨�����������еģ�
//��װ�����ϵ���Ƿ����
//        ���˼·��ɾ����ϵ��ǰ�жϸ���ϵ���Ƿ���ڣ����ھͽ���ɾ���������ھ���ʾ�û�������Ҫɾ������ϵ�ˡ���ˣ����ǿ��԰�
//                           �����ϵ���Ƿ���ڷ�װ��һ��������������ھͷ�����ϵ����ͨѶ¼�е�λ�ã������ھͷ���-1
//��װɾ����ϵ�˺���
//����ɾ����ϵ�˹���

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ����������ľ���λ�ã������ڷ���-1
//3.1������ϵ�ˣ�    ����1   ͨѶ¼     ����2  �Ա�����
int isExist(Addressbooks *abs,string name)
{
	for(int i=0;i<abs->m_Size;i++)
	{
		if(abs->personArray[i].m_Name==name)
		{
			return i;//�ҵ��˾ͷ�����ϵ�˵��±�
		}
	}
	return -1;//��ʾ�����Ҳ�������ϵ��
}

//ɾ����ϵ�˺������˼·
//�����û�������ϵ���ж�ͨѶ¼���Ƿ���ڴ���
//���ҵ�����ɾ��������ʾɾ���ɹ�
//�鲻������ʾ���޴���

//3.2ɾ��ָ������ϵ��
void deletePerson(Addressbooks *abs)
{
	cout<<"��������Ҫɾ����ϵ�˵������� "<<endl;
	string name;
	cin>>name;

	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		//�鵽���ˣ�����ɾ������
		for(int i=ret;i<abs->m_Size;i++)
		{
			//�򵥵������ǰѺ����������ǰ�ƶ��ﵽɾ��Ŀ��
			abs->personArray[i]=abs->personArray[i+1];
		}
		abs->m_Size--;//����ͨѶ¼�е���Ա��
		cout<<"ɾ���ɹ�"<<endl;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	system("pause");
	system("cls");
}

//4������ϵ��
void findPerson(Addressbooks *abs)
{
	cout<<"�����������ϵ�˵�����"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		cout<<"������ "<<abs->personArray[ret].m_Name<<"  �Ա�  "<<abs->personArray[ret].m_Sex
		<<"  ���䣺  "<<abs->personArray[ret].m_Age<<"  �绰���룺  "<<abs->personArray[ret].m_Phone
		<<"  ��ַ��  "<<abs->personArray [ret].m_Addr<<endl;
		cout<<"�Ա�1��ʾ�У��Ա�2��ʾŮ"<<endl;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	system("pause");
	system("cls");
}

//5�޸�ָ����ϵ��
void editPerson(Addressbooks *abs)
{
	cout<<"��������Ҫ�޸ĵ���ϵ�˵�����"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
		cout<<"��������ϵ�������� "<<endl;
		string name;
		cin>>name;
		abs->personArray[ret].m_Name=name;
		
		cout<<"��������ϵ�˵��Ա�"<<endl;
		cout<<"1--��"<<endl;
		cout<<"2--Ů"<<endl;
		int sex=0;
		cin>>sex;
		while(true)
		{
			if(sex==1 || sex==2)
			{
				abs->personArray[ret].m_Sex=sex;
			}
			else
			{
				cout<<"������������������"<<endl;
			}
			break;
		}
		
		cout<<"��������ϵ�˵����䣺"<<endl;
		int age;
		cin>>age;
		abs->personArray[ret].m_Age=age;

		cout<<"��������ϵ�˵ĵ绰����"<<endl;
		string number;
		cin>>number;
		abs->personArray[ret].m_Phone=number;

		cout<<"��������ϵ�˵ĵ�ַ"<<endl;
		string address;
		cin>>address;
		abs->personArray[ret].m_Addr=address;
		
		cout<<"�޸ĳɹ�"<<endl;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	system("pause");
	system("cls");
}
//6���������ϵ����Ϣ
//ʵ��˼·����ͨѶ¼������Ϊ0�����߼���ռ��ɡ�
void clearPerson(Addressbooks *abs)
{
	abs->m_Size=0;
	cout<<"ͨѶ¼����գ�"<<endl;
	system("pause");
	system("cls");
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size=0;

	int select=0;//�����û�ѡ������ı���
	while(true)
	{
			//�˵�����
	showMenu();

	cin>>select;

	switch(select)
	{
	case 1://1�������ϵ��
		addPerson(&abs);//���õ�ַ���ݣ���������ʵ��
		break;
	case 2://2����ʾ��ϵ��
		showPerson(&abs);
		break;
	case 3://3��ɾ����ϵ��
	deletePerson(&abs);

	//if(isExist(&abs,name)==-1)
	//{
	//	cout<<"û�и���ϵ��"<<endl;
	//}
	//else
	//{
	//	cout<<"����ϵ�˴���"<<endl;
	//}
		break;
	case 4://4��������ϵ��
			findPerson(&abs);
		break;
	case 5://5���޸���ϵ��
		editPerson(&abs);
		break;
	case 6://6�������ϵ��
		clearPerson(&abs);
		break;
	case 0://0���˳�ͨѶ¼
		cout<<"��ӭ�´�ʹ��"<<endl;
		system("pause");
		return 0;
		break;
	default:
		break;
	}
	}
	system("pause");
	return 0;
}