#ifndef _IDENTIFIER_H_
#define _IDENTIFIER_H_

#pragma once
#include "cocos2d.h"
#include "BasicObject.h"

USING_NS_CC;

class IIdentifier
{
public:
	IIdentifier(void) {};
	virtual ~IIdentifier(void) {};
	virtual void update(double delta) = 0;
	virtual void setTarget(BasicObject*) = 0;
	virtual BasicObject* getTarget() = 0;
	virtual void addToTarget(BasicObject*) = 0;
};

#endif