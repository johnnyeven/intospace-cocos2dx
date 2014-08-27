#ifndef __PLAYER_RENDER_H__
#define __PLAYER_RENDER_H__

#pragma once
#include "cocos2d.h"
#include "PlayerShip.h"

class PlayerRender:
	public IRender
{
public:
	PlayerRender(void);
	virtual ~PlayerRender(void);
	virtual void update(double delta);
	virtual Node* getTarget();
	virtual void setTarget(Node*);
private:
	PlayerShip* _target;
};

#endif