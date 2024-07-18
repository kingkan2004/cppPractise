#include"employee.h"

Employee::Employee(int id,string name,int dId)//构造函数
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}
void Employee::showInfo()//显示个人信息
{
	cout << "职工编号：" << this->m_id;
	cout << "\t职工姓名：" << this->m_name;
	cout << "\t职工编号：" << this->getDeptName();
	cout << "\t岗位职责：" << "搬砖" << endl;
}
string  Employee::getDeptName()//获取岗位名称
{
	return string("员工");
}