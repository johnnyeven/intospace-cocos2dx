#include "PlayerShip.h"
#include "PlayerBehavior.h"
#include "Render/PlayerRender.h"

PlayerShip::PlayerShip(void):Ship()
{
    _behavior = new PlayerBehavior();
	setMainRender(new PlayerRender());
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
		_behavior->setTurnSpeed(240.f);
		_behavior->setTarget(this);

		setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("attack_drone_3_1_0.png"));
		return true;
	}
	return false;
}

void PlayerShip::update(double delta)
{
	Ship::update(delta);

    if(_behavior)
    {
        _behavior->update(delta);
    }
}

void PlayerShip::setTargetDirection(float x, float y)
{
    _behavior->setTargetDirection(x, y);
}
