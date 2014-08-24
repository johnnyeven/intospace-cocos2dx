#include "MovableObject.h"


MovableObject::MovableObject(void):BasicObject()
{
    _direction = 0.f;
    _velocity = 0.f;
    _acceleration = 0.f;
    _mass = 0;
}


MovableObject::~MovableObject(void)
{
}

void MovableObject::setDirection(double direction)
{
    _direction = direction;
}

double MovableObject::getDirection()
{
    return _direction;
}
