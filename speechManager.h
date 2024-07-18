#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include"speaker.h"
#include<algorithm>
#include<functional>
#include<numeric>//��ֵ�����ͨ�ú�����������͡����֡��ڻ��Ȳ���
#include<fstream>//�ļ�����
#include<ctime>//�����
using namespace std;

class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//����ģ�麯��=============

	void showMenu();//�˵�����

	void ExitSystem();//�˳�ϵͳ

	void startSpeech();//��ʼ����

	void speechDraw();//��ǩ

	void speechContest();//����

	void showScore();//��ʾ�÷�

	void saveRecord();//�����¼

	void loadRecord();//��ȡ��¼

	bool fileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

	void showRecord();//��ʾ����÷�

	void clearRecord();//�������
	//====================

	//��������
	~SpeechManager();

	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	map<int, vector<string>>m_Record;

	//��Ա����
	//�����һ�ֽ���ѡ�ֱ������
	vector<int>v1;

	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;

	//ʤ��ǰ����ѡ�ֱ������
	vector<int>vVictory;

	//��ű���Լ���Ӧ����ѡ������
	map<int, Speaker>m_Speaker;

	//��ű�������
	int m_Index;
};
