#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"orderFile.h"
#include<vector>

class Teacher : public Identity   //--200712
{
public:

	//Ĭ�Ϲ���
	Teacher();

	//�вι��죨ְ����š����������룩
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMeun();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId;//��ʦ���
};