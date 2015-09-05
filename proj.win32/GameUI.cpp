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
	auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
	auto centerPoint = origin+visibleSize/2;
	// 开始菜单 
	menuItem_begin = MenuItemFont::create("Begin",CC_CALLBACK_1(GameUI::menuBeginCallback,this));
	menuItem_begin->setPosition(centerPoint);
	// 下一关菜单
	menuItem_next = MenuItemFont::create("Next",CC_CALLBACK_1(GameUI::menuNextCallback,this));
	menuItem_next->setPosition(centerPoint);
	// 退出菜单
	menuItem_quit = MenuItemFont::create("Quit",CC_CALLBACK_1(GameUI::menuQuitCallback,this));
	menuItem_quit->setPosition(centerPoint-Vec2(0,menuItem_quit->getContentSize().height));
	// 继续菜单
	menuItem_resume = MenuItemFont::create("Resume",CC_CALLBACK_1(GameUI::menuResumeCallback,this));
	menuItem_resume->setPosition(centerPoint);
	// 重新开始菜单
	menuItem_replay = MenuItemFont::create("Replay",CC_CALLBACK_1(GameUI::menuReplayCallback,this));
	menuItem_replay->setPosition(centerPoint);
	//声音开关
	menuItem_sound = MenuItemFont::create("Sound",CC_CALLBACK_1(GameUI::menuSoundCallback,this));
	menuItem_sound->setPosition(origin+visibleSize-menuItem_sound->getContentSize()/2);

	menu = Menu::create(menuItem_begin,menuItem_quit,menuItem_resume,menuItem_replay,menuItem_sound,nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	HideAll();
	ShowBegin();

	return true;
}
void GameUI::menuBeginCallback(Ref* sender)
{
	menuItem_quit->setVisible(false);
}
void GameUI::menuNextCallback(Ref* sender)
{

}
void GameUI::menuQuitCallback(Ref* sender)
{

}
void GameUI::menuResumeCallback(Ref* sender)
{

}
void GameUI::menuReplayCallback(Ref* sender)
{

}
void GameUI::menuSoundCallback(Ref* sender)
{

}

void GameUI::ShowBegin()
{
	menuItem_begin->setVisible(true);
	menuItem_quit->setVisible(true);
}
void GameUI::ShowNext()
{
	menuItem_next->setVisible(true);
	menuItem_quit->setVisible(true);
}
void GameUI::ShowResume()
{
	menuItem_resume->setVisible(true);
	menuItem_quit->setVisible(true);
}
void GameUI::ShowReplay()
{
	menuItem_replay->setVisible(true);
	menuItem_quit->setVisible(true);
}
void GameUI::HideAll()
{
	menuItem_begin->setVisible(false);
	menuItem_next->setVisible(false);
	menuItem_resume->setVisible(false);
	menuItem_replay->setVisible(false);
	menuItem_quit->setVisible(false);
}

GameUI::~GameUI(void)
{
}
