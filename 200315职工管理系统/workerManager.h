#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//�������������ͷ�ļ�

using namespace std;//ʹ�ñ�׼�����ռ�
#include<string>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>


#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//ְ���ķ���Ϊ����ͨԱ���������ϰ�
	//������ְ������һ���ࣨworker���У����ö�̬����ְͬ������
	//ְ�������ԣ�ְ����š�ְ��������ְ�����ڲ��ű��
	//ְ������Ϊ����λְ����Ϣ��������ȡ��λ����

	//��¼ְ������
	int m_EmpNun;

	//ְ������ָ��
	Worker ** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();//�����쳣

	//�ļ�����--���ļ�
	//��һ��ʹ�ã��ļ�δ����
	//�ļ����ڣ������ݱ��û����
	//�ļ����ڣ����ұ���ְ������������

	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int Id);

	//�޸�ְ��200327
	void Mod_Emp();

	//����ְ��200327
	void Find_Emp();

	//����ְ���������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkerManager();
};