#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id, string name, int dId);//���캯��
	virtual void showInfo();//��ʾ������Ϣ
	virtual string  getDeptName();//��ȡ��λ����
};
