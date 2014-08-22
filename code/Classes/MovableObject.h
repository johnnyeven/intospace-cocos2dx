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
	double _direction;			//���򻡶���
	float _velocity;			//�ٶ�
	float _acceleration;		//���ٶ�
	int _mass;					//����
};

