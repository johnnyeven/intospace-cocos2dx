#include "DefaultIdentifier.h"

DefaultIdentifier::DefaultIdentifier(IdentifierType type)
{
	_type = type;
	_icon = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("identifier_%i.png", _type)));
}

DefaultIdentifier::~DefaultIdentifier(void)
{
}

void DefaultIdentifier::update(double delta)
{
	auto camera = SceneCamera::getInstance();
	Rect view = camera->getScreenView();
	if(_target && view.containsPoint(_target->getPosition()))
	{
		//addToTarget(_target);
	}
}

void DefaultIdentifier::setTarget(BasicObject* obj)
{
	if(_target != obj)
	{
		_target = obj;
	}
}

void DefaultIdentifier::addToTarget(BasicObject* obj)
{
	if(obj)
	{
		if(_icon->getParent())
		{
			_icon->removeFromParent();
		}
		Size s = _target->getTexture()->getContentSize();
		log("width=%f, height=%f", s.width, s.height);
		_target->addChild(_icon);
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