#include "rotatorMan.h"


rotatorMan::rotatorMan(void)
{
	
}
bool rotatorMan::init()
{
	if (!Sprite::create())
	{
		return false;
	}
}
void rotatorMan::createRotator(LevelInfo levelInfo)
{
	for (int i = 0; i < levelInfo.ball_num1; i++)
	{
		auto ball=Sprite::create("ball.png");
		ball->setPosition(Vec2(0,i*30));
		this->addChild(ball);
	}
}
rotatorMan::~rotatorMan(void)
{
}
