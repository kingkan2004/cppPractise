#pragma once//防止头文件重复包含
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
	workerManager();//构造函数

	void Show_Menu();//菜单展示

	int m_employeeNum;//职工人数

	Worker** m_employeeArray;//职工数组指针


	//功能模块函数=============
	void ExitSystem();//退出系统

	void Add_Employee();//增加职工

	void Show_Employee();//显示职工

	void Del_Employee();//删除职工

	void Mod_Employee();//修改员工

	void Find_Employee();//查找职工

	void Clean_File();//清空文件

	void Sort_Employee();//职工排序
	//====================


	void save();//保存数据

	bool m_FileIsEmpty;//判断文件是否为空

	int get_employeeNum();//统计文件中人数

	void init_employee();//初始化员工

	int Is_Exist(int id);//判断职工是否存在

	~workerManager();//析构函数
};
