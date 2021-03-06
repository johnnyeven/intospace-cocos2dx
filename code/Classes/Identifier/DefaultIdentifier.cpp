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
	TTFConfig config("fonts/arial.ttf", 14);
	_info = Label::createWithTTF(config, "0 m", TextHAlignment::CENTER);
	originalSize = getContentSize();
	_info->setPosition(originalSize.width / 2, -originalSize.height / 2);
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

	Vec2 p = getPosition();
	Size s = _info->getContentSize();
	Vec2 p2 = _info->getPosition();
	if(p.y < originalSize.height / 2 + s.height)
	{
		p2.y = originalSize.height + s.height / 2;
	}
	else
	{
		p2.y = -originalSize.height / 2;
	}
	if(p.x < s.width / 2)
	{
		p2.x = s.width / 2;
	}
	else if(p.x > GlobalConfig::scene_width - s.width / 2)
	{
		p2.x = -s.width / 2;
	}
	else
	{
		p2.x = originalSize.width / 2;
	}
	_info->setPosition(p2);

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