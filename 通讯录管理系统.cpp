#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	char m_Sex;//m-�У�f-Ů
	int m_Age;
	string m_Phone;//�绰����
	string m_Addr;//��ַ
};

//ͨѶ¼�ṹ��
struct AddressBooks
{
	struct Person personArray[MAX];
	int m_Size;//ͨѶ¼��Ա����
};

//�˵�����
void ShowMenu()//�˵�����
{
	cout << " ** ͨ Ѷ ¼ �� �� ϵ ͳ **" << endl;
	cout << "----------------------------" << endl;
	cout << "****\t1.�����ϵ��\t****" << endl;
	cout << "****\t2.��ʾ��ϵ��\t****" << endl;
	cout << "****\t3.ɾ����ϵ��\t****" << endl;
	cout << "****\t4.������ϵ��\t****" << endl;
	cout << "****\t5.�޸���ϵ��\t****" << endl;
	cout << "****\t6.�����ϵ��\t****" << endl;
	cout << "****\t0.�˳�ͨѶ¼\t****" << endl;
	cout << "----------------------------" << endl;
}

//�����ϵ�˺���
void personAdd(AddressBooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size >= MAX)
	{
		cout << "ͨѶ¼�������޷������" << endl;
		//����
		system("pause");
		system("cls");
		return;
	}

	//����
	string name;
	cout << "������������";
	cin >> name;

	// �ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷������" << endl;
		return;
	}

	abs->personArray[abs->m_Size].m_Name = name;

	//�Ա�
	char sex;
	cout << "�������Ա�m-�У�f-Ů:";
	while (true)
	{
		cin >> sex;
		if (sex == 'm' || sex == 'f')
		{
			abs->personArray[abs->m_Size].m_Sex = sex;
			break;
		}
		else
		{
			cout << "��������ȷ��ʽ���Ա�" << endl;
		}
	}
	//����
	int age = 0;
	cout << "���������䣺";
	while (true)
	{
		cin >> age;
		if (age > 0 && age < 200)
		{
			abs->personArray[abs->m_Size].m_Age = age;
			break;
		}
		else
		{
			cout << "��������ȷ��ʽ�����䡣" << endl;
		}
	}
	//�绰����
	string phone;
	cout << "������绰���룺";
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;
	//��ַ
	string address;
	cout << "�������ַ��";
	cin >> address;
	abs->personArray[abs->m_Size].m_Addr = address;
	// ����ͨѶ¼��С
	abs->m_Size++;
	cout << "��ӳɹ�" << endl;
	//����
	system("pause");
	system("cls");
}

//��ʾ��ϵ�˺���
void personShow(AddressBooks* abs)
{
	//�ж��Ƿ�Ϊ��
	if (abs->m_Size == 0)
	{
		cout << "��¼Ϊ��" << endl; 
		//����
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name
				 << " �Ա�" << (abs->personArray[i].m_Sex == 'm'?"��":"Ů")
				 << " ����:" << abs->personArray[i].m_Age 
				 << " �绰:" << abs->personArray[i].m_Phone
				 << " ��ַ��" << abs->personArray[i].m_Addr << endl;
		}
		//����
		system("pause");
		system("cls");
	}
}

//�����ϵ���Ƿ���ں���--ͨ����������
int isExist(AddressBooks* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (name == abs->personArray[i].m_Name)
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ�˺���
void personDelete(AddressBooks* abs)
{
	string name;
	cout << "������Ҫɾ������ϵ�ˣ�";
	cin >> name;
	int n = isExist(abs, name);
	if (n == -1)
	{
		cout << "���޴���" << endl;
		//����
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = n; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			abs->m_Size--;
		}
		cout << "ɾ���ɹ���" << endl;
		//����
		system("pause");
		system("cls");
	}
}

//������ϵ�˺���
void personSearch(AddressBooks* abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ�ˣ�";
	cin >> name;
	int n = isExist(abs, name);
	if (n == -1)
	{
		cout << "���޴���" << endl;
		//����
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������" << abs->personArray[n].m_Name
			<< " �Ա�" << (abs->personArray[n].m_Sex == 'm' ? "��" : "Ů")
			<< " ����:" << abs->personArray[n].m_Age
			<< " �绰:" << abs->personArray[n].m_Phone
			<< " ��ַ��" << abs->personArray[n].m_Addr << endl;
		//����
		system("pause");
		system("cls");
	}
}

//�޸���ϵ�˺���
void personModify(AddressBooks* abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ�ˣ�";
	cin >> name;
	int n = isExist(abs, name);
	if (n == -1)
	{
		cout << "���޴���" << endl;
		//����
		system("pause");
		system("cls");
	}
	else
	{
		//�ж�ͨѶ¼�Ƿ�����
		if (abs->m_Size >= MAX)
		{
			cout << "ͨѶ¼�������޷������" << endl;
			//����
			system("pause");
			system("cls");
			return;
		}

		//����
		string name;
		cout << "������������";
		cin >> name;

		// �ж�ͨѶ¼�Ƿ�����
		if (abs->m_Size == MAX)
		{
			cout << "ͨѶ¼�������޷������" << endl;
			return;
		}

		abs->personArray[n].m_Name = name;

		//�Ա�
		char sex;
		cout << "�������Ա�m-�У�f-Ů:";
		while (true)
		{
			cin >> sex;
			if (sex == 'm' || sex == 'f')
			{
				abs->personArray[n].m_Sex = sex;
				break;
			}
			else
			{
				cout << "��������ȷ��ʽ���Ա�" << endl;
			}
		}
		//����
		int age = 0;
		cout << "���������䣺";
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 200)
			{
				abs->personArray[n].m_Age = age;
				break;
			}
			else
			{
				cout << "��������ȷ��ʽ�����䡣" << endl;
			}
		}
		//�绰����
		string phone;
		cout << "������绰���룺";
		cin >> phone;
		abs->personArray[n].m_Phone = phone;
		//��ַ
		string address;
		cout << "�������ַ��";
		cin >> address;
		abs->personArray[n].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
		//����
		system("pause");
		system("cls");
	}
}

//�����ϵ�˺���
void personClean(AddressBooks* abs)
{
	abs->m_Size = 0;
	cout << "��ϵ����ȫ����ա�" << endl;
	//����
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	struct AddressBooks abs1;
	abs1.m_Size = 0; // ��ʼ��ͨѶ¼��СΪ 0
	while (true)
	{
		ShowMenu();
		cout << "����������Ҫ�Ĺ��ܴ��룺";
		cin >> select;
		if (select >= 0 && select <= 6)
		{
			switch (select)
			{
			case 1://�����ϵ��
				personAdd(&abs1);//ͨ����ַ����
				break;
			case 2://��ʾ��ϵ��
				personShow(&abs1);
				break;
			case 3://ɾ����ϵ��
				personDelete(&abs1);
				break;
			case 4://������ϵ��
				personSearch(&abs1);
				break;
			case 5://�޸���ϵ��
				personModify(&abs1);
				break;
			case 6://�����ϵ��
				personClean(&abs1);
				break;
			case 0://�˳�ͨѶ¼
				cout << "��ӭ�ٴ�ʹ��" << endl;
				exit(0);
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "��������ȷ��ʽ�Ĺ��ܴ��롣" << endl;
			//����
			system("pause");
			system("cls");
		}
	}
	return 0;
}