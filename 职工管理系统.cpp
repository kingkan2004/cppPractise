#include"workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main()
{
	workerManager wm;
	
	int choice = 0;//�û�ѡ��

	while (true)
	{
		wm.Show_Menu();
		cout << "����������Ҫ�Ĺ��ܴ��룺";
		cin >> choice;
		if (choice >= 0 && choice <= 7)
		{
			switch (choice)
			{
			case 1://����ְ����Ϣ
				wm.Add_Employee();
				break;
			case 2://��ʾְ����Ϣ
				wm.Show_Employee();
				break;
			case 3://ɾ����ְԱ��
				wm.Del_Employee();
				break;
			case 4://�޸�ְ����Ϣ
				wm.Mod_Employee();
				break;
			case 5://����ְ����Ϣ
				wm.Find_Employee();
				break;
			case 6://���ձ������
				wm.Sort_Employee();
				break;
			case 7://��������ĵ�
				wm.Clean_File();
				break;
			case 0://�˳�
				wm.ExitSystem();
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "��������ȷ��ʽ�Ĺ��ܴ��롣" << endl;
		}
		//����
		system("pause");
		system("cls");
	}
	return 0;
}
