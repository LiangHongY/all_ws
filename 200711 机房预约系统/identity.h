#pragma once  //��ֹͷ�ļ��ظ�����
#include<iostream>
#include<string>
using namespace std;

//��ݳ��� �� �� --200712
class Identity
{
public:
	//�����˵�  ���麯��
	virtual void operMeun() = 0;

	string m_Name;//�û���
	string m_Pwd;//����
};