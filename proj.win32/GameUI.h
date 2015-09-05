#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class GameUI :	public cocos2d::Layer
{
public:
	virtual bool init();
	// �˵��ص�����
	void menuBeginCallback(Ref* sender);
	void menuQuitCallback(Ref* sender);
	void menuResumeCallback(Ref* sender);
	void menuReplayCallback(Ref* sender);
	void menuSoundCallback(Ref* sender);
	void menuNextCallback(Ref* sender);
	// �˵�����
	void ShowBegin();
	void ShowNext();
	void ShowResume();
	void ShowReplay();
	void HideAll();

	GameUI(void);
	~GameUI(void);
	CREATE_FUNC(GameUI);
private:
	Menu* menu;
	MenuItem* menuItem_begin;
	MenuItem* menuItem_next;
	MenuItem* menuItem_quit;
	MenuItem* menuItem_resume;
	MenuItem* menuItem_replay;
	MenuItem* menuItem_sound;
	// �˵�����ʾ������
	Action* hideMove;
	Action* showMove;
	Vec2 visibleSize;
};

