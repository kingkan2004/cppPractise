#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
	virtual void showInfo() = 0;//显示个人信息
	virtual string  getDeptName() = 0;//获取岗位名称

	int m_id;
	string m_name;
	int m_deptId;//部门编号
};