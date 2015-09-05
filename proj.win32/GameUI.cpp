#include "GameUI.h"


GameUI::GameUI(void)
{
}

bool GameUI::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
	auto centerPoint = origin+visibleSize/2;
	// ��ʼ�˵� 
	menuItem_begin = MenuItemFont::create("Begin",CC_CALLBACK_1(GameUI::menuBeginCallback,this));
	menuItem_begin->setPosition(centerPoint);
	// ��һ�ز˵�
	menuItem_next = MenuItemFont::create("Next",CC_CALLBACK_1(GameUI::menuNextCallback,this));
	menuItem_next->setPosition(centerPoint);
	// �˳��˵�
	menuItem_quit = MenuItemFont::create("Quit",CC_CALLBACK_1(GameUI::menuQuitCallback,this));
	menuItem_quit->setPosition(centerPoint-Vec2(0,menuItem_quit->getContentSize().height));
	// �����˵�
	menuItem_resume = MenuItemFont::create("Resume",CC_CALLBACK_1(GameUI::menuResumeCallback,this));
	menuItem_resume->setPosition(centerPoint);
	// ���¿�ʼ�˵�
	menuItem_replay = MenuItemFont::create("Replay",CC_CALLBACK_1(GameUI::menuReplayCallback,this));
	menuItem_replay->setPosition(centerPoint);
	//��������
	menuItem_sound = MenuItemFont::create("Sound",CC_CALLBACK_1(GameUI::menuSoundCallback,this));
	menuItem_sound->setPosition(origin+visibleSize-menuItem_sound->getContentSize()/2);

	menu = Menu::create(menuItem_begin,menuItem_next,menuItem_quit,menuItem_resume,menuItem_replay,menuItem_sound,nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	hideMove=MoveBy::create(0,visibleSize);
	showMove=MoveBy::create(0,-visibleSize);

	return true;
}
// �˵��ص�����
void GameUI::menuBeginCallback(Ref* sender)
{
	auto sData = String::create("begin"); 
	NotificationCenter::getInstance()->postNotification("uiEvent",sData);
}
void GameUI::menuNextCallback(Ref* sender)
{
	auto sData = String::create("next"); 
	NotificationCenter::getInstance()->postNotification("uiEvent",sData);
}
void GameUI::menuQuitCallback(Ref* sender)
{
	auto sData = String::create("quit"); 
	NotificationCenter::getInstance()->postNotification("uiEvent",sData);
}
void GameUI::menuResumeCallback(Ref* sender)
{
	auto sData = String::create("resume"); 
	NotificationCenter::getInstance()->postNotification("uiEvent",sData);
}
void GameUI::menuReplayCallback(Ref* sender)
{
	auto sData = String::create("replay"); 
	NotificationCenter::getInstance()->postNotification("uiEvent",sData);
}
void GameUI::menuSoundCallback(Ref* sender)
{
	auto sData = String::create("sound"); 
	NotificationCenter::getInstance()->postNotification("uiEvent",sData);
}
// ��ʾ�˵���
void GameUI::ShowBegin()
{
	HideAll();
	menuItem_begin->setVisible(true);
	menuItem_quit->setVisible(true);
}
void GameUI::ShowNext()
{
	HideAll();
	menuItem_next->setVisible(true);
	menuItem_quit->setVisible(true);
}
void GameUI::ShowResume()
{
	HideAll();
	menuItem_resume->setVisible(true);
	menuItem_quit->setVisible(true);
}
void GameUI::ShowReplay()
{
	HideAll();
	menuItem_replay->setVisible(true);
	menuItem_quit->setVisible(true);
}
void GameUI::HideAll()
{
	menuItem_begin->setVisible(false);
	menuItem_next->setVisible(false);
	menuItem_quit->setVisible(false);
	menuItem_replay->setVisible(false);
	menuItem_resume->setVisible(false);
}

GameUI::~GameUI(void)
{
}
