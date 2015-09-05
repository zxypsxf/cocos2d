#pragma once
#include "cocos2d.h"
#include "myglobal.h"
using namespace cocos2d;

class rotatorMan :
	public Sprite
{
public:
	virtual bool init();
	rotatorMan(void);
	~rotatorMan(void);
	void createRotator(LevelInfo levelInfo);
	CREATE_FUNC(rotatorMan);
};

