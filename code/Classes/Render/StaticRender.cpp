//
//  StaticRender.cpp
//  IntoSpace
//
//  Created by 李翌文 on 14-8-27.
//
//

#include "StaticRender.h"

StaticRender::StaticRender(void)
{
}


StaticRender::~StaticRender(void)
{
}

Node* StaticRender::getTarget()
{
	return _target;
}

void StaticRender::setTarget(Node* target)
{
	_target = dynamic_cast<BasicObject*>(target);
	
}

void StaticRender::update(double delta)
{
	auto camera = SceneCamera::getInstance();
    Vec2 p = camera->getScreenPosition(
                                                          _target->getWorldPositionX(),
                                                          _target->getWorldPositionY(),
                                                          _target->getBlock().x,
                                                          _target->getBlock().y);
    
	if(_target->zIndex > 0)
	{
		//修正视距差效果
		p.x = p.x * _target->zIndex + (GlobalConfig::scene_width >> 1);
		p.y = p.y * _target->zIndex + (GlobalConfig::scene_height >> 1);
	}
	log("x=%f, y=%f", p.x, p.y);
    _target->setPosition(p);
}