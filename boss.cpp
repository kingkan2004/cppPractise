#include"boss.h"
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptId = dId;
}
void Boss::showInfo()//��ʾ������Ϣ
{
	cout << "ְ����ţ�" << this->m_id;
	cout << "\tְ��������" << this->m_name;
	cout << "\tְ����ţ�" << this->getDeptName();
	cout << "\t��λְ��" << "�������е���" << endl;
}
string  Boss::getDeptName()//��ȡ��λ����
{
	return string("�ϰ�");
}