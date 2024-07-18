#include"workerManager.h"

workerManager::workerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_employeeNum = 0;
		this->m_employeeArray = NULL;
		this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ��
		ifs.close();
		return;
	}
	
	//�ļ����ڣ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_employeeNum = 0;
		this->m_employeeArray = NULL;
		this->m_FileIsEmpty = true; //��ʼ���ļ�Ϊ��
		ifs.close();
		return;
	}

	//�ļ����ڣ����Ҽ�¼����
	int num = this->get_employeeNum();
	//cout << "ְ������Ϊ" << num << endl;
	this->m_employeeNum = num;
	this->m_employeeArray = new Worker * [this->m_employeeNum];
	this->init_employee();
}

void workerManager::Show_Menu()
{
	cout << "		ְ������ϵͳ		" << endl;
	cout << "	**------------------------**" << endl;
	cout << "	     0. �˳�����ϵͳ" << endl;
	cout << "	     1. ����ְ����Ϣ" << endl;
	cout << "	     2. ��ʾְ����Ϣ" << endl;
	cout << "	     3. ɾ����ְԱ��" << endl;
	cout << "	     4. �޸�ְ����Ϣ" << endl;
	cout << "	     5. ����ְ����Ϣ" << endl;
	cout << "	     6. ���ձ������" << endl;
	cout << "	     7. ��������ĵ�" << endl;
	cout << "	==------------------------==" << endl;
	cout << endl;
}

void workerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void workerManager::Add_Employee()
{
	int addNum = 0;
	cout << "��������ӵ�ְ����������" << endl;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_employeeNum + addNum;//�¿ռ����� = ԭ��+����
		Worker** newSpace = new Worker * [newSize];

		if (this->m_employeeArray != NULL)
		{
			for (int i = 0; i < this->m_employeeNum; i++)
			{
				newSpace[i] = this->m_employeeArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�����" << i + 1 << "��ְ�����" << endl;
			cin >> id;
			cout << "�����" << i + 1 << "��ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_employeeNum + i] = worker;
		}
		delete[]this->m_employeeArray;
		this->m_employeeArray = newSpace;
		this->m_employeeNum = newSize;
		this->m_FileIsEmpty = false;//��ʼ���ļ���Ϊ��
		cout << "�ɹ����" << addNum << "��ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}
}


void workerManager::save()
{
	if (this->m_employeeArray == NULL)
	{
		return; // �������Ϊ�գ���ֱ�ӷ���
	}

	ofstream ofs;
	ofs.open(FILENAME, ios::out); // д�ļ�

	for (int i = 0; i < this->m_employeeNum; i++)
	{
		if (this->m_employeeArray[i] != NULL) // ȷ��ÿ��ָ�붼���ǿ�ָ��
		{
			ofs << this->m_employeeArray[i]->m_id << " "
				<< this->m_employeeArray[i]->m_name << " "
				<< this->m_employeeArray[i]->m_deptId << endl;
		}
	}

	ofs.close();
}


int workerManager::get_employeeNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ��
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void workerManager::init_employee()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ��
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_employeeArray[index] = worker;
		index++;
	}
	ifs.close();
}

void workerManager::Show_Employee()
{
	if (!this->m_FileIsEmpty && this->m_employeeArray != NULL) // �ж��ļ��Ƿ�Ϊ�ղ���ָ�벻Ϊ��
	{
		for (int i = 0; i < m_employeeNum; i++)
		{
			if (this->m_employeeArray[i] != NULL) // ȷ��ÿ��ָ�붼���ǿ�ָ��
			{
				this->m_employeeArray[i]->showInfo();
			}
		}
	}
	else
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
}


void workerManager::Del_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ����ְ����ţ�";
		cin >> id;
		int index = this->Is_Exist(id);
		if (index != -1)//ְ������
		{
			for (int i = index; i < this->m_employeeNum - 1; i++)
			{
				this->m_employeeArray[i] = this->m_employeeArray[i + 1];
			}
			this->m_employeeNum--;
			this->save();//ͬ�����ļ�
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
}

int workerManager::Is_Exist(int id)
{
	int index = -1;
	for (int i = 0; i < m_employeeNum; i++)
	{
		if (this->m_employeeArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void workerManager::Mod_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫ�޸ĵ�ְ����ţ�";
		cin >> id;
		int ret = this->Is_Exist(id);
		if (ret != -1)//ְ������
		{
			delete this->m_employeeArray[ret];//�ͷ�ԭ������
			int new_id;
			string new_name;
			int new_dId;
			int dSelect;

			cout << "�����µ�ְ����ţ�" << endl;
			cin >> new_id;
			cout << "�����µ�ְ��������" << endl;
			cin >> new_name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(new_id, new_name, dSelect);
				break;
			case 2:
				worker = new Manager(new_id, new_name, dSelect);
				break;
			case 3:
				worker = new Boss(new_id, new_name, dSelect);
				break;
			default:
				break;
			}
			this->m_employeeArray[ret] = worker;
			this->save();//ͬ�����ļ�
			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "���޴��ˣ�" << endl;
		}
	}
}

void workerManager::Find_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.ְ�����" << endl;
		cout << "2.ְ������" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "������Ҫ���ҵ�ְ����ţ�";
			cin >> id;
			int find = this->Is_Exist(id);
			if (find != -1)//ְ������
			{
				cout << "���ҳɹ���" << endl;
				this->m_employeeArray[find]->showInfo();
			}
			else
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�ְ��������";
			cin >> name;

			bool flag = false;

			for (int i = 0; i < this->m_employeeNum; i++)
			{
				if (this->m_employeeArray[i]->m_name == name)
				{
					cout << "���ҳɹ���" << endl;
					flag = true;
					this->m_employeeArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "���޴��ˣ�" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}

	}
}

void workerManager::Clean_File()
{
	cout << "�Ƿ�ȷ����գ�" << endl;
	cout << "ȷ��" << endl;
	cout << "�����������" << endl;
	string select;
	cin >> select;
	if (select  == "ȷ��")
	{
		ofstream ofs(FILENAME, ios::trunc);//ɾ�������´���
		ofs.close();
		if (this->m_employeeArray != NULL)
		{
			for (int i = 0; i < this->m_employeeNum; i++)
			{
				delete this->m_employeeArray[i];
				this->m_employeeArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_employeeArray;
			this->m_employeeArray = NULL;
			this->m_employeeNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
}

void workerManager::Sort_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < m_employeeNum; i++)
		{
			int MinOrMax = i;
			for (int j = 0;  j < i + 1;  j++)
			{
				if (select == 1)
				{
					if (this->m_employeeArray[MinOrMax]->m_id < this->m_employeeArray[j]->m_id)
					{
						MinOrMax = j;
					}
				}
				else if (select == 2)
				{
					if (this->m_employeeArray[MinOrMax]->m_id > this->m_employeeArray[j]->m_id)
					{
						MinOrMax = j;
					}
				}
				else
				{
					cout << "��������ȷ��ѡ��" << endl;
				}
			}
			if (i != MinOrMax)
			{
				Worker* temp = this->m_employeeArray[i];
				this->m_employeeArray[i] = this->m_employeeArray[MinOrMax];
				this->m_employeeArray[MinOrMax] = temp;
			}
		}
		cout << "����ɹ���" <<"������£�" <<  endl;
		this->save();
		this->Show_Employee();
	}
}

workerManager::~workerManager()
{
	if (this->m_employeeArray!=NULL)
	{
		delete[]this->m_employeeArray;
		this->m_employeeArray = NULL;
	}
}