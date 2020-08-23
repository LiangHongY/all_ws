#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"identity.h"
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<functional>
#include<numeric>
#include<algorithm>
#include"computerRoom.h"


//����Ա���  --200712
class Manager :public Identity
{
public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//ѡ��˵�����
	virtual void operMeun();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������   --200714
	void initVector();

	//����ظ�  ����:(����id,��������) ����ֵ:(true �������ظ���false����û���ظ�)
    //--200714
	bool checkRepeat(int id, int type);

	//ѧ������   --200714
	vector<Student> vStu;

	//��ʦ����   --200714
	vector<Teacher> vTea;

	//��������   --200715
	vector<ComputerRoom> vCom;

};