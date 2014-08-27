#include "PlayerRender.h"


PlayerRender::PlayerRender(void)
{
}


PlayerRender::~PlayerRender(void)
{
}

Node* PlayerRender::getTarget()
{
	return _target;
}

void PlayerRender::setTarget(Node* target)
{
	_target = dynamic_cast<PlayerShip*>(target);
	
}

void PlayerRender::update(double delta)
{
    double d = CC_RADIANS_TO_DEGREES(_target->getDirection());
    if(d < 0)
    {
        d += 360;
    }
    int index = d / 10;
    _target->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attack_drone_3_1_%i.png", index)));
}