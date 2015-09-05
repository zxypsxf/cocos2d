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
	//关卡信息
	totalLevelNum=3;
	levelConfig[0].level_num=1;
	levelConfig[0].ball_num1=2;
	levelConfig[0].rSpeed=5;
	levelConfig[1].level_num=1;
	levelConfig[1].ball_num1=2;
	levelConfig[1].rSpeed=5;
	levelConfig[2].level_num=1;
	levelConfig[2].ball_num1=2;
	levelConfig[2].rSpeed=5;


	// 生成菜单
	gameUI=GameUI::create();
	NotificationCenter::getInstance()->addObserver(this,callfuncO_selector(HelloWorld::menuCallback),"uiEvent",NULL);

	this->addChild(gameUI,2);

	levelNow=0;
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
	auto centerPoint = origin+visibleSize/2;

	rMan=rotatorMan::create();
	this->addChild(rMan);
	rMan->setPosition(centerPoint);

    
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

	StateToBegin();
  
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
	auto statePre=stateNow;
	gameUI->HideAll();
	// 开始进入游戏
	if (statePre==stateBegin)
	{
		ShowLevel();
	}
	// 重试本关
	else if (statePre==stateFail)
	{
		rMan->createRotator(levelConfig[levelNow]);
	}
	//下一关
	else if (statePre==stateWin)
	{
		if (levelNow<totalLevelNum-1)
		{
			levelNow++;
			ShowLevel();
		}
	}
	//回到游戏
	else if (statePre==statePause)
	{
		rMan->Rotate();
	}
	stateNow=statePlaying;
}
void HelloWorld::StateToPause()
{
	if (stateNow==statePlaying)
	{
		stateNow=statePause;
		rMan->StopRotate();
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
		gameUI->ShowNext();
	}
}
// 处理菜单事件
void HelloWorld::menuCallback(Ref* sender)
{
	auto msg = (String*)sender;
	if (msg->isEqual(String::create("begin")))
	{
		StateToPlaying();
	}
	else if(msg->isEqual(String::create("next")))
	{
		StateToPlaying();
	}
    else if(msg->isEqual(String::create("resume")))
	{
		StateToPlaying();
	}
	else if(msg->isEqual(String::create("replay")))
	{
		StateToPlaying();
	}
	else if(msg->isEqual(String::create("quit")))
	{
		QuitGame();
	}
	else if(msg->isEqual(String::create("sound")))
	{
		StateToPause();
	}
}
void HelloWorld::QuitGame()
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

void HelloWorld::ShowLevel()
{
	rMan->createRotator(levelConfig[levelNow]);
}