#include"employee.h"

Employee::Employee(int id,string name,int dId)//���캯��
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}
void Employee::showInfo()//��ʾ������Ϣ
{
	cout << "ְ����ţ�" << this->m_id;
	cout << "\tְ��������" << this->m_name;
	cout << "\tְ����ţ�" << this->getDeptName();
	cout << "\t��λְ��" << "��ש" << endl;
}
string  Employee::getDeptName()//��ȡ��λ����
{
	return string("Ա��");
}