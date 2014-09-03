#include "PlayerShip.h"
#include "PlayerBehavior.h"
#include "Render/PlayerRender.h"

PlayerShip* PlayerShip::_instance = nullptr;

PlayerShip::PlayerShip(void):Ship()
{
    _behavior = new PlayerBehavior();
	setMainRender(new PlayerRender());
	zIndex = 1.f;
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

PlayerShip* PlayerShip::getInstance()
{
	if(!_instance)
	{
		_instance = create();
	}
	return _instance;
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

unsigned long long PlayerShip::getDistance(BasicObject* target)
{
	Vec2 targetBlock = target->getBlock();
	Vec2 playerBlock = getBlock();
	double _x = target->getWorldPositionX() + (targetBlock.x - playerBlock.x) * GlobalConfig::block_width - getWorldPositionX();
	double _y = target->getWorldPositionY() + (targetBlock.y - playerBlock.y) * GlobalConfig::block_height - getWorldPositionY();
	return unsigned long long(sqrt(_x * _x + _y * _y));
}