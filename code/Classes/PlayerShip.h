#ifndef __PLAYER_SHIP_H__
#define __PLAYER_SHIP_H__

#pragma once
#include "cocos2d.h"
#include "Ship.h"
#include "GlobalConfig.h"

USING_NS_CC;
class PlayerBehavior;
class PlayerShip :
	public Ship
{
public:
	static PlayerShip* getInstance();
	virtual bool init();
    virtual void update(double delta);
    
    void setTargetDirection(float x, float y);
	unsigned long long getDistance(BasicObject*);
private:
	PlayerShip(void);
	~PlayerShip(void);
	static PlayerShip* create();

	static PlayerShip* _instance;
    PlayerBehavior *_behavior;
};

#endif
