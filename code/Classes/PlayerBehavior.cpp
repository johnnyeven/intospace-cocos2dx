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
    
	//旋转
    float a = CC_RADIANS_TO_DEGREES(_targetDirection->getAngle(*_currentDirection));
	float angle;

    //log("%f", a);
    if(abs(a) < 5.f)
    {
        _currentDirection->x = _targetDirection->x;
        _currentDirection->y = _targetDirection->y;
		angle = _currentDirection->getAngle();
    }
	else
	{
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
		angle = _currentDirection->getAngle();
		_target->setDirection(_currentDirection->getAngle());
	}
	
	if(_target->getAction() == ShipAction::MOVE)
	{
		//计算速度
		calculateVelocity(delta);
	
		//计算位置
		calculatePosition(angle, delta);
		//log("velocity=%f", _target->getVelocity());
	}
}

void PlayerBehavior::calculateVelocity(double delta)
{
	float a = _target->getAcceleration();
	double v = _target->getVelocity();
	double max = _target->getMaxVelocity();

	if(a != 0)
	{
		_target->setVelocity(v + a * delta);
	}
	
	v = _target->getVelocity();
	if(v == max)
	{
		_target->setAcceleration(0.f);
	}
	else if(v == 0)
	{
		_target->setAcceleration(0.f);
		_target->setAction(ShipAction::STOP);
	}
}

void PlayerBehavior::calculatePosition(float angle, double delta)
{
	double speed = _target->getVelocity() * delta;
	if(speed > 0)
	{
		double speedX = speed * cosf(angle);
		double speedY = speed * sinf(angle);

		_target->setWorldPosition(
									_target->getWorldPositionX() + speedX,
									_target->getWorldPositionY() + speedY);
	}
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