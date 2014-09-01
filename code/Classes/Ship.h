#ifndef _SHIP_H_
#define _SHIP_H_

#pragma once
#include "cocos2d.h"
#include "MovableObject.h"
#include "define.h"

USING_NS_CC;
class Ship :
	public MovableObject
{
public:
	ShipAction getAction() { return _action; };
	void setAction(ShipAction);
protected:
	Ship(void);
	~Ship(void);
private:
	ShipAction _action;
};

#endif