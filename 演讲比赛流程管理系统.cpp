#include"speechManager.h"
using namespace std;

int main()
{
	//���������
	srand((unsigned int)time(NULL));

	//�������������
	SpeechManager sm;

	////����
	//for(map<int,Speaker>::iterator it = sm.m_Speaker.begin();it != sm.m_Speaker.end();it++)
	//{
	//	cout << (*it).first << " " << (*it).second.m_Name << " " << (*it).second.m_Score[0] << endl;
	//}

	int choice = 0;//�û�ѡ��

	while (true)
	{
		sm.showMenu();//�˵�
		cout << "����������Ҫ�Ĺ��ܴ��룺";
		cin >> choice;
		if (choice >= 0 && choice <= 7)
		{
			switch (choice)
			{
			case 1://��ʼ�ݽ�����
				sm.startSpeech();
				break;
			case 2://�鿴�����¼
				sm.showRecord();
				break;
			case 3://��ձ�����¼
				sm.clearRecord();
				break;
			case 0://�˳���������
				sm.ExitSystem();
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