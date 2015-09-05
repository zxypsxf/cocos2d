#include "rotatorMan.h"


rotatorMan::rotatorMan(void)
{
	
}
bool rotatorMan::init()
{
	if (!Node::create())
	{
		return false;
	}
	bRotating=false;
}
void rotatorMan::createRotator(LevelInfo levelInfo)
{
	this->removeAllChildrenWithCleanup(true);
	for (int i = 0; i < levelInfo.ball_num1; i++)
	{
		auto ball=Sprite::create("ball.png");
		ball->setPosition(Vec2(0,i*30));
		ballList.pushBack(ball);
		this->addChild(ball);
	}
	if (levelInfo.rSpeed>0)
	{
		rot=RepeatForever::create(RotateBy::create(5/levelInfo.rSpeed,360));
		this->runAction(rot);
		bRotating=true;
	}
}
void rotatorMan::Rotate()
{
	if (!bRotating)
	{
		this->resume();
	}
	bRotating=true;
}
void rotatorMan::StopRotate()
{
	if (bRotating)
	{
		this->pause();
	}
	bRotating=false;
}

rotatorMan::~rotatorMan(void)
{
}
