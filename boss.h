#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Boss :public Worker
{
public:
	Boss(int id, string name, int dId);
	virtual void showInfo();//显示个人信息
	virtual string  getDeptName();//获取岗位名称
};
