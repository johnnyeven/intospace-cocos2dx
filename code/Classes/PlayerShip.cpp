#include "PlayerShip.h"
#include "PlayerBehavior.h"

PlayerShip::PlayerShip(void):Ship()
{
    PlayerBehavior *b = new PlayerBehavior();
    b->setTurnSpeed(120.f);
    b->setTarget(this);
    _behavior = b;
}


PlayerShip::~PlayerShip(void)
{
}

PlayerShip* PlayerShip::create()
{
    PlayerShip *s = new (std::nothrow) PlayerShip();
    if (s && s->init())
    {
        s->autorelease();
        return s;
    }
    CC_SAFE_DELETE(s);
    return nullptr;
}

bool PlayerShip::init()
{
	if(Ship::init())
	{
		setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("attack_drone_3_1_0.png"));
		return true;
	}
	return false;
}

void PlayerShip::update(double delta)
{
    if(_behavior)
    {
        _behavior->update(delta);
    }
    double d = getDirection();
    if(d < 0)
    {
        d += 360;
    }
    int index = d / 10;
    setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attack_drone_3_1_%i.png", index)));
}

void PlayerShip::setTargetDirection(float direction)
{
    _behavior->setTargetDegrees(direction);
}
