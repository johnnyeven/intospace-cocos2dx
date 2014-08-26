#include "Ship.h"


Ship::Ship(void):MovableObject()
{
}


Ship::~Ship(void)
{
}

void Ship::setAction(ShipAction a)
{
	_action = a;
}