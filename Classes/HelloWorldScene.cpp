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
	//�ؿ���Ϣ
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


	// ���ɲ˵�
	gameUI=GameUI::create();
	NotificationCenter::getInstance()->addObserver(this,callfuncO_selector(HelloWorld::menuCallback),"uiEvent",NULL);

	this->addChild(gameUI,2);

	levelNow=0;
    // ��ȡ��Ļ����
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
	auto centerPoint = origin+visibleSize/2;
	// ת�̹�����
	rMan=rotatorMan::create();
	this->addChild(rMan);
	rMan->setPosition(centerPoint);

    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    label = LabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    label->setPosition(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height);

    // add the label as a child to this layer
    this->addChild(label, 1);

	//�����¼�
	auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	StateToBegin();
  
    return true;
}
// ״̬��
void HelloWorld::StateToBegin()
{
	stateNow=stateBegin;
	gameUI->ShowBegin();
}
void HelloWorld::StateToPlaying()
{
	auto statePre=stateNow;
	gameUI->HideAll();
	// ��ʼ������Ϸ
	if (statePre==stateBegin)
	{
		ShowLevel();
	}
	// ���Ա���
	else if (statePre==stateFail)
	{
		rMan->createRotator(levelConfig[levelNow]);
	}
	//��һ��
	else if (statePre==stateWin)
	{
		if (levelNow<totalLevelNum-1)
		{
			levelNow++;
			ShowLevel();
		}
	}
	//�ص���Ϸ
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
// ����˵��¼�
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
// ���ڵ�ǰ��
void HelloWorld::ShowLevel()
{
	rMan->createRotator(levelConfig[levelNow]);
}
// �����¼�
bool HelloWorld::onTouchBegan(Touch *touch,Event* event)
{
	CCLOG("Begin");
	return true;
}
void HelloWorld::onTouchMoved(Touch *touch,Event* event)
{
	char temp[100];
	sprintf(temp,"%f,%f,%f",touch->getLocation().x,touch->getLocation().y,touch->getDelta().y);
	label->setString(temp);
	slideSpeed=touch->getDelta().y;
}
void HelloWorld::onTouchEnded(Touch *touch,Event* event)
{
	CCLOG("ENDED");
}
void HelloWorld::Shoot(float shootSpeed)
{

}