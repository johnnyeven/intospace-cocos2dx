#include "BasicObject.h"
#include "PZGuidMaker.h"
#include "GlobalConfig.h"

BasicObject::BasicObject(void)
{
	guid = PZGuidMaker::CreateGuidString().c_str();
    _blockX = 0;
    _blockY = 0;
    _positionX = 0;
    _positionY = 0;
    _isFocused = false;
}


BasicObject::~BasicObject(void)
{
}

const char* BasicObject::getGuid()
{
	return guid;
}

void BasicObject::setWorldPosition(double x, double y)
{
	if(x < 0)
	{
		--_blockX;
		x += GlobalConfig::block_width;
	}
	else if(x > GlobalConfig::block_width)
	{
		++_blockX;
		x -= GlobalConfig::block_width;
	}
	_positionX = x;

	if(y < 0)
	{
		--_blockY;
		y += GlobalConfig::block_height;
	}
	else if(y > GlobalConfig::block_height)
	{
		++_blockY;
		y -= GlobalConfig::block_height;
	}
	_positionY = y;
}

void BasicObject::setFocused(bool value)
{
    _isFocused = value;
}

bool BasicObject::isFocused()
{
    return _isFocused;
}

void BasicObject::update(double delta)
{
    
}