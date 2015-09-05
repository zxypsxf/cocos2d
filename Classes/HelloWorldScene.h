#pragma once
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameUI.h"
#include "myglobal.h"
#include "rotatorMan.h"


class HelloWorld : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void menuCloseCallback(Ref* sender);
	// 菜单回调
	void menuCallback(Ref* sender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	//状态机
	void StateToBegin();
	void StateToPlaying();
	void StateToPause();
	void StateToFail();
	void StateToWin();

	// 触摸事件
	bool onTouchBegan(Touch *touch,Event* event);
	void onTouchMoved(Touch *touch,Event* event);
	void onTouchEnded(Touch *touch,Event* event);

	void ShowLevel();
	void Shoot(float shootSpeed);
	void QuitGame();

private:
	// 菜单
	GameUI* gameUI;
	// 当前状态
	int stateNow;
	// 当前关卡数
	int levelNow;
	// 转盘
	rotatorMan* rMan;
	int totalLevelNum;
	LevelInfo levelConfig[20];
	LabelTTF* label;
	// 滑动速度
	float slideSpeed;
};

#endif // __HELLOWORLD_SCENE_H__
