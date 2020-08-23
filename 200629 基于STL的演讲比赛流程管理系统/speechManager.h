#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>     //
#include<functional>
#include<numeric>    
#include<string>     //�ַ�������
#include<fstream>   //��д�ļ�
#include<ctime>     //�����������Ҫϵͳʱ����������

using namespace std;

//����ݽ�������
class SpeechManager
{
public:
	//���캯�� --200705
	SpeechManager();

	//��ʾ�˵�  --200705
	void show_Menu();

	//�˳�����  --200705
	void exitSystem();

	//��Ա�������  --200705
	//����ѡ��   ����  12��
	vector<int>v1;
	//��һ�ֽ�������   6��
	vector<int>v2;
	//ʤ��ǰ��������   3��
	vector<int>vVictory;
	//��ű��  �Լ���Ӧ��  ����ѡ��  ����
	map<int, Speaker> m_Speaker;
	//��¼��������
	int m_Index;

	//��ʼ�����ĳ�Ա���� --200705
	//��ʼ������������
	void initSpeech();

	//�ṩ��ʼ�ݽ������ĳ�Ա����,����12��ѡ��  --200705
	void createSpeaker();

	//��ʼ����   �����������̿��ƺ���    --200705
	void startspeech();

	//��ǩ     --200705
	void speechDraw();

	// ����  --200706
	void speechContest();

	//��ʾ�������  --200707
	void showScore();

	//��������    --200707
	void saveRecord();

	//��ȡ��¼   --200708
	void loadRecord();

	//�ļ�Ϊ�ձ�־   --200708
	bool fileIsEmpty;

	//��¼�����¼   --200708
	map<int, vector<string>> m_Record;

	//�鿴��¼����   --200709
	void showRecord();

	//��ռ�¼   --200710
	void clearRecord();


	//��������  --200705
	~SpeechManager();
};