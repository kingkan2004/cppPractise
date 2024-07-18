#include"workerManager.h"

workerManager::workerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_employeeNum = 0;
		this->m_employeeArray = NULL;
		this->m_FileIsEmpty = true;//初始化文件为空
		ifs.close();
		return;
	}
	
	//文件存在，为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_employeeNum = 0;
		this->m_employeeArray = NULL;
		this->m_FileIsEmpty = true; //初始化文件为空
		ifs.close();
		return;
	}

	//文件存在，并且记录数据
	int num = this->get_employeeNum();
	//cout << "职工人数为" << num << endl;
	this->m_employeeNum = num;
	this->m_employeeArray = new Worker * [this->m_employeeNum];
	this->init_employee();
}

void workerManager::Show_Menu()
{
	cout << "		职工管理系统		" << endl;
	cout << "	**------------------------**" << endl;
	cout << "	     0. 退出管理系统" << endl;
	cout << "	     1. 增加职工信息" << endl;
	cout << "	     2. 显示职工信息" << endl;
	cout << "	     3. 删除离职员工" << endl;
	cout << "	     4. 修改职工信息" << endl;
	cout << "	     5. 查找职工信息" << endl;
	cout << "	     6. 按照编号排序" << endl;
	cout << "	     7. 清空所有文档" << endl;
	cout << "	==------------------------==" << endl;
	cout << endl;
}

void workerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void workerManager::Add_Employee()
{
	int addNum = 0;
	cout << "请输入添加的职工的人数：" << endl;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_employeeNum + addNum;//新空间人数 = 原来+新增
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
			cout << "输入第" << i + 1 << "个职工编号" << endl;
			cin >> id;
			cout << "输入第" << i + 1 << "个职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
		this->m_FileIsEmpty = false;//初始化文件不为空
		cout << "成功添加" << addNum << "名职工" << endl;
		this->save();
	}
	else
	{
		cout << "人数输入有误" << endl;
	}
}


void workerManager::save()
{
	if (this->m_employeeArray == NULL)
	{
		return; // 如果数组为空，则直接返回
	}

	ofstream ofs;
	ofs.open(FILENAME, ios::out); // 写文件

	for (int i = 0; i < this->m_employeeNum; i++)
	{
		if (this->m_employeeArray[i] != NULL) // 确保每个指针都不是空指针
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
	ifs.open(FILENAME, ios::in);//打开文件 读
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
	ifs.open(FILENAME, ios::in);//打开文件 读
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//普通职工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//老板
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
	if (!this->m_FileIsEmpty && this->m_employeeArray != NULL) // 判断文件是否为空并且指针不为空
	{
		for (int i = 0; i < m_employeeNum; i++)
		{
			if (this->m_employeeArray[i] != NULL) // 确保每个指针都不是空指针
			{
				this->m_employeeArray[i]->showInfo();
			}
		}
	}
	else
	{
		cout << "文件不存在或为空" << endl;
	}
}


void workerManager::Del_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入要删除的职工编号：";
		cin >> id;
		int index = this->Is_Exist(id);
		if (index != -1)//职工存在
		{
			for (int i = index; i < this->m_employeeNum - 1; i++)
			{
				this->m_employeeArray[i] = this->m_employeeArray[i + 1];
			}
			this->m_employeeNum--;
			this->save();//同步到文件
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "查无此人！" << endl;
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
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入要修改的职工编号：";
		cin >> id;
		int ret = this->Is_Exist(id);
		if (ret != -1)//职工存在
		{
			delete this->m_employeeArray[ret];//释放原有数据
			int new_id;
			string new_name;
			int new_dId;
			int dSelect;

			cout << "输入新的职工编号：" << endl;
			cin >> new_id;
			cout << "输入新的职工姓名：" << endl;
			cin >> new_name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			this->save();//同步到文件
			cout << "修改成功！" << endl;
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}
}

void workerManager::Find_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.职工编号" << endl;
		cout << "2.职工姓名" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入要查找的职工编号：";
			cin >> id;
			int find = this->Is_Exist(id);
			if (find != -1)//职工存在
			{
				cout << "查找成功！" << endl;
				this->m_employeeArray[find]->showInfo();
			}
			else
			{
				cout << "查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找的职工姓名：";
			cin >> name;

			bool flag = false;

			for (int i = 0; i < this->m_employeeNum; i++)
			{
				if (this->m_employeeArray[i]->m_name == name)
				{
					cout << "查找成功！" << endl;
					flag = true;
					this->m_employeeArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入有误！" << endl;
		}

	}
}

void workerManager::Clean_File()
{
	cout << "是否确认清空：" << endl;
	cout << "确认" << endl;
	cout << "按任意键返回" << endl;
	string select;
	cin >> select;
	if (select  == "确认")
	{
		ofstream ofs(FILENAME, ios::trunc);//删除后重新创建
		ofs.close();
		if (this->m_employeeArray != NULL)
		{
			for (int i = 0; i < this->m_employeeNum; i++)
			{
				delete this->m_employeeArray[i];
				this->m_employeeArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_employeeArray;
			this->m_employeeArray = NULL;
			this->m_employeeNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
}

void workerManager::Sort_Employee()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
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
					cout << "请输入正确的选项" << endl;
				}
			}
			if (i != MinOrMax)
			{
				Worker* temp = this->m_employeeArray[i];
				this->m_employeeArray[i] = this->m_employeeArray[MinOrMax];
				this->m_employeeArray[MinOrMax] = temp;
			}
		}
		cout << "排序成功！" <<"结果如下：" <<  endl;
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