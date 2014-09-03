#include "DefaultIdentifier.h"

DefaultIdentifier::DefaultIdentifier(IdentifierType type)
{
	_type = type;
}

DefaultIdentifier::~DefaultIdentifier(void)
{
}

DefaultIdentifier* DefaultIdentifier::create(IdentifierType type)
{
	auto instance = new DefaultIdentifier(type);
	if(instance && instance->initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("identifier_%i.png", type))))
	{
		return instance;
	}
	CC_SAFE_DELETE(instance);
	return nullptr;
}

bool DefaultIdentifier::initWithSpriteFrame(SpriteFrame *pSpriteFrame)
{
	bool result = Sprite::initWithSpriteFrame(pSpriteFrame);
//	TTFConfig config("fonts/Marker Felt.ttf", 14);
//	_info = Label::createWithTTF(config, "0 m", TextHAlignment::CENTER);
	_info = Label::create("0 m", "Arial", 14);
	Size s = getContentSize();
	_info->setPosition(s.width / 2, -s.height / 2);
	addChild(_info);
	return result;
}

void DefaultIdentifier::update(float delta)
{
	auto camera = SceneCamera::getInstance();
	Rect view = camera->getScreenView();
	if(_target)
	{
		setPosition(_target->getPosition());
	}
	Vec2 b = _target->getBlock();
	unsigned long long d = PlayerShip::getInstance()->getDistance(_target);
	_info->setString(SpaceUtils::humanReadableDistance(d));
}

void DefaultIdentifier::setPosition(const Vec2& pos)
{
	Sprite::setPosition(Vec2(
		std::max(0.f, std::min((float)GlobalConfig::scene_width, pos.x)),
		std::max(0.f, std::min((float)GlobalConfig::scene_height, pos.y))));
}

void DefaultIdentifier::setTarget(BasicObject* obj)
{
	if(_target != obj)
	{
		_target = obj;
	}
}

BasicObject* DefaultIdentifier::getTarget()
{
	return _target;
}

void DefaultIdentifier::setType(IdentifierType type)
{
	_type = type;
}

IdentifierType DefaultIdentifier::getType()
{
	return _type;
}