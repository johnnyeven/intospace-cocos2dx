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

void MovableObject::setMaxVelocity(double v)
{
	_maxVelocity = v;
}

double MovableObject::getMaxVelocity()
{
	return _maxVelocity;
}

void MovableObject::setVelocity(double v)
{
	_velocity = v > _maxVelocity ? _maxVelocity : v;
}

double MovableObject::getVelocity()
{
	return _velocity;
}

void MovableObject::setAcceleration(float v)
{
	_acceleration = v;
}

float MovableObject::getAcceleration()
{
	return _acceleration;
}

void MovableObject::setMass(int v)
{
	_mass = v;
}

int MovableObject::getMass()
{
	return _mass;
}