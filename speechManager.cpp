#include"speechManager.h"

//构造函数
SpeechManager::SpeechManager()
{
	//初始化容器与属性
	this->initSpeech();
	//创建12名选手
	this->createSpeaker();
	// 加载往届记录
	this->loadRecord();
}


//菜单功能
void SpeechManager::showMenu()
{
	cout << "欢迎参加演讲比赛" << endl;
	cout << "=================" << endl;
	cout << "1.开始演讲比赛" << endl;
	cout << "2.查看往届记录" << endl;
	cout << "3.清空比赛记录" << endl;
	cout << "0.退出比赛程序" << endl;
	cout << "=================" << endl;
}

//退出系统功能
void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//初始化容器和属性
void SpeechManager::initSpeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛论数
	this->m_Index = 1;

	//将记录容器清空
	this->m_Record.clear();
}

//创建12名选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		
        //创建具体选手
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		//创建选手编号，并且放入v1容器中
		this->v1.push_back(i + 10001);

		//选手编号以及对应选手放入map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//开始比赛
void SpeechManager::startSpeech()
{
	//第一轮开始比赛

	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示晋级结果
	this->showScore();
	//第二轮开始比赛
	this->m_Index++;
	//1.抽签
	this->speechDraw();
	//2.比赛
	this->speechContest();
	//3.显示最终结果
	this->showScore();
	//4.保存分数到文件中
	this->saveRecord();

	//重置比赛，获取记录
	//初始化容器与属性
	this->initSpeech();
	//创建12名选手
	this->createSpeaker();
	// 加载往届记录
	this->loadRecord();

	cout << "本届比赛圆满结束" << endl;
}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第" << this->m_Index << "轮比赛选手正在抽签" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下:" << endl;

	if (this->m_Index == 1)
	{
		//第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin();it != v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << " \n" << endl;
	}
	else
	{
		//第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

//比赛
void SpeechManager::speechContest()
{
	cout << "=======第" << this->m_Index << "轮比赛正式开始=======" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//记录人员个数6人一组

	vector<int>v_Src;//比赛选手容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>d;
		for (int i = 1; i <= 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;//600~1000
			//cout << "裁判" << i << " 分数:" << score << endl;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//排序->降序
		d.pop_front();//去除最高分
		d.pop_back();//去除最低分

		double sum = accumulate(d.begin(), d.end(),0.0f);//总分
		double avg = sum / (double)d.size();//平均分

		//打印平均分
		//cout << "编号：" << *it << " " << this->m_Speaker[*it].m_Name << " " << "平均分：" << avg << endl;

		//将平均分放入map容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据放入临时小组容器中
		groupScore.insert(make_pair(avg, *it));//key是得分，value是具体选手编号
		
		//每六人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "组比赛名次如下：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " " << this->m_Speaker[it->second].m_Name << " 成绩:" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double,int,greater<double>>::iterator it = groupScore.begin();it != groupScore.end() && count < 3;it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();//小组容器清空
			cout << endl;
		}
	}
}

//显示得分
void SpeechManager::showScore()
{
	cout << "=======第" << this->m_Index << "轮晋级选手如下：=======" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout <<"编号："<<*it<<" "<<this->m_Speaker[*it].m_Name<<" 成绩："<< this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
}

//保存记录
void SpeechManager::saveRecord() 
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件

	//将每个选手数据写入文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] <<",";
	}
	ofs << endl;
	

	//关闭
	ofs.close();
	cout << "记录保存成功" << endl;
}

//读取记录
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件清空了
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);//将上面读取的单个字符放回来

	string data;
	int index = 0;

	while (ifs >> data)
	{
		vector<string>v;//存放往届记录

		//cout << data;
		int pos = -1;//查到逗号位置的变量
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);

			if (pos == -1)//没有找到的情况
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;//移动起始位置
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

//显示往届得分
void SpeechManager::showRecord()
{
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届" << endl
			<< "冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << endl
			<< "亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << endl
			<< "季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
	}
}

//清空数据
void SpeechManager::clearRecord()
{
	cout << "是否确认清空：" << endl;
	cout << "确认" << endl;
	cout << "按任意键返回" << endl;
	string select;
	cin >> select;
	if (select == "确认")
	{
		ofstream ofs("speech.csv", ios::trunc);//删除后重新创建
		ofs.close();
		//初始化容器与属性
		this->initSpeech();
		//创建12名选手
		this->createSpeaker();
		// 加载往届记录
		this->loadRecord();
		cout << "清空成功" << endl;
	}
}

//析构函数
SpeechManager::~SpeechManager()
{

}
