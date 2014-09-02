#ifndef _DEFAULT_IDENTIFIER_H_
#define _DEFAULT_IDENTIFIER_H_

#pragma once
#include "IIdentifier.h"
#include "cocos2d.h"
#include "BasicObject.h"
#include "Camera.h"
#include "define.h"

USING_NS_CC;

class DefaultIdentifier :
	public IIdentifier
{
public:
	DefaultIdentifier(IdentifierType);
	virtual ~DefaultIdentifier(void);
	virtual void update(double delta);

	void setTarget(BasicObject*);
	BasicObject* getTarget();
	void addToTarget(BasicObject*);
	void setType(IdentifierType);
	IdentifierType getType();
private:
	BasicObject* _target;
	IdentifierType _type;
	Sprite* _icon;
};

#endif