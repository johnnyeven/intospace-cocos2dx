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
    _currentDirection = new Vec2(1, 0);
    _targetDirection = new Vec2(1, 0);
    _turnSpeed = 0;
}
PlayerBehavior::~PlayerBehavior()
{
}

void PlayerBehavior::update(double delta)
{
    Behavior::update(delta);
    
    float a = CC_RADIANS_TO_DEGREES(_targetDirection->getAngle(*_currentDirection));
    //log("%f", a);
    if(abs(a) < .5f)
    {
        _currentDirection->x = _targetDirection->x;
        _currentDirection->y = _targetDirection->y;
        return;
    }
    float offset = CC_DEGREES_TO_RADIANS(_turnSpeed * delta);
    if(a < 0)
    {
        //逆时针
        _currentDirection->rotate(Vec2(0, 0), offset);
        //log("逆时针 %f", CC_RADIANS_TO_DEGREES(_currentDirection->getAngle()));
    }
    else if(a > 0)
    {
        //顺时针
        _currentDirection->rotate(Vec2(0, 0), -offset);
        //log("顺时针 %f", CC_RADIANS_TO_DEGREES(_currentDirection->getAngle()));
    }
    _target->setDirection(CC_RADIANS_TO_DEGREES(_currentDirection->getAngle()));
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

void PlayerBehavior::setTargetDirection(float x, float y)
{
    _targetDirection->x = x;
    _targetDirection->y = y;
}

Vec2* PlayerBehavior::getTargetDirection()
{
    return _targetDirection;
}

void PlayerBehavior::installListener()
{
    Behavior::installListener();
}

void PlayerBehavior::uninstallListener()
{
    Behavior::uninstallListener();
}