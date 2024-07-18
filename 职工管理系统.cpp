#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main()
{
	workerManager wm;
	
	int choice = 0;//用户选择

	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您想要的功能代码：";
		cin >> choice;
		if (choice >= 0 && choice <= 7)
		{
			switch (choice)
			{
			case 1://增加职工信息
				wm.Add_Employee();
				break;
			case 2://显示职工信息
				wm.Show_Employee();
				break;
			case 3://删除离职员工
				wm.Del_Employee();
				break;
			case 4://修改职工信息
				wm.Mod_Employee();
				break;
			case 5://查找职工信息
				wm.Find_Employee();
				break;
			case 6://按照编号排序
				wm.Sort_Employee();
				break;
			case 7://清空所有文档
				wm.Clean_File();
				break;
			case 0://退出
				wm.ExitSystem();
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "请输入正确格式的功能代码。" << endl;
		}
		//清屏
		system("pause");
		system("cls");
	}
	return 0;
}
