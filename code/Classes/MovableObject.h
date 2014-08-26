#pragma once
#include "BasicObject.h"
class MovableObject :
	public BasicObject
{
public:
	void setDirection(double);
	double getDirection();
	void setMaxVelocity(double);
	double getMaxVelocity();
	void setVelocity(double);
	double getVelocity();
	void setAcceleration(float);
	float getAcceleration();
	void setMass(int);
	int getMass();
protected:
	MovableObject(void);
	~MovableObject(void);
private:
	double _direction;			//���򻡶���
	double _maxVelocity;		//����ٶ�
	double _velocity;			//�ٶ�
	float _acceleration;		//���ٶ�
	int _mass;					//����
};

