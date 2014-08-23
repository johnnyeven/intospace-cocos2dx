#include "PlayerShip.h"


PlayerShip::PlayerShip(void)
{
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
