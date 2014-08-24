//
//  PlayerBehavior.cpp
//  IntoSpace
//
//  Created by 李翌文 on 14-8-24.
//
//

#include "PlayerBehavior.h"

PlayerBehavior::PlayerBehavior():Behavior()
{
    _targetDegrees = 0;
    _turnSpeed = 0;
}
PlayerBehavior::~PlayerBehavior()
{
}

void PlayerBehavior::update(double delta)
{
    Behavior::update(delta);
    double _d = _target->getDirection();
    double offset = fabs(_d - _targetDegrees);
    if (offset < 1.f)
    {
        _target->setDirection(_targetDegrees);
        return;
    }
    if(_targetDegrees > _d)
    {
        //逆时针转
        _d += _turnSpeed * delta;
    }
    else if(_targetDegrees < _d)
    {
        _d -= _turnSpeed * delta;
    }
    
    _target->setDirection(_d);
}

void PlayerBehavior::setTurnSpeed(float speed)
{
    _turnSpeed = speed;
}

float PlayerBehavior::getTurnSpeed()
{
    return _turnSpeed;
}

void PlayerBehavior::setTarget(PlayerShip *obj)
{
    if(obj)
    {
        _target = obj;
    }
}

PlayerShip* PlayerBehavior::getTarget()
{
    return _target;
}

void PlayerBehavior::setTargetDegrees(float degrees)
{
    _targetDegrees = degrees;
}

float PlayerBehavior::getTargetDegrees()
{
    return _targetDegrees;
}

void PlayerBehavior::installListener()
{
    Behavior::installListener();
}

void PlayerBehavior::uninstallListener()
{
    Behavior::uninstallListener();
}