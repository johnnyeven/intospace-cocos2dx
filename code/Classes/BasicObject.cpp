#include "BasicObject.h"
#include "PZGuidMaker.h"

BasicObject::BasicObject(void)
{
	guid = PZGuidMaker::newGUID();
}


BasicObject::~BasicObject(void)
{
}

const char* BasicObject::getGuid()
{
	return guid;
}
