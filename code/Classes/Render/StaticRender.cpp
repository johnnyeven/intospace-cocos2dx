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
    Vec2 p = SceneCamera::getInstance()->getWorldPosition(
                                                          _target->getWorldPositionX(),
                                                          _target->getWorldPositionY(),
                                                          _target->getBlock().x,
                                                          _target->getBlock().y);
    _target->setPosition(p);
    log("x=%f, y=%f", p.x, p.y);
}