#pragma once
#include "cocos2d.h"

USING_NS_CC;

class IRender
{
public:
	IRender(void){};
	virtual ~IRender(void){};
	virtual void update(double delta) = 0;
	virtual Node* getTarget() = 0;
	virtual void setTarget(Node*) = 0;
};

