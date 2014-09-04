#ifndef _DEFAULT_IDENTIFIER_H_
#define _DEFAULT_IDENTIFIER_H_

#pragma once
#include "cocos2d.h"
#include "BasicObject.h"
#include "Camera.h"
#include "GlobalConfig.h"
#include "PlayerShip.h"
#include "define.h"
#include "Utilities/SpaceUtils.h"

USING_NS_CC;

class DefaultIdentifier :
	public Sprite
{
public:
	DefaultIdentifier(IdentifierType);
	virtual ~DefaultIdentifier(void);
	static DefaultIdentifier* create(IdentifierType);
	virtual bool initWithSpriteFrame(SpriteFrame *pSpriteFrame);
	virtual void update(float delta);

	virtual void setPosition(const Vec2& pos) override;
	virtual void setTarget(BasicObject*);
	virtual BasicObject* getTarget();
	void setType(IdentifierType);
	IdentifierType getType();
private:
	Node* _container;
	BasicObject* _target;
	IdentifierType _type;
	Label* _info;
	Size originalSize;
};

#endif