#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>

#define FILENAME "empFile.txt"
using namespace std;

class workerManager
{
public:
	workerManager();//���캯��

	void Show_Menu();//�˵�չʾ

	int m_employeeNum;//ְ������

	Worker** m_employeeArray;//ְ������ָ��


	//����ģ�麯��=============
	void ExitSystem();//�˳�ϵͳ

	void Add_Employee();//����ְ��

	void Show_Employee();//��ʾְ��

	void Del_Employee();//ɾ��ְ��

	void Mod_Employee();//�޸�Ա��

	void Find_Employee();//����ְ��

	void Clean_File();//����ļ�

	void Sort_Employee();//ְ������
	//====================


	void save();//��������

	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

	int get_employeeNum();//ͳ���ļ�������

	void init_employee();//��ʼ��Ա��

	int Is_Exist(int id);//�ж�ְ���Ƿ����

	~workerManager();//��������
};
