#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include"speaker.h"
#include<algorithm>
#include<functional>
#include<numeric>//数值计算的通用函数，例如求和、积分、内积等操作
#include<fstream>//文件操作
#include<ctime>//随机数
using namespace std;

class SpeechManager
{
public:
	//构造函数
	SpeechManager();

	//功能模块函数=============

	void showMenu();//菜单功能

	void ExitSystem();//退出系统

	void startSpeech();//开始比赛

	void speechDraw();//抽签

	void speechContest();//比赛

	void showScore();//显示得分

	void saveRecord();//保存记录

	void loadRecord();//读取记录

	bool fileIsEmpty;//判断文件是否为空

	void showRecord();//显示往届得分

	void clearRecord();//清空数据
	//====================

	//析构函数
	~SpeechManager();

	//初始化容器和属性
	void initSpeech();

	//创建12名选手
	void createSpeaker();

	map<int, vector<string>>m_Record;

	//成员属性
	//保存第一轮晋级选手编号容器
	vector<int>v1;

	//第一轮晋级选手编号容器
	vector<int>v2;

	//胜出前三名选手编号容器
	vector<int>vVictory;

	//存放编号以及对应具体选手容器
	map<int, Speaker>m_Speaker;

	//存放比赛轮数
	int m_Index;
};
