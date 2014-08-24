//
//  Behavior.cpp
//  IntoSpace
//
//  Created by 李翌文 on 14-8-24.
//
//

#include "Behavior.h"

Behavior::Behavior()
{
}
Behavior::~Behavior()
{
}

void Behavior::update(double delta)
{
}

void Behavior::installListener()
{
}

void Behavior::uninstallListener()
{
}

void Behavior::setTarget(BasicObject *obj)
{
    if(obj)
    {
        _target = obj;
    }
}

BasicObject* Behavior::getTarget()
{
    return _target;
}