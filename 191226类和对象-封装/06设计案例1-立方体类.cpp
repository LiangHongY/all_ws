#include<iostream>
using namespace std;

//�����������
//����������
//�ֱ�ʹ��ȫ�ֺ����ͳ�Ա�����Ƿ����

//�����������
//�������
//�����Ϊ����ȡ��������
//�ֱ�ʹ��ȫ�ֺ����ͳ�Ա�������ж������������Ƿ����

class Cube
{
	//��Ϊ
	//��ȡ���

	//��ȡ���
public:
	//���ó�
	void setL(int l)
	{
		m_L=l;
	}
	//���ÿ�
		void setW(int w)
	{
		m_W=w;
	}

	//���ø�
	void setH(int h)
	{
		m_H=h;
	}
	//��ȡ��
		int getL()
	{
	    return m_L;
	}
	//��ȡ��
		int getW()
	{
	    return m_W;
	}
	//��ȡ��
		int getH()
	{
	    return m_H;
	}
	//��ȡ���
		int calulateS()
		{
			return 2*(m_L*m_W+m_L*m_H+m_W*m_H);
		}
		//��ȡ���
				int calulateV()
		{
			return m_L*m_W*m_H;
		}
		//���ó�Ա�����ж������������Ƿ����
		bool isSameByclass(Cube &c)
		{
			if(m_L==c.getL()&&m_W==c.getW()&&m_H==c.getH())
			{
				return true;
			}
			else  
				return false;
		}
private:
	//���ԣ�һ������˽��
	int m_L;
	int m_W;
	int m_H;

};
//����ȫ�ֺ����ж������������Ƿ����
bool isSame(Cube &c1,Cube &c2)
{
	if(c1.getL()==c2.getL()&&c1.getW()==c2.getW()&&c1.getH()==c2.getH())
	{
		return true;
	}
	return false;
}


int main()
{
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout<<"c1���Ϊ  "<<c1.calulateS()<<endl;
	cout<<"c1���Ϊ  "<<c1.calulateV()<<endl;

	//�����ڶ���������
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(11);//����֤�����Ƿ�������ʱ��Ӧ��ѡ��򵥵���������֤

	bool ret=isSame(c1,c2);
	if(ret)
	{
		cout <<"c1��c2����ȵ�"<<endl;
	}
	else
	{
		cout<<"c1��c2�ǲ���ȵ�"<<endl;
	}

	//���ó�Ա�����ж�
	ret =c1.isSameByclass(c2);
		if(ret)
	{
		cout <<"��Ա�����жϣ� c1��c2����ȵ�"<<endl;
	}
	else
	{
		cout<<"��Ա�����жϣ� c1��c2�ǲ���ȵ�"<<endl;
	}


	system("pause");
	return 0;
}