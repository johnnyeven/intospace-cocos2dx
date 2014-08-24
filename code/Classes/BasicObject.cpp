#include "BasicObject.h"
#include "PZGuidMaker.h"

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