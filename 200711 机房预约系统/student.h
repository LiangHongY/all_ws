#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include<fstream>
#include"globalFile.h"
#include"computerRoom.h"
#include"orderFile.h"

//ѧ����  
class Student :public Identity           
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��죨ѧ�š����������룩
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMeun();//һ��ʼд����operMenu,δ�ܹ����ظ���������鹹�죬
	                         //����һϵ�д���  --200714

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyorder();

	//�鿴����ԤԼ
	void showAllorder();

	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id;//ѧ��

	//��������  --200715
	vector<ComputerRoom> vCom;
};
