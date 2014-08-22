#pragma once
#include "cocos2d.h"
#include "Ship.h"

USING_NS_CC;
class PlayerShip :
	public Ship
{
public:
	static PlayerShip* create();
	virtual bool init();
private:
	PlayerShip(void);
	~PlayerShip(void);
};

