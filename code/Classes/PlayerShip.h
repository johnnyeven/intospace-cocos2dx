#ifndef __PLAYER_SHIP_H__
#define __PLAYER_SHIP_H__

#pragma once
#include "cocos2d.h"
#include "Ship.h"

USING_NS_CC;
class PlayerBehavior;
class PlayerShip :
	public Ship
{
public:
	static PlayerShip* create();
	virtual bool init();
    virtual void update(double delta);
    
    void setTargetDirection(float x, float y);
private:
	PlayerShip(void);
	~PlayerShip(void);
    
    PlayerBehavior *_behavior;
};

#endif
