#pragma once
#include "BasicObject.h"
class MovableObject :
	public BasicObject
{
public:
	void setDirection(double);
	double getDirection();
	void setVelocity(float);
	float getVelocity();
	void setAcceleration(float);
	float getAcceleration();
	void setMass(int);
	int getMass();
protected:
	MovableObject(void);
	~MovableObject(void);
private:
	double _direction;			//方向弧度数
	float _velocity;			//速度
	float _acceleration;		//加速度
	int _mass;					//质量
};

