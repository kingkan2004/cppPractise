#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager :public Worker
{
public:
	Manager(int id,string name,int dId);
	virtual void showInfo();//��ʾ������Ϣ
	virtual string  getDeptName();//��ȡ��λ����
};
