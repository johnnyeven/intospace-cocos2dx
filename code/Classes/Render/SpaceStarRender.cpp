#include "SpaceStarRender.h"

SpaceStarRender::SpaceStarRender(void)
{
	_frame = SpriteFrame::create("images/maps/stars.png", Rect(0, 0, 1, 1));
	_container = Sprite::create();
	_displayContainer = Vector<Sprite*>();
	_deepContainer = std::vector<int>();
	srand(time(0));
}

SpaceStarRender::~SpaceStarRender(void)
{
}

Node* SpaceStarRender::getTarget()
{
	return _target;
}

void SpaceStarRender::setTarget(Node* target)
{
	_target = dynamic_cast<SpaceScene*>(target);
	_container->setAnchorPoint(Vec2(0.f, 0.f));
	_container->setPosition(0.f, 0.f);
	_target->addChild(_container);

	for(int i = 0; i < STAR_LEVEL; ++i)
	{
		auto layer = Sprite::create();
		layer->setAnchorPoint(Vec2(0.f, 0.f));
		layer->setPosition(0.f, 0.f);
		layer->setTag(i);
		_container->addChild(layer);
	}
}

void SpaceStarRender::update(double delta)
{
	if(_displayContainer.size() < STAR_COUNT)
	{
		int index = rand() % 5;
		auto _layer = _container->getChildByTag(index);
		//auto _star = Sprite::createWithSpriteFrame(_frame);
		auto _star = Sprite::create("images/maps/stars.png");
		int _x = rand() % GlobalConfig::scene_width;
		int _y = rand() % GlobalConfig::scene_height;
		_star->setPosition(_x, _y);
		float opacity = 255 * (1.f / (index + 1));
		_star->setOpacity(0);
		_layer->addChild(_star);
		_displayContainer.pushBack(_star);
		_deepContainer.push_back(index);

		_star->runAction(FadeTo::create(.5f, opacity));
	}

	int size = _displayContainer.size();
	for(int i = 0; i < size; ++i)
	{
		auto _layer = _container->getChildByTag(_deepContainer[i]);
		auto _child = _displayContainer.at(i);
		Vec2 current = _child->getPosition();
		Vec2 point = _child->getParent()->convertToWorldSpaceAR(current);
		if(point.x > GlobalConfig::scene_width || point.x < 0 || point.y > GlobalConfig::scene_height || point.y < 0)
		{
			_layer->removeChild(_child);
            
            Vector<Sprite*>::iterator it = _displayContainer.begin() + i;
            _displayContainer.erase(it);
            
            std::vector<int>::iterator it1 = _deepContainer.begin() + i;
            _deepContainer.erase(it1);
            
            --size;
		}
		else
		{
			float percent = 1.f / (_deepContainer[i] + 1);
			auto p = _target->getPlayer();
			double speed = p->getVelocity() * delta;
			double speedX = speed * cosf(p->getDirection());
			double speedY = speed * sinf(p->getDirection());
			float _x = current.x + (.5f - speedX) * percent;
			float _y = current.y - speedY * percent;
			_child->setPosition(_x, _y);
		}
	}
}