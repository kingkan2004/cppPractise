#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//联系人结构体
struct Person
{
	string m_Name;
	char m_Sex;//m-男，f-女
	int m_Age;
	string m_Phone;//电话号码
	string m_Addr;//地址
};

//通讯录结构体
struct AddressBooks
{
	struct Person personArray[MAX];
	int m_Size;//通讯录人员个数
};

//菜单函数
void ShowMenu()//菜单函数
{
	cout << " ** 通 讯 录 管 理 系 统 **" << endl;
	cout << "----------------------------" << endl;
	cout << "****\t1.添加联系人\t****" << endl;
	cout << "****\t2.显示联系人\t****" << endl;
	cout << "****\t3.删除联系人\t****" << endl;
	cout << "****\t4.查找联系人\t****" << endl;
	cout << "****\t5.修改联系人\t****" << endl;
	cout << "****\t6.清空联系人\t****" << endl;
	cout << "****\t0.退出通讯录\t****" << endl;
	cout << "----------------------------" << endl;
}

//添加联系人函数
void personAdd(AddressBooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_Size >= MAX)
	{
		cout << "通讯录已满，无法再添加" << endl;
		//清屏
		system("pause");
		system("cls");
		return;
	}

	//姓名
	string name;
	cout << "请输入姓名：";
	cin >> name;

	// 判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法再添加" << endl;
		return;
	}

	abs->personArray[abs->m_Size].m_Name = name;

	//性别
	char sex;
	cout << "请输入性别，m-男，f-女:";
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
			cout << "请输入正确格式的性别。" << endl;
		}
	}
	//年龄
	int age = 0;
	cout << "请输入年龄：";
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
			cout << "请输入正确格式的年龄。" << endl;
		}
	}
	//电话号码
	string phone;
	cout << "请输入电话号码：";
	cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;
	//地址
	string address;
	cout << "请输入地址：";
	cin >> address;
	abs->personArray[abs->m_Size].m_Addr = address;
	// 更新通讯录大小
	abs->m_Size++;
	cout << "添加成功" << endl;
	//清屏
	system("pause");
	system("cls");
}

//显示联系人函数
void personShow(AddressBooks* abs)
{
	//判断是否为空
	if (abs->m_Size == 0)
	{
		cout << "记录为空" << endl; 
		//清屏
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name
				 << " 性别：" << (abs->personArray[i].m_Sex == 'm'?"男":"女")
				 << " 年龄:" << abs->personArray[i].m_Age 
				 << " 电话:" << abs->personArray[i].m_Phone
				 << " 地址：" << abs->personArray[i].m_Addr << endl;
		}
		//清屏
		system("pause");
		system("cls");
	}
}

//检测联系人是否存在函数--通过姓名检索
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

//删除联系人函数
void personDelete(AddressBooks* abs)
{
	string name;
	cout << "请输入要删除的联系人：";
	cin >> name;
	int n = isExist(abs, name);
	if (n == -1)
	{
		cout << "查无此人" << endl;
		//清屏
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
		cout << "删除成功。" << endl;
		//清屏
		system("pause");
		system("cls");
	}
}

//查找联系人函数
void personSearch(AddressBooks* abs)
{
	string name;
	cout << "请输入要查找的联系人：";
	cin >> name;
	int n = isExist(abs, name);
	if (n == -1)
	{
		cout << "查无此人" << endl;
		//清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "姓名：" << abs->personArray[n].m_Name
			<< " 性别：" << (abs->personArray[n].m_Sex == 'm' ? "男" : "女")
			<< " 年龄:" << abs->personArray[n].m_Age
			<< " 电话:" << abs->personArray[n].m_Phone
			<< " 地址：" << abs->personArray[n].m_Addr << endl;
		//清屏
		system("pause");
		system("cls");
	}
}

//修改联系人函数
void personModify(AddressBooks* abs)
{
	string name;
	cout << "请输入要查找的联系人：";
	cin >> name;
	int n = isExist(abs, name);
	if (n == -1)
	{
		cout << "查无此人" << endl;
		//清屏
		system("pause");
		system("cls");
	}
	else
	{
		//判断通讯录是否已满
		if (abs->m_Size >= MAX)
		{
			cout << "通讯录已满，无法再添加" << endl;
			//清屏
			system("pause");
			system("cls");
			return;
		}

		//姓名
		string name;
		cout << "请输入姓名：";
		cin >> name;

		// 判断通讯录是否已满
		if (abs->m_Size == MAX)
		{
			cout << "通讯录已满，无法再添加" << endl;
			return;
		}

		abs->personArray[n].m_Name = name;

		//性别
		char sex;
		cout << "请输入性别，m-男，f-女:";
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
				cout << "请输入正确格式的性别。" << endl;
			}
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：";
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
				cout << "请输入正确格式的年龄。" << endl;
			}
		}
		//电话号码
		string phone;
		cout << "请输入电话号码：";
		cin >> phone;
		abs->personArray[n].m_Phone = phone;
		//地址
		string address;
		cout << "请输入地址：";
		cin >> address;
		abs->personArray[n].m_Addr = address;
		cout << "修改成功" << endl;
		//清屏
		system("pause");
		system("cls");
	}
}

//清空联系人函数
void personClean(AddressBooks* abs)
{
	abs->m_Size = 0;
	cout << "联系人已全部清空。" << endl;
	//清屏
	system("pause");
	system("cls");
}

int main()
{
	int select = 0;
	struct AddressBooks abs1;
	abs1.m_Size = 0; // 初始化通讯录大小为 0
	while (true)
	{
		ShowMenu();
		cout << "请输入您想要的功能代码：";
		cin >> select;
		if (select >= 0 && select <= 6)
		{
			switch (select)
			{
			case 1://添加联系人
				personAdd(&abs1);//通过地址传递
				break;
			case 2://显示联系人
				personShow(&abs1);
				break;
			case 3://删除联系人
				personDelete(&abs1);
				break;
			case 4://查找联系人
				personSearch(&abs1);
				break;
			case 5://修改联系人
				personModify(&abs1);
				break;
			case 6://清空联系人
				personClean(&abs1);
				break;
			case 0://退出通讯录
				cout << "欢迎再次使用" << endl;
				exit(0);
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "请输入正确格式的功能代码。" << endl;
			//清屏
			system("pause");
			system("cls");
		}
	}
	return 0;
}