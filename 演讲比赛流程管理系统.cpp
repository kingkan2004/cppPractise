#include"speechManager.h"
using namespace std;

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//创建管理类对象
	SpeechManager sm;

	////测试
	//for(map<int,Speaker>::iterator it = sm.m_Speaker.begin();it != sm.m_Speaker.end();it++)
	//{
	//	cout << (*it).first << " " << (*it).second.m_Name << " " << (*it).second.m_Score[0] << endl;
	//}

	int choice = 0;//用户选择

	while (true)
	{
		sm.showMenu();//菜单
		cout << "请输入您想要的功能代码：";
		cin >> choice;
		if (choice >= 0 && choice <= 7)
		{
			switch (choice)
			{
			case 1://开始演讲比赛
				sm.startSpeech();
				break;
			case 2://查看往届记录
				sm.showRecord();
				break;
			case 3://清空比赛记录
				sm.clearRecord();
				break;
			case 0://退出比赛程序
				sm.ExitSystem();
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