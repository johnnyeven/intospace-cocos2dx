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
	return Sprite::initWithSpriteFrame(pSpriteFrame);
}

void DefaultIdentifier::update(float delta)
{
	auto camera = SceneCamera::getInstance();
	Rect view = camera->getScreenView();
	if(_target)
	{
		setPosition(_target->getPosition());
	}
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