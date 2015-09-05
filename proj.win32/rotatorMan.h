#pragma once
#include "cocos2d.h"
#include "myglobal.h"
using namespace cocos2d;

class rotatorMan :
	public Node
{
public:
	virtual bool init();
	rotatorMan(void);
	~rotatorMan(void);
	void createRotator(LevelInfo levelInfo);
	void Rotate();
	void StopRotate();
	CREATE_FUNC(rotatorMan);
private:
	Vector<Sprite*> ballList;
	Action* rot;
	bool bRotating;
};

