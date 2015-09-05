#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;

enum
{
	stateBegin,
	statePlaying,
	statePause,
	stateFail,
	stateWin,
};
Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	// 生成菜单
	gameUI=GameUI::create();
	NotificationCenter::getInstance()->addObserver(this,callfuncO_selector(HelloWorld::menuCallback),"uiEvent",NULL);

	this->addChild(gameUI,2);

	levelNow=0;
	StateToBegin();
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
	auto centerPoint = origin+visibleSize/2;

	rMan=rotatorMan::create();
	this->addChild(rMan);

	LevelInfo levelInfo1;
	levelInfo1.ball_num1=5;
	rMan->createRotator(levelInfo1);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    
    closeItem->setPosition(origin  + Vec2(closeItem->getContentSize() / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    label->setPosition(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height);

    // add the label as a child to this layer
    this->addChild(label, 1);
  
    return true;
}
// 状态机
void HelloWorld::StateToBegin()
{
	stateNow=stateBegin;
	gameUI->ShowBegin();
}
void HelloWorld::StateToPlaying()
{
	stateNow=statePlaying;
	gameUI->HideAll();
}
void HelloWorld::StateToPause()
{
	if (stateNow==statePlaying)
	{
		stateNow=statePause;
		gameUI->ShowResume();
	}
}
void HelloWorld::StateToFail()
{
	if (stateNow==statePlaying)
	{
		stateNow=stateFail;
		gameUI->ShowReplay();
	}
}
void HelloWorld::StateToWin()
{
	if (stateNow==statePlaying)
	{
		stateNow=stateWin;
	
	}
}
// 处理菜单事件
void HelloWorld::menuCallback(Ref* sender)
{
	auto msg = (String*)sender;
	if (msg->isEqual(String::create("begin")))
	{
		
		LevelInfo levelInfo1;
		levelInfo1.level_num=1;
		log("testMsg-%d: %s",levelInfo1.level_num,msg->getCString()); 
	}
	else if(msg->isEqual(String::create("next")))
	{
		log("testMsg: %s",msg->getCString()); 
	}
    else if(msg->isEqual(String::create("resume")))
	{
		log("testMsg: %s",msg->getCString()); 
	}
	else if(msg->isEqual(String::create("replay")))
	{
		log("testMsg: %s",msg->getCString()); 
	}
	else if(msg->isEqual(String::create("quit")))
	{
		log("testMsg: %s",msg->getCString()); 
	}
	else if(msg->isEqual(String::create("sound")))
	{
		log("testMsg: %s",msg->getCString()); 
	}
}
void HelloWorld::menuCloseCallback(Ref* sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
