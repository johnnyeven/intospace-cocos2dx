#pragma once
#include "IRender.h"
#include "SpaceScene.h"
#include "GlobalConfig.h"

#define STAR_LEVEL 5
#define STAR_COUNT 100

class SpaceStarRender :
	public IRender
{
public:
	SpaceStarRender(void);
	virtual ~SpaceStarRender(void);
	virtual void update(double delta);
	virtual Node* getTarget();
	virtual void setTarget(Node*);
private:
	SpaceScene* _target;
	Sprite* _container;
	SpriteFrame* _frame;
	Vector<Sprite*> _displayContainer;
	std::vector<int> _deepContainer;
};

